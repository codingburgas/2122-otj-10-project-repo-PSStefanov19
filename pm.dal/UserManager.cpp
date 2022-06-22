#include "UserManager.h"

pm::dal::UserManager& pm::dal::UserManager::getInstance()
{
    static pm::dal::UserManager u;
    return u;
}

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
		return;
	}
	db << lastId << ", "<< username << ", " << md5(passwordHash) << ", " << firstName << ", " << lastName << ", " << email << ", " << dateOfCreation << "," <<isAdmin << "\n";
	db.flush();

	lastId++;
	db.close();
}

void pm::dal::UserManager::displayUsers() 
{
	if (!std::filesystem::exists("../data/users.csv")) 
	{
		return;
	}

	io::CSVReader<8> in("../data/users.csv");

	in.read_header(io::ignore_missing_column, "Id", "Username", "Password", "FirstName", "LastName", "Email", "DateOfCreation", "isAdmin");
	std::string username, password, firstName, lastName, email, dateOfCreation;
	short int isAdmin;
	while (in.read_row(lastId,username, password, firstName, lastName, email, dateOfCreation, isAdmin)) 
	{
		std::cout << lastId << " " << username << " " <<email << " " << bool(isAdmin) << std::endl;
	}
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
