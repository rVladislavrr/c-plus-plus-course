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

bool Date::operator== (const Date &other) const
{
    return (m_year == other.m_year) && (m_month == other.m_month) &&
           (m_day == other.m_day);
}

std::string Date::Getstr() const
{
    std::string year , month , day;
    year = std::string(4 - std::to_string(m_year).length() , '0')
           + std::to_string(m_year);

    month = std::string(2 - std::to_string(m_month).length() , '0')
            + std::to_string(m_month);

    day = std::string(2 - std::to_string(m_day).length() , '0')
          + std::to_string(m_day);
    return year + "-" + month + "-" + day;
}