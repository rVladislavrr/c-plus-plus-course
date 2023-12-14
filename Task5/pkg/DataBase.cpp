//
// Created by user on 08.12.2023.
//


#include <iostream>
#include "DataBase.h"


void DataBase::AddEvent(const Date& date, const std::string &str)
{
    m_container[date].insert(str);
}

void DataBase::Print() const
{
    for (const auto& iter: m_container)
    {
        for (const auto& iterSet : iter.second)
        {
            std::cout << iter.first.Getstr() << " " << iterSet << std::endl;
        }
    }
}

void DataBase::DeleteEvent(const Date &date, const std::string &event)
{
    if ((m_container.find(date) == m_container.end()) ||
        (m_container[date].find(event) == m_container[date].end() )){
        std::cout << "Event not found" << std::endl;
        return;
    }
    m_container[date].erase(event);
    std::cout << "Deleted successfully" << std::endl;
}

void DataBase::DeleteDate(const Date &date)
{
    size_t N;
    if(m_container.find(date) == m_container.end()){
        N = 0;
    }
    else
    {
        N = m_container[date].size();
        m_container.erase(date);
    }
    std::cout << "Deleted " << N << " events" << std::endl;

}

void DataBase::Find(const Date &date) const
{
    const auto it = m_container.find(date);
    if (it != m_container.end())
    {
        for (const auto &iterSet: it->second)
        {
            std::cout << iterSet << std::endl;
        }
    }
}