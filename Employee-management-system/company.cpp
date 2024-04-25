#include "company.h"


Company::Company() {}

Company::~Company() {
    for (Employee* emp : employees) {
        delete emp;
    }
}

bool Company::isIdUnique(int id) const {

    auto it = std::find_if(employees.begin(), employees.end(),[id](const Employee* emp) { return emp->getId() == id; });
    return it == employees.end();
}


void Company::addEmployee(const std::string firstName, const std::string lastName, int id, const std::string position, double salary, double bonus) {
   
        if (isIdUnique(id)) {
            if (salary > 0 && bonus >= 0) {
                if (position == "Manager") {
                    std::string department;
                    std::cout << "Enter department of manager: ";
                    std::cin >> department;
                    employees.push_back(new Manager(firstName, lastName, id, salary, bonus, department));
                }
                else if (position == "Developer") {
                    std::string programmingLanguage;
                    std::cout << "Enter a programming language of developer: ";
                    std::cin >> programmingLanguage;
                    employees.push_back(new Developer(firstName, lastName, id, salary, bonus, programmingLanguage));
                }
                else {
                    employees.push_back(new Employee(firstName, lastName, id, position, salary, bonus));
                }
            }
            else {
                throw EmployeeException(EmployeeException::ErrorType::INVALID_INPUT, "Salary must be greater than 0 and bonus must be greater than or equal to 0.");
            }

        }
        else {
            throw EmployeeException(EmployeeException::ErrorType::ID_ALREADY_EXISTS, "Employee with the provided ID already exists.");
        }

    

}


std::ostream& operator<<(std::ostream& os, const Company& company) {
    os << "Employee List:\n";
    for (const Employee* emp : company.employees) {
        os << *emp << "\n";
    }
    return os;
}


void Company::displayAllEmployees() const {
    std::cout << *this;
}

void Company::removeEmployeeById(int id) {
    auto it = std::remove_if(employees.begin(), employees.end(),
        [id](const Employee* emp) { return emp->getId() == id; });

    if (it != employees.end()) {
        delete* it;
        employees.erase(it);
        std::cout << "Employee with ID " << id << " has been removed." << std::endl;
    }
    else {
        throw EmployeeException(EmployeeException::ErrorType::ID_NON_EXISTS, "Employee with the provided ID does not exist.");
    }
}
bool Company::changeSalary(int id, double newSalary) {
    auto it = std::find_if(employees.begin(), employees.end(),
        [id](const Employee* emp) { return emp->getId() == id; });

    if (it != employees.end()) {
        if (newSalary > 0) {
            (*it)->setSalary(newSalary);
            return true;
        }
        else {
            throw EmployeeException(EmployeeException::ErrorType::INVALID_INPUT, "Salary must be greater than 0.");
            return false;
        }
    }else {
        throw EmployeeException(EmployeeException::ErrorType::ID_NON_EXISTS, "Employee with the provided ID does not exist.");
    }
}

void Company::changePosition(int id, const std::string newPosition) {
    auto it = std::find_if(employees.begin(), employees.end(),
        [id](const Employee* emp) { return emp->getId() == id; });
    if (it != employees.end()) {
        Employee* employee = *it;
        Employee* newEmployee = nullptr;

        if (newPosition == "Manager") {
            std::string department;
            std::cout << "Enter department of manager: ";
            std::cin >> department;
            newEmployee= new Manager(employee->getFirstName(), employee->getLastName(), id, employee->getSalary(), employee->getBonus(), department);
        }
        else if (newPosition == "Developer") {
            std::string programmingLanguage;
            std::cout << "Enter a programming language of developer: ";
            std::cin >> programmingLanguage;
            newEmployee = new Developer(employee->getFirstName(), employee->getLastName(), id, employee->getSalary(), employee->getBonus(), programmingLanguage);
        }
        else {
           
            newEmployee = new Employee(employee->getFirstName(), employee->getLastName(), id, newPosition, employee->getSalary(), employee->getBonus());
        }
        
        *it = newEmployee;

        delete employee;

    }
    else {
        throw EmployeeException(EmployeeException::ErrorType::ID_NON_EXISTS, "Employee with the provided ID does not exist");
    }

}

bool Company::changeBonus(int id, double newBonus) {
    auto it = std::find_if(employees.begin(), employees.end(),
        [id](const Employee* emp) { return emp->getId() == id; });
    try {
        if (it != employees.end()) {
            Employee* employee = *it;
            if (newBonus >= 0) {
                employee->setBonus(newBonus);
                return true;
            }
            else {
                std::cerr << "Bonus must be greater than or equal to 0." << std::endl;
                return false;
            }
        }
        else {
            throw EmployeeException(EmployeeException::ErrorType::ID_NON_EXISTS, "Employee with the provided ID does not exist");
        }
    } catch (const EmployeeException& e) {
 
        std::cerr << "Error occured: " << e.what() << std::endl;
    }

}

