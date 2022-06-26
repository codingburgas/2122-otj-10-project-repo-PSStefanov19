#include "UserManager.h"


void pm::dal::UserManager::createUser(const std::string username,
	const std::string passwordHash,
	const std::string firstName,
	const std::string lastName,
	const std::string email,
	const time_t dateOfCreation,
	const bool isAdmin)
{
	db.open("../data/users.csv", std::ios::out | std::ios::app);

	if (!db.is_open()) 
	{
		throw "Could not open file";
		return;
	}
	db << lastId << ", "<< username << ", " << md5(passwordHash) << ", " << firstName << ", " << lastName << ", " << email << ", " << dateOfCreation << "," <<isAdmin << "\n";
	db.flush();

	lastId++;
	db.close();
}

std::vector<pm::types::User> pm::dal::UserManager::getAllUsers()
{
	io::CSVReader<8> in("../data/users.csv");
	in.read_header(
		io::ignore_extra_column,
		"Id",
		"Username",
		"Password",
		"FirstName",
		"LastName",
		"Email",
		"DateOfCreation",
		"isAdmin"
	);
	
	std::vector <pm::types::User> allUsers;
	int id, isAdmin;
	std::string username, password, firstName, lastName, email, dateOfCreation;
	
	std::stringstream s;

	while (in.read_row(id,
		username,
		password,
		firstName,
		lastName,
		email,
		dateOfCreation,
		isAdmin)) 
	{
		tm doc;

		s.str("");
		s.clear();

		s << dateOfCreation;

		s >> std::get_time(&doc, "%F");

		allUsers.push_back(pm::types::User(id,
			username,
			password,
			firstName,
			lastName,
			email,
			mktime(&doc),
			bool(isAdmin)
		));
	}

	return allUsers;
}

void pm::dal::UserManager::createDB()
{
	db.open("../data/users.csv", std::ios::out);

	if (!db.is_open()) 
	{
		return;
	}

	time_t t = time(0);
	tm* time = localtime(&t);
	db << "Id,Username,Password,FirstName,LastName,Email,DateOfCreation,isAdmin\n";
	db << lastId <<",admin," << md5("adminpass") << ",NULL,NULL,NULL," << std::put_time(time, "%F") << ",1\n";
	lastId++;
	db.flush();
	db.close();
}

void pm::dal::UserManager::setId(int newId)
{
	this->lastId = newId;
}

void pm::dal::UserManager::syncId()
{
	std::string s;
	int i = -1;
	db.open("../data/users.csv", std::ios::in);
	if (!db.is_open()) 
	{
		return;
	}

	while (getline(db, s)) 
	{
		i++;
	}
	setId(i);

	db.close();
}
