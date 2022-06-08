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
	const time_t dateOfCreation)
{
	db.open("../data/db.csv", std::ios::out | std::ios::app);

	if (!db.is_open()) 
	{
		return;
	}

	db << username << ", " << md5(passwordHash) << ", " << firstName << ", " << lastName << ", " << email << ", " << dateOfCreation << "\n";
	db.flush();

	db.close();
}

void pm::dal::UserManager::displayUsers() 
{
	for (pm::types::User user : users) 
	{
		std::cout << "Id: " << user.getId() << "\n";
		std::cout << "UserName: " << user.getUsername() << "\n";
		std::cout << "Pass: " << user.getPassword() << "\n";
		std::cout << "\n";
		std::cout.flush();
	}
}

void pm::dal::UserManager::createDB()
{
	std::filesystem::create_directories("../data");
	db.open("../data/db.csv", std::ios::out);

	if (!db.is_open()) 
	{
		return;
	}

	time_t t = time(0);
	tm* time = localtime(&t);
	db << "Username,Password,FirstName,LastName,Email,DateOfCreation\n";
	db << "admin," << md5("adminpass") << ",NULL,NULL,NULL," << std::put_time(time, "%F") << "\n";
	db.flush();
	db.close();
}

void pm::dal::UserManager::parseUsers()
{
	db.open("../data/db.csv", std::ios::in);

	if (!db.is_open()) 
	{
		return;
	}


	std::string line;
	
	io::CSVReader<6> reader("../data/db.csv");

	reader.read_header(io::ignore_extra_column, "Username", "Password", "FirstName", "LastName", "Email", "DateOfCreation");

	std::string username;
	std::string password;
	std::string firstName;
	std::string lastName;
	std::string email;
	std::time_t dOC;
	while (reader.read_row(username, password, firstName, lastName, email, dOC)) 
	{
		users.push_back(pm::types::User(users.size() + 1, username, password, firstName, lastName, email, dOC));
	}
}
