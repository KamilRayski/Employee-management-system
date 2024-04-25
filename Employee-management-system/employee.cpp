#include "employee.h"
#include "manager.h"
#include "developer.h"

Employee::Employee(std::string firstName, std::string lastName, int id, std::string position, double salary, double bonus)
    : firstName(firstName), lastName(lastName), id(id), position(position), salary(salary), bonus(bonus) {}

Employee::~Employee() {}

std::ostream& operator<<(std::ostream& os, const Employee& employee) {
    const Manager* manager = dynamic_cast<const Manager*>(&employee);//pd
    if (manager) {
        return os << *manager;
    }

    const Developer* developer = dynamic_cast<const Developer*>(&employee);//pd
    if (developer) {
        return os << *developer;
    }

    os << "ID: " << employee.getId() << ", Name: " << employee.getFirstName() << " " << employee.getLastName()
        << ", Position: " << employee.getPosition() << ", Salary: " << employee.getSalary()
        << ", Bonus: " << employee.getBonus();
    return os;
}


void Employee::displayInfo() const {
    std::cout << *this;
}
