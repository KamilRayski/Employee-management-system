#include "company.h"
#include "manager.h"
#include <iostream>
#include <limits>

void displayMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Add Employee" << std::endl;
    std::cout << "2. Remove Employee" << std::endl;
    std::cout << "3. Change Employee Salary" << std::endl;
    std::cout << "4. Change Employee Bonus" << std::endl;
    std::cout << "5. Change Employee Position" << std::endl;
    std::cout << "6. Display Employee List" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Choose an option:" << std::endl;
}

void addEmployeeMenu(Company& company) {

    std::string firstName, lastName, position;
    int id;
    double salary, bonus;
    std::cout << "Enter first name: ";
    std::cin >> firstName;

    std::cout << "Enter last name: ";
    std::cin >> lastName;

    std::cout << "Enter ID: ";
    std::cin >> id;

    std::cout << "Enter position: ";
    std::cin >> position;

    std::cout << "Enter salary: ";
    std::cin >> salary;

    std::cout << "Enter bonus (optional, enter 0 if none): ";
    std::cin >> bonus;

    company.addEmployee(firstName, lastName, id, position, salary, bonus);


}
void removeEmployeeMenu(Company& company) {
    try {
        int id;
        std::cout << "Enter the ID of the employee to remove: ";
        std::cin >> id;
        company.removeEmployeeById(id);
    }
    catch (const EmployeeException& e) {
        std::cerr << "Error occurred: " << e.what() << std::endl;
    }

}

void changeSalaryMenu(Company& company) {
    try {
        int id;
        double newSalary;
        std::cout << "Enter the ID of the employee whose salary you want to change: ";
        std::cin >> id;

        std::cout << "Enter the new salary: ";
        std::cin >> newSalary;

        company.changeSalary(id, newSalary);

    }
    catch (const EmployeeException& e) {
        std::cerr << "Error occurred: " << e.what() << std::endl;
    }


}

void changePositionMenu(Company& company) {
    int id;
    std::string newPosition;
    try {
        std::cout << "Enter the ID of the employee: ";
        std::cin >> id;

        std::cout << "Enter the new position: ";
        std::cin >> newPosition;

        company.changePosition(id, newPosition);
    }
    catch (const EmployeeException& e) {
        std::cerr << "Error occurred: " << e.what() << std::endl;
    }

}

void changeBonusMenu(Company& company) {
    int id;
    double newBonus;

    std::cout << "Enter the ID of the employee whose bonus you want to change: ";
    std::cin >> id;

    std::cout << "Enter the new bonus: ";
    std::cin >> newBonus;

    if (std::cin.fail()) {
        throw EmployeeException(EmployeeException::ErrorType::INVALID_INPUT, "Input error. Enter valid data.");
    }

    if (company.changeBonus(id, newBonus)) {
        std::cout << "Bonus for employee with ID " << id << " has been changed." << std::endl;
    }
    else {
        throw EmployeeException(EmployeeException::ErrorType::ID_ALREADY_EXISTS, "Employee with the provided ID already exists.");
    }
}



int main() {
    Company myCompany;

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            addEmployeeMenu(myCompany);
            break;
        case 2:
            removeEmployeeMenu(myCompany);
            break;
        case 3:
            changeSalaryMenu(myCompany);
            break;
        case 4:
            changeBonusMenu(myCompany);
            break;
        case 5:
            changePositionMenu(myCompany);
            break;
        case 6:
            std::cout << myCompany;
            break;
        case 7:
            std::cout << "Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 7);

    return 0;
}
