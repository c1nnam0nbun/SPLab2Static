#include "database.h"
#include <iostream>
#include <stdexcept>


Employee &Database::addEmployee(const std::string &firstName, const std::string &lastName, int salary)
{
    if (m_Index >= MAX_EMPLOYEES)
    {
        std::cerr << "Cannot add more employees" << std::endl;
        throw std::exception();
    }

    Employee& emp = m_Employees[m_Index];
    emp.setFirstName(firstName);
    emp.setLastName(lastName);
    emp.setID(m_Index);
    emp.setSalary(salary);
    emp.hire();
    m_Index++;

    return emp;
}

Employee &Database::getEmployee(const std::string &firstName, const std::string &lastName)
{
    for (int i = 0; i < m_Index; i++)
    {
        Employee& e = m_Employees[i];
        if (e.getFirstName() == firstName && e.getLastName() == lastName) return e;
    }
    std::cerr << "Employee not found" << std::endl;
    throw std::exception();
}

Employee &Database::getEmployee(int employeeID)
{
    for (int i = 0; i < m_Index; i++)
    {
        Employee& e = m_Employees[i];
        if (e.getID() == employeeID) return e;
    }
    std::cerr << "Employee not found" << std::endl;
    throw std::exception();
}

void Database::fireEmployee(Employee &e)
{
    e.fire();
}

void Database::promote(const std::string &firstName, const std::string &lastName, int salaryIncrease)
{
    getEmployee(firstName, lastName).promote(salaryIncrease);
}

void Database::promote(int employeeID, int salaryIncrease)
{
    getEmployee(employeeID).promote(salaryIncrease);
}

void Database::promote(Employee &e, int increase)
{
    e.promote(increase);
}

void Database::demote(const std::string &firstName, const std::string &lastName, int salaryDecrease)
{
    getEmployee(firstName, lastName).promote(salaryDecrease);
}

void Database::demote(int employeeID, int salaryDecrease)
{
    getEmployee(employeeID).promote(salaryDecrease);
}

void Database::demote(Employee &e, int salaryDecrease)
{
    e.demote(salaryDecrease);
}


void Database::displayAll()
{
    for (int i = 0; i < m_Index; i++) m_Employees[i].display();
}

void Database::displayCurrent()
{
    for (int i = 0; i < m_Index; i++)
    {
        Employee e = m_Employees[i];
        if (e.isHired()) e.display();
    }
}

void Database::displayFormer()
{
    for (int i = 0; i < m_Index; i++)
    {
        Employee e = m_Employees[i];
        if (!e.isHired()) e.display();
    }
}
