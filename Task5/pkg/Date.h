//
// Created by user on 08.12.2023.
//

#ifndef TASK5C_DATE_H
#define TASK5C_DATE_H

#include <iostream>

class Date
{
public:
    Date(int year, int month, int day): m_year(year), m_month(month) ,m_day(day){}
    bool operator< (const Date& other) const;
    bool operator== (const Date& other) const;
    std::string Getstr() const;
private:
    const int m_year;
    const int m_month;
    const int m_day;
};


#endif //TASK5C_DATE_H
