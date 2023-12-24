//
// Created by user on 08.12.2023.
//

#include "Date.h"
#include <iostream>
#include "Date.h"

bool Date::operator< (const Date &other) const
{
    if (m_year != other.m_year)
    {
        return m_year < other.m_year;
    }
    if (m_month != other.m_month)
    {
        return  m_month < other.m_month;
    }
    return m_day < other.m_day;
}

std::ostream& operator << (std::ostream &os, const Date &date)
{
    std::string year , month , day;
    year = std::string(4 - std::to_string(date.m_year).length() , '0')
           + std::to_string(date.m_year);

    month = std::string(2 - std::to_string(date.m_month).length() , '0')
            + std::to_string(date.m_month);

    day = std::string(2 - std::to_string(date.m_day).length() , '0')
          + std::to_string(date.m_day);
    os << (year + "-" + month + "-" + day);
    return os;
}

bool Date::operator== (const Date &other) const
{
    return (m_year == other.m_year) && (m_month == other.m_month) &&
           (m_day == other.m_day);
}

Date::Date(int year, int month, int day) : m_year(year), m_month(month) ,m_day(day)
{
    if (m_month < 1 || m_month > 12) {
        throw std::logic_error("Month value is invalid: " +
                               std::to_string(month));
    } else if (m_day < 1 || m_day > 31) {
        throw std::logic_error("Day value is invalid: " +
                               std::to_string(day));
    }
}
