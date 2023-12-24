
#include <iostream>
#include <sstream>
#include "../pkg/DataBase.h"

Date chekDate(std::istringstream &is)
{
    std::string date;
    is >> date;
    std::istringstream dateStream(date);
    int year, month, day;
    char dash;

    if (!(dateStream >> year >> dash >> month >> dash >> day) || (dateStream >> dash))
        throw std::logic_error("Wrong date format: " + date);
    return {year, month, day};
}

void chekComm(std::istringstream &is , DataBase& db)
{
    std::string comm;
    is >> comm;

    if (!comm.empty())
    {
        if (comm == "Add")
        {
            Date date = chekDate(is);
            std::string str;
            is >> str;
            db.AddEvent(date, str);
        }
        else if (comm == "Print")
        {
            db.Print();
        }
        else if (comm == "Find")
        {
            Date date = chekDate(is);
            const auto sett = db.Find(date);

            for(const auto& event : sett)
            {
                std::cout << event << std::endl;
            }

        }
        else if (comm == "Del")
        {
            Date date = chekDate(is);
            std::string str;
            is >> str;

            if (str.empty())
            {
                db.DeleteDate(date);
            }
            else
            {
                db.DeleteEvent(date, str);
            }
        }
        else
        {
            throw std::runtime_error("Unknown command: " + comm);
        }
    }
}

int main() {
    DataBase db;
    std::string commandLine;

    while (std::getline(std::cin, commandLine))
    {
        std::istringstream is(commandLine);
        try
        {
            chekComm(is ,db);
        }
        catch (const std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
            break;
        }
        catch (const std::logic_error& e)
        {
            std::cout << e.what() << std::endl;
            break;
        }
    }
    return 0;
}
