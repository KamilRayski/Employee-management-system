#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <string>
#include <vector>

/**
 * @file employee.h
 * @brief Plik nag³ówkowy zawieraj¹cy definicjê klasy Employee.
*/

/**
 * @class Employee
 * @brief Klasa reprezentuj¹ca ogólnego pracownika.
 *
 * Klasa zawiera podstawowe informacje o pracowniku, takie jak imiê, nazwisko,
 * identyfikator, stanowisko, wynagrodzenie i premia.
*/

class Employee {
public:
    /**
     * @brief Konstruktor klasy Employee.
     * @param firstName Imiê pracownika.
     * @param lastName Nazwisko pracownika.
     * @param id Numer identyfikacyjny pracownika.
     * @param position Stanowisko pracownika.
     * @param salary Wynagrodzenie pracownika.
     * @param bonus Premia pracownika.
    */
    Employee(std::string firstName, std::string lastName, int id, std::string position, double salary, double bonus);
    /**
     * @brief Destruktor klasy Employee.
    */
    virtual ~Employee();
    /**
     * @brief Przyjazna funkcja operatora << do wypisywania informacji o obiekcie Employee.
     * @param os Strumieñ wyjœciowy.
     * @param employee Obiekt klasy Employee.
     * @return Strumieñ wyjœciowy.
    */
    friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
    /**
     * @brief Metoda do wypisywania informacji o obiekcie Employee.
    */
    virtual void displayInfo() const;
    /**
     * @brief Pobiera numer identyfikacyjny pracownika.
     * @return Numer identyfikacyjny pracownika.
    */
    int getId() const { return id; }
    /**
     * @brief Ustawia nowe wynagrodzenie pracownika.
     * @param newSalary Nowe wynagrodzenie pracownika.
    */
    void setSalary(double newSalary) { salary = newSalary; }
    /**
     * @brief Ustawia nowe stanowisko pracownika.
     * @param newPosition Nowe stanowisko pracownika.
    */
    void setPosition(std::string newPosition) { position = newPosition; }
    /**
     * @brief Ustawia now¹ premiê pracownika.
     * @param newBonus Nowa premia pracownika.
    */
    void setBonus(double newBonus) { bonus = newBonus; }
    /**
     * @brief Pobiera imiê pracownika.
     * @return Imiê pracownika.
    */
    std::string getFirstName() const { return firstName; }
    /**
     * @brief Pobiera nazwisko pracownika.
     * @return Nazwisko pracownika.
    */
    std::string getLastName() const { return lastName; }
    /**
     * @brief Pobiera stanowisko pracownika.
     * @return Stanowisko pracownika.
    */
    std::string getPosition() const { return position; }
    /**
     * @brief Pobiera wynagrodzenie pracownika.
     * @return Wynagrodzenie pracownika.
    */
    double getSalary() const { return salary; }
    /**
     * @brief Pobiera premiê pracownika.
     * @return Premia pracownika.
    */
    double getBonus() const { return bonus; }
private:
    std::string firstName; /**< Imiê pracownika. */
    std::string lastName;  /**< Nazwisko pracownika. */
    int id;               /**< Numer identyfikacyjny pracownika. */
    std::string position; /**< Stanowisko pracownika. */
    double salary;        /**< Wynagrodzenie pracownika. */
    double bonus;         /**< Premia pracownika. */
};

#endif
