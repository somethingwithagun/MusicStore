#ifndef CURRENTACCOUNT_H_
#define CURRENTACCOUNT_H_

#include <string>

class CurrentAccount
{
  public:
    CurrentAccount(){};
    ~CurrentAccount(){};
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
    std::string getId()
    {
        return this->id;
    }
    std::string getUsername()
    {
       return this->username;
    }
    std::string getPassword()
    {
        return this->password;
    }
    int getBalance()
    {
        return this->balance;
    }

  private:
    int balance;
    std::string username;
    std::string password;
    std::string id;
};

#endif