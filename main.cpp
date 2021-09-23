#include <iostream>
#include "database.h"

static bool done = false;
static Database db;

int displayMenu()
{
    int selection;
    std::cout << "--------------------Employee Database-----------------\n";
    std::cout << "1) Hire new employee\n";
    std::cout << "2) Fire an employee\n";
    std::cout << "3) Promote an employee\n";
    std::cout << "4) Demote an employee\n";
    std::cout << "5) List all employees\n";
    std::cout << "6) List current employees\n";
    std::cout << "7) List former employees\n";
    std::cout << "0) Exit" << std::endl;

    std::cin >> selection;
    return selection;
}

Employee& selectEmployee()
{
    int selection;
    std::cout << "1) By name\n";
    std::cout << "2) By ID\n";
    std::cin >> selection;

    switch (selection)
    {
        case 1:
        {
            std::string firstName, lastName;

            std::cout << "Enter first name: ";
            std::cin >> firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;

            return db.getEmployee(firstName, lastName);
        }
        case 2:
        {
            int ID;

            std::cout << "Enter ID: ";
            std::cin >> ID;

            return db.getEmployee(ID);
        }
    default: throw std::exception();
    }
}

void doHire()
{
    std::string firstName, lastName;
    int salary;

    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter salary: ";
    std::cin >> salary;

    db.addEmployee(firstName, lastName, salary);
}

void doFire()
{
    Employee& e = selectEmployee();
    db.fireEmployee(e);
}

void doPromote()
{
    int increase;
    Employee& e = selectEmployee();
    std::cout << "Enter salary increase: ";
    std::cin >> increase;
    db.promote(e, increase);
}

void doDemote()
{
    int decreasse;
    Employee& e = selectEmployee();
    std::cout << "Enter salary decrease: ";
    std::cin >> decreasse;
    db.demote(e, decreasse);
}

void doDisplayAll()
{
    std::cout << "--------------------All employees-----------------\n";
    db.displayAll();
}

void doDisplayCurrent()
{
    std::cout << "--------------------Current employees-----------------\n";
    db.displayCurrent();
}

void doDisplayFormer()
{
    std::cout << "--------------------Former employees-----------------\n";
    db.displayFormer();
}

int main()
{
    db = Database();
    while (!done)
    {
        int selection = displayMenu();
        switch (selection) {
            case 1: doHire(); break;
            case 2: doFire(); break;
            case 3: doPromote(); break;
            case 4: doDemote(); break;
            case 5: doDisplayAll(); break;
            case 6: doDisplayCurrent(); break;
            case 7: doDisplayFormer(); break;
            case 0: done = true; break;
        }
    }

}
