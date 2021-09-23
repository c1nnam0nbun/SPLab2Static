#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
public:
    Employee() = default;
    Employee(const std::string& firstName, const std::string& lastName);
    ~Employee() = default;

public:
    void promote(int salaryIncrease);
    void demote(int salaryDecrease);
    std::string& getFirstName();
    std::string& getLastName();
    void setFirstName(const std::string firstName);
    void setLastName(const std::string lastName);
    void setSalary(int salary);
    void setID(int ID);
    int getID();
    bool isHired();
    void fire();
    void hire();
    void display();

private:
    std::string m_FirstName;
    std::string m_LastName;
    int m_ID;
    int m_Salary;
    bool m_IsHired;
};

#endif // EMPLOYEE_H
