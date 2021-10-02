#include "database.h"
#include <iostream>

Employee &Database::addEmployee(const std::string &firstName, const std::string &lastName, Position position)
{
    if (m_EmployeeIndex >= MAX_EMPLOYEES)
       {
           std::cerr << "Cannot add more employees" << std::endl;
           throw std::exception();
       }

       Employee& emp = m_Employees[m_EmployeeIndex];
       emp.setFirstName(firstName);
       emp.setLastName(lastName);
       emp.setCode(m_EmployeeIndex);
       emp.setPosition(position);
       emp.hire();
       m_EmployeeIndex++;

       return emp;
}

Employee &Database::getEmployee(const std::string &firstName, const std::string &lastName)
{
    for (unsigned int i = 0; i < m_EmployeeIndex; i++)
    {
        Employee& e = m_Employees[i];
        if (e.getFirstName() == firstName && e.getLastName() == lastName) return e;
    }
    std::cerr << "Employee not found" << std::endl;
    throw std::exception();
}

Employee &Database::getEmployee(unsigned int code)
{
    for (unsigned int i = 0; i < m_EmployeeIndex; i++)
       {
           Employee& e = m_Employees[i];
           std::cout << "Emp code: " << e.getCode() << " Code: " << code << std::endl;
           if (e.getCode() == code) return e;
       }
       std::cerr << "Employee not found" << std::endl;
       throw std::exception();
}

void Database::fireEmployee(Employee &e)
{
    e.fire();
}

Taxi &Database::addTaxi(unsigned int carCode, unsigned int bodyCode, unsigned int engineCode, unsigned int brandCode, unsigned int registerCode, Employee& driver, Employee& mechanic)
{
    if (driver.getPosition() != Driver || mechanic.getPosition() != Mechanic)
    {
        std::cerr << "Please assign valid employees." << std::endl;
        throw std::exception();
    }

    if (m_TaxiIndex >= MAX_TAXIS)
       {
           std::cerr << "Cannot add more taxis" << std::endl;
           throw std::exception();
       }

       Taxi& taxi = m_Taxis[m_TaxiIndex];
       taxi.setCarCode(carCode);
       taxi.setBodyCode(bodyCode);
       taxi.setEngineCode(engineCode);
       taxi.setBrandCode(brandCode);
       taxi.setRegisterCode(registerCode);
       taxi.setDriverCode(driver.getCode());
       taxi.setMechanicCode(mechanic.getCode());
       taxi.setActive();
       m_TaxiIndex++;

       return taxi;
}

Taxi &Database::getTaxi(unsigned int carCode, unsigned int bodyCode, unsigned int engineCode, unsigned int brandCode, unsigned int registerCode)
{
    for (unsigned int i = 0; i < m_TaxiIndex; i++)
    {
        Taxi& taxi = m_Taxis[i];
        if (taxi.getCarCode() == carCode && taxi.getBodyCode() == bodyCode && taxi.getEngineCode() == engineCode && taxi.getBrandCode() == brandCode && taxi.getRegisterCode() == registerCode)
            return taxi;
    }
    std::cerr << "Taxi not found" << std::endl;
    throw std::exception();
}

Taxi &Database::getTaxi(Employee& driver)
{
    for (unsigned int i = 0; i < m_TaxiIndex; i++)
    {
        Taxi& taxi = m_Taxis[i];
        if (taxi.getDriverCode() != driver.getCode())
            return taxi;
    }
    std::cerr << "Taxi not found" << std::endl;
    throw std::exception();
}

void Database::removeTaxi(Taxi &taxi)
{
    taxi.setUnactive();
}

void Database::displayAllEmployees(Position position)
{
    for (unsigned int i = 0; i < m_EmployeeIndex; i++)
    {
        Employee& e = m_Employees[i];
        if (position == None) e.display();
        else if (e.getPosition() == position) e.display();
    }
}

void Database::displayCurrentEmployees(Position position)
{
    for (unsigned int i = 0; i < m_EmployeeIndex; i++)
    {
        Employee& e = m_Employees[i];
        if (e.isHired())
        {
            if (position == None) e.display();
            else if (e.getPosition() == position) e.display();
        }
    }
}

void Database::displayFormerEmployees(Position position)
{
    for (unsigned int i = 0; i < m_EmployeeIndex; i++)
    {
        Employee& e = m_Employees[i];
        if (!e.isHired())
        {
            if (position == None) e.display();
            else if (e.getPosition() == position) e.display();
        }
    }
}

void Database::displayAllTaxis()
{
    std::cout << m_TaxiIndex << std::endl;
    for (unsigned int i = 0; i < m_TaxiIndex; i++)
    {
        Taxi& taxi= m_Taxis[i];
        std::cout << taxi.getFullCode() << std::endl;
    }
}

void Database::displayCurrentTaxis()
{
    for (unsigned int i = 0; i < m_TaxiIndex; i++)
    {
        Taxi& taxi= m_Taxis[i];
        if (taxi.isActive())
            std::cout << taxi.getFullCode() << std::endl;
    }
}

void Database::displayFormerTaxis()
{
    for (unsigned int i = 0; i < m_TaxiIndex; i++)
    {
        Taxi& taxi= m_Taxis[i];
        if (!taxi.isActive())
            std::cout << taxi.getFullCode() << std::endl;
    }
}
