#include "employee.h"
#include <iostream>

Employee::Employee(const std::string &firstName, const std::string &lastName, Position position)
    : m_FirstName(firstName), m_LastName(lastName)
{
    m_Position = position;
}

void Employee::setCode(unsigned int code)
{
    m_Code = code;
}

Position Employee::getPosition()
{
    return m_Position;
}

void Employee::setPosition(Position position)
{
    m_Position = position;
}

unsigned int Employee::getCode()
{
    return m_Code;
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

void Employee::display()
{
    std::cout << m_Code << " " << m_FirstName << " " << m_LastName << " " << getPositionString(m_Position) << " " << (m_IsHired ? "currently employed" : "former employee") << std::endl;
}
