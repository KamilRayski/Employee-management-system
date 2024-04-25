#include "developer.h"

Developer::Developer(std::string firstName, std::string lastName, int id, double salary, double bonus, std::string programmingLanguage)
    : Employee(firstName, lastName, id,"Developer", salary, bonus), programmingLanguage(programmingLanguage) {}

Developer::~Developer(){}

std::ostream& operator<<(std::ostream& os, const Developer& developer) {
    os << "ID: " << developer.getId() << ", Name: " << developer.getFirstName() << " " << developer.getLastName()
        << ", Position: Developer, Salary: " << developer.getSalary() << ", Bonus: " << developer.getBonus()
        << ", Programming Language: " << developer.getProgrammingLanguage();
    return os;
}
std::string Developer::getProgrammingLanguage() const { return programmingLanguage; }

void Developer::displayInfo() const {
    std::cout << *this;
}
