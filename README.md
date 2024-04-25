
# Employee management system
Employee Classes (Manager and Developer):
The application defines two derived classes from the base class Employee: Manager and Developer. Each class represents a specific type of employee within the company.
Each employee class has attributes such as first name, last name, ID, salary, bonus (for managers and developers), and additional attributes like department (for managers) and programming language (for developers).
The classes implement methods to access and modify these attributes, as well as methods to display employee information.
Company Class:
The Company class represents the company itself and manages a collection of employees.
It provides methods to add new employees, remove employees by ID, change employee salaries, bonuses, and positions, and display the list of employees.
The class ensures the uniqueness of employee IDs and handles exceptions for invalid operations, such as attempting to change the bonus of a non-existent employee.
Main Function:
The main function serves as the entry point of the application.
It presents a menu to the user with options to perform various operations on the employee list.
Depending on the user's choice, it calls corresponding functions to execute the desired operation.
Menu Functions:
Functions like addEmployeeMenu, removeEmployeeMenu, changeSalaryMenu, changeBonusMenu, and changePositionMenu provide interfaces for interacting with the user to perform specific actions.
They handle user input, interact with the Company object, and catch and handle exceptions when necessary.
Overall, this application provides a basic framework for managing employees within a company, allowing users to perform essential operations efficiently.

