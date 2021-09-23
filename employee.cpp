#include "employee.h"
#include <iostream>

Employee::Employee(const std::string &firstName, const std::string &lastName)
    :m_FirstName(firstName), m_LastName(lastName), m_ID(-1), m_IsHired(false)
{}

void Employee::setSalary(int salary)
{
    m_Salary = salary;
}

void Employee::setID(int ID)
{
    m_ID = ID;
}

int Employee::getID()
{
    return m_ID;
}

bool Employee::isHired()
{
    return m_IsHired;
}

void Employee::fire()
{
    m_IsHired = false;
}

void Employee::hire()
{
    m_IsHired = true;
}

void Employee::setFirstName(const std::string firstName)
{
    m_FirstName = firstName;
}

void Employee::setLastName(const std::string lastName)
{
    m_LastName = lastName;
}

std::string& Employee::getFirstName()
{
    return m_FirstName;
}

std::string& Employee::getLastName()
{
    return m_LastName;
}

void Employee::promote(int salaryIncrease)
{
    m_Salary += salaryIncrease;
}

void Employee::demote(int salaryDecrease)
{
    m_Salary += salaryDecrease;
}

void Employee::display()
{
    std::cout << m_ID << ". " << m_FirstName << " " << m_LastName << ", ";
    if (m_IsHired)
    {
        std::cout << "currently employed" << ", $" << m_Salary << std::endl;
    }
    else
    {
        std::cout << "former employee" << std::endl;
    }
}
