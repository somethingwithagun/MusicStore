#include "database.h"
bool Database::readUserData(const std::string user)
{
    if (!checkIfUserExists(user))
    {
        return false;
    }
    std::ifstream db(defPathToDB + user + ".txt");
    if(!db.is_open())
        return false;
    std::string buffer;
    while (std::getline(db, buffer))
    {
        int i = 0;
        while (buffer[i] != ':')
        {
            i++;
        }
        i += 2; // because of : and space symbols
        int k = i;
        if (buffer.substr(0, i - 2) == "USERNAME")
        {
            while (buffer[k] != '\0')
            {
                username += buffer[k];
                k++;
            }
        }
        else if (buffer.substr(0, i - 2) == "PASSWORD")
        {
            while (buffer[k] != '\0')
            {
                password += buffer[k];
                k++;
            }
        }
        else if (buffer.substr(0, i - 2) == "ID")
        {
            while (buffer[k] != '\0')
            {
                id += buffer[k];
                k++;
            }
        }
        else if (buffer.substr(0, i - 2) == "BALANCE")
        {
            std::string temp = "";
            while (buffer[k] != '\0')
            {
                temp += buffer[k];
                k++;
            }
            this->setBalance(stoi(temp));
        }
    }
    return true;
}

void Database::writeBalance(int value, std::string username)
{
    if(!checkIfUserExists(username))
    {
        return;
    }
    std::fstream db(defPathToDB + username + ".txt", std::fstream::in);
    std::string buffer;
    std::string newFile = "";
    while(getline(db, buffer))
    {
        if(buffer.substr(0, 7) == "BALANCE") // 7 is the length of BALANCE word
            newFile += "BALANCE: " + std::to_string(value) + '\n';
        else
            newFile += buffer + '\n';
    }
    db.close();
    db.open(defPathToDB + username + ".txt", std::fstream::out);
    db << newFile;
    db.close();
}

bool Database::addUser(std::string username, std::string password)
{
    if (checkIfUserExists(username))
    {
        return false;
    }
    std::ofstream db(defPathToDB + username + ".txt");
    db << "USERNAME: " << username << '\n';
    db << "PASSWORD: " << password << '\n';
    db << "BALANCE: 0" << '\n';
    db << "ID: " << makeId() << '\n';

    db.close();

    readUserData(username);
    
    return true;
}

bool Database::checkIfUserExists(std::string username)
{
    std::ifstream db(defPathToDB + username + ".txt");
    if (!db.is_open())
    {
        return false;
    }
    db.close();
    return true;
}

std::string Database::makeId()
{
    time_t now = time(0);
    tm *ltm = std::localtime(&now);

    std::string res = "";
    res += std::to_string(ltm->tm_hour);
    res += std::to_string(ltm->tm_min);
    res += std::to_string(ltm->tm_sec);

    return res;
}