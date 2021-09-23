#ifndef DATABASE_H
#define DATABASE_H

#include "employee.h"

static constexpr int MAX_EMPLOYEES = 1000;

class Database
{
public:
    Database() = default;

    Employee& addEmployee(const std::string& firstName, const std::string& lastName, int salary);
    Employee& getEmployee(const std::string& firstName, const std::string& lastName);
    Employee& getEmployee(int employeeID);
    void fireEmployee(Employee& e);

    void promote(const std::string& firstName, const std::string& lastName, int salaryIncrease);
    void promote(int employeeID, int salaryIncrease);
    void promote(Employee& e, int salaryIncrease);

    void demote(const std::string& firstName, const std::string& lastName, int salaryDecrease);
    void demote(int employeeID, int salaryDecrease);
    void demote(Employee& e, int salaryDecrease);

    void displayAll();
    void displayCurrent();
    void displayFormer();

private:
    Employee m_Employees[MAX_EMPLOYEES];
    int m_Index = 0;
};
#endif // DATABASE_H;
