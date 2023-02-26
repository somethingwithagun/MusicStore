#ifndef DATABASE_H_
#define DATABASE_H_

#include <ctime>
#include <fstream>
#include <string>

class Database
{
  public: // constructor & destructor
    Database()
    {
    }
    ~Database()
    {
    }

  public:
    std::string getUsername()
    {
        return this->username;
    }
    std::string getPassword()
    {
        return this->password;
    }
    std::string getId()
    {
        return this->id;
    }
    int getBalance()
    {
        return this->balance;
    }
    void setId(std::string value)
    {
        this->id = value;
    }
    void setUsername(std::string value)
    {
        this->username = value;
    }
    void setPassword(std::string value)
    {
        this->password = value;
    }
    void setBalance(int value)
    {
        this->balance = value;
    }
    // write current user's balance
    void writeBalance(int value, std::string username);
    // add new user into database
    bool addUser(std::string username, std::string password);
    // read data from database
    bool readUserData(const std::string filepath);

  private:
    const std::string defPathToDB = "./data/accounts/"; // default path to database storage
    std::string username;
    std::string password;
    std::string id;
    int balance;
    std::string makeId();
    bool checkIfUserExists(
        std::string username); // checks if file with similar username exists, if true, then username must be changed
};

#endif