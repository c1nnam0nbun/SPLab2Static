#ifndef DATABASE_H
#define DATABASE_H

#include "employee.h"
#include "taxi.h"

static constexpr int MAX_EMPLOYEES = 1000;
static constexpr int MAX_TAXIS = 1000;

class Database
{
public:
    Database() = default;

    Employee& addEmployee(const std::string& firstName, const std::string& lastName, Position position);
    Employee& getEmployee(const std::string& firstName, const std::string& lastName);
    Employee& getEmployee(unsigned int code);
    void fireEmployee(Employee& e);

    Taxi& addTaxi(unsigned int carCode, unsigned int bodyCode, unsigned int engineCode, unsigned int brandCode, unsigned int registerCode, Employee &driver, Employee &mechanic);
    Taxi& getTaxi(unsigned int carCode, unsigned int bodyCode, unsigned int engineCode, unsigned int brandCode, unsigned int registerCode);
    Taxi& getTaxi(Employee &driver);
    void removeTaxi(Taxi& taxi);

    void displayAllEmployees(Position position = None);
    void displayCurrentEmployees(Position position = None);
    void displayFormerEmployees(Position position = None);

    void displayAllTaxis();
    void displayCurrentTaxis();
    void displayFormerTaxis();

private:
    Employee m_Employees[MAX_EMPLOYEES];
    Taxi m_Taxis[MAX_TAXIS];
    unsigned int m_EmployeeIndex = 0;
    unsigned int m_TaxiIndex = 0;
};

#endif // DATABASE_H
