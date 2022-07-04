#include "UserManager.h"

/**
 * . Function to create user in database
 * 
 * \param username Username of user
 * \param passwordHash Hashed password of user
 * \param firstName First name of user
 * \param lastName Last name of user
 * \param email Email of user
 * \param dateOfCreation Date of creation of user
 * \param isAdmin Privlidges of user
 */
void pm::dal::UserManager::createUser(const std::string username,
    const std::string passwordHash,
    const std::string firstName,
    const std::string lastName,
    const std::string email,
    const time_t dateOfCreation,
    const bool isAdmin)
{
    // Get last id
    int lastId = getLastId();

    // Open database to append to
    db.open("../data/users.csv", std::ios::out | std::ios::app);

    // Check if it's open
    if (!db.is_open())
    {
        return;
    }

    // Write user to database and flush
    db << lastId << ", " << username << ", " << passwordHash << ", " << firstName << ", " << lastName << ", " << email << ", " << dateOfCreation << "," << isAdmin << "\n";
    db.flush();
    db.close();
}

/**
 * . Function to delete user by Id
 * 
 * \param id Id of user to be deleted
 */
void pm::dal::UserManager::deleteUserById(int id)
{
    // String that will contain all of the file without the user
    std::string fileContents;

    // Open database
    db.open("../data/users.csv", std::ios::in);
    
    // Check if it's open
    if (!db.is_open())
    {
        return;
    }

    // Line counter
    int counter = 0;

    // String that will hold each line of file
    std::string line;
    
    while (std::getline(db, line))
    {
        // If the line is not the user add it to the file contents
        if (id != line[0] - '0' && counter != 0)
        {
            fileContents += line;
            fileContents += '\n';
        }
        counter++;
    }

    db.close();

    // Open database and write all file contents
    db.open("../data/users.csv", std::ios::out | std::ios::trunc);
    db << fileContents;
    db.close();
}

/**
 * . Function to return all users in database
 * 
 * \return Vector of all users
 */
std::vector<pm::types::User> pm::dal::UserManager::getAllUsers()
{
    // Initialize csv reader
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

    // Vector that will hold all the users
    std::vector <pm::types::User> allUsers;

    // Variables that will hold the value of each user
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

        // Clear stream
        s.str("");
        s.clear();

        // Transform date of creation to time_t
        s << dateOfCreation;
        s >> std::get_time(&doc, "%F");

        // Push back a user
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

/**
 * . Function to return the last id
 * 
 * \return Last id
 */
int pm::dal::UserManager::getLastId()
{
    db.open("../data/users.csv", std::ios::in);

    std::string unused;
    int i = 0;
    int counter = 0;
    if (!db.is_open())
    {
        return NULL;
    }

    while (std::getline(db, unused))
    {
        counter++;
        i = unused[0] - '0';
    }
    db.close();

    if (counter == 1) 
    {
        return 1;
    }
    return i + 1;
}

/**
 * . Function to return user by username
 * 
 * \param username Username of user
 * \return User data
 */
pm::types::User pm::dal::UserManager::getUserByUsername(std::string username) 
{
    // Get all users
    std::vector<pm::types::User> users = this->getAllUsers();

    // Search gor user with the username
    for (auto i = 0; i < users.size(); i++) 
    {
        if (users[i].getUsername() == username) 
        {
            return users[i];
        }
    }

    // If not found return null user
    return pm::types::User();
}

/**
 * . Function that initialized the database
 * 
 */
void pm::dal::UserManager::createDB()
{
    // Check if the file exists
    if (std::filesystem::exists("../data/users.csv"))
    {
        return;
    }

    // Open database and create the file
    db.open("../data/users.csv", std::ios::out);

    if (!db.is_open())
    {
        return;
    }

    time_t t = time(0);
    tm* time = localtime(&t);

    // Write columns in database
    db << "Id,Username,Password,FirstName,LastName,Email,DateOfCreation,isAdmin\n";
    
    // Write admin information in database
    db << 1 << ",admin," << md5("adminpass") << ",NULL,NULL,NULL," << std::put_time(time, "%F") << ",1\n";
    db.flush();
    db.close();
}
