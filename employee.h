#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

enum Position
{
    None,
    Driver,
    Mechanic
};

static const char* positionStr[] = {"None", "Driver", "Mechanic"};

inline const char* getPositionString(Position pos)
{
    return positionStr[pos];
}


class Employee
{
public:
    Employee() = default;
    Employee(const std::string& firstName, const std::string& lastName, Position position);
    ~Employee() = default;

public:
    std::string& getFirstName();
    std::string& getLastName();
    void setFirstName(const std::string firstName);
    void setLastName(const std::string lastName);
    unsigned int getCode();
    void setCode(unsigned int code);
    Position getPosition();
    void setPosition(Position position);
    bool isHired();
    void fire();
    void hire();
    void display();

private:
    std::string m_FirstName;
    std::string m_LastName;
    Position m_Position;
    unsigned int m_Code;
    bool m_IsHired;
};

#endif // EMPLOYEE_H
