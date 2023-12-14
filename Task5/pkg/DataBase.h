//
// Created by user on 08.12.2023.
//

#ifndef TASK5C_DATABASE_H
#define TASK5C_DATABASE_H

#include "Date.h"
#include <string>
#include <set>
#include <map>

class DataBase
{
public:
    void AddEvent(const Date& date, const std::string& str);
    void DeleteEvent(const Date& date, const std::string& event);
    void DeleteDate(const Date& date);
    void Print() const;
    void Find(const Date& date) const;
private:
    std::map < Date, std::set <std::string> > m_container;
};


#endif //TASK5C_DATABASE_H
