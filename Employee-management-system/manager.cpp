#include "manager.h"

Manager::Manager(std::string firstName, std::string lastName, int id, double salary, double bonus, std::string department)
    : Employee(firstName, lastName, id, "Manager", salary, bonus), department(department) {}

Manager::~Manager() {}

std::ostream& operator<<(std::ostream& os, const Manager& manager) {
    os << "ID: " << manager.getId() << ", Name: " << manager.getFirstName() << " " << manager.getLastName()
        << ", Position: Manager, Salary: " << manager.getSalary() << ", Bonus: " << manager.getBonus()
        << ", Department: " << manager.getDepartment();
    return os;
}

std::string Manager::getDepartment() const { return department; }

void Manager::displayInfo() const {
    std::cout << *this;
}
