#include <iostream>
#include "database.h"

static bool done = false;
static Database db;

int displayMenu()
{
    int selection;
    std::cout << "--------------------Database-----------------\n";
    std::cout << "1) Hire new employee\n";
    std::cout << "2) Fire an employee\n";
    std::cout << "3) Add taxi\n";
    std::cout << "4) Remove taxi\n";
    std::cout << "5) List all employees\n";
    std::cout << "6) List current employees\n";
    std::cout << "7) List former employees\n";
    std::cout << "8) List all taxis\n";
    std::cout << "9) List current taxis\n";
    std::cout << "10) List former taxis\n";
    std::cout << "0) Exit" << std::endl;

    std::cin >> selection;
    return selection;
}

Employee& selectEmployee()
{
    int selection;
    std::cout << "1) By name\n";
    std::cout << "2) By code\n";
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
            unsigned int code;

            std::cout << "Enter code: ";
            std::cin >> code;

            return db.getEmployee(code);
        }
    default: throw std::exception();
    }
}

void doHire()
{
    std::string firstName, lastName, position;

    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;

    int selection;
    std::cout << "1) Driver\n";
    std::cout << "2) Mechanic\n";
    std::cin >> selection;

    if (selection != Driver && selection != Mechanic)
    {
        std::cerr << "Select valid position." << std::endl;
        throw std::exception();
    }

    db.addEmployee(firstName, lastName, (Position) selection);
}

void doFire()
{
    Employee& e = selectEmployee();
    db.fireEmployee(e);
}

Taxi& selectTaxi()
{
    int selection;
    std::cout << "1) By code\n";
    std::cout << "2) By driver\n";
    std::cin >> selection;

    switch (selection)
    {
        case 1:
        {
            unsigned int carCode, bodyCode, engineCode, brandCode, registerCode;
            std::cout << "Enter car code: ";
            std::cin >> carCode;
            std::cout << "Enter body code: ";
            std::cin >> bodyCode;
            std::cout << "Enter engine code: ";
            std::cin >> engineCode;
            std::cout << "Enter brand code: ";
            std::cin >> brandCode;
            std::cout << "Enter register code: ";
            std::cin >> registerCode;

            return db.getTaxi(carCode, bodyCode, engineCode, brandCode, registerCode);
        }
        case 2:
        {
            std::cout << "Select driver: ";
            Employee& driver = selectEmployee();

            return db.getTaxi(driver);
        }
    default: throw std::exception();
    }
}


void doAddTaxi()
{
    unsigned int carCode, bodyCode, engineCode, brandCode, registerCode;
    std::cout << "Enter car code: ";
    std::cin >> carCode;
    std::cout << "Enter body code: ";
    std::cin >> bodyCode;
    std::cout << "Enter engine code: ";
    std::cin >> engineCode;
    std::cout << "Enter brand code: ";
    std::cin >> brandCode;
    std::cout << "Enter register code: ";
    std::cin >> registerCode;

    std::cout << "Select driver: ";
    Employee& driver = selectEmployee();

    std::cout << "Select mechanic: ";
    Employee& mechanic = selectEmployee();

    db.addTaxi(carCode, bodyCode, engineCode, brandCode, registerCode, driver, mechanic);
}

void doRemoveTaxi()
{
    Taxi& taxi = selectTaxi();
    db.removeTaxi(taxi);
}


void doDisplayAllEmployees()
{
    std::cout << "--------------------All employees-----------------\n";
    db.displayAllEmployees();
}

void doDisplayCurrentEmployees()
{
    std::cout << "--------------------Current employees-----------------\n";
    db.displayCurrentEmployees();
}

void doDisplayFormerEmployees()
{
    std::cout << "--------------------Former employees-----------------\n";
    db.displayFormerEmployees();
}

void doDisplayAllTaxis()
{
    std::cout << "--------------------All taxis-----------------\n";
    db.displayAllTaxis();
}

void doDisplayCurrentTaxis()
{
    std::cout << "--------------------Current taxis-----------------\n";
    db.displayCurrentTaxis();
}

void doDisplayFormerTaxis()
{
    std::cout << "--------------------Former taxis-----------------\n";
    db.displayFormerTaxis();
}

int main()
{
    db = Database();
    while (!done)
    {
        int selection = displayMenu();
        switch (selection) {
            case 1:  doHire(); break;
            case 2:  doFire(); break;
            case 3:  doAddTaxi(); break;
            case 4:  doRemoveTaxi(); break;
            case 5:  doDisplayAllEmployees(); break;
            case 6:  doDisplayCurrentEmployees(); break;
            case 7:  doDisplayFormerEmployees(); break;
            case 8:  doDisplayAllTaxis(); break;
            case 9:  doDisplayCurrentTaxis(); break;
            case 10: doDisplayFormerTaxis(); break;
            case 0:  done = true;
        }
    }

}
