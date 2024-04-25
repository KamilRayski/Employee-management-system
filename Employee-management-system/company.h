#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include "employee.h"
#include "manager.h"
#include "developer.h"
#include "exception.h"

/**
 * @file company.h
 * @brief Plik nag��wkowy zawieraj�cy definicj� klasy Company.
*/

/**
 * @class Company
 * @brief Klasa reprezentuj�ca firm� zarz�dzaj�c� pracownikami.
 *
 * Klasa zawiera funkcje do zarz�dzania pracownikami, takie jak dodawanie, usuwanie,
 * zmiana wynagrodzenia, zmiana stanowiska, zmiana premii.
*/

class Company {
public:
    /**
     * @brief Konstruktor klasy Company.
    */
    Company();
    /**
     * @brief Destruktor klasy Company.
    */
    ~Company();
    /**
     * @brief Dodaje pracownika do firmy.
     * @param firstName Imi� pracownika.
     * @param lastName Nazwisko pracownika.
     * @param id Numer identyfikacyjny pracownika.
     * @param position Stanowisko pracownika.
     * @param salary Wynagrodzenie pracownika.
     * @param bonus Premia pracownika.
     * @throw EmployeeException Wyrzuca wyj�tek, je�li podane ID ju� istnieje.
    */
    void addEmployee(std::string firstName, std::string lastName, int id, const std::string position, double salary, double bonus);
    /**
     * @brief Przyjazna funkcja operatora << do wypisywania informacji o obiekcie Company.
     * @param os Strumie� wyj�ciowy.
     * @param company Obiekt klasy Company.
     * @return Strumie� wyj�ciowy.
    */
    friend std::ostream& operator<<(std::ostream& os, const Company& company);
    /**
     * @brief Wypisuje informacje o wszystkich pracownikach w firmie.
    */
    void displayAllEmployees() const;
    /**
     * @brief Usuwa pracownika z firmy na podstawie numeru identyfikacyjnego.
     * @param id Numer identyfikacyjny pracownika do usuni�cia.
     * @throw EmployeeException Wyrzuca wyj�tek, je�li pracownik o podanym ID nie istnieje.
    */
    void removeEmployeeById(int id);
    /**
     * @brief Zmienia wynagrodzenie pracownika na podstawie numeru identyfikacyjnego.
     * @param id Numer identyfikacyjny pracownika.
     * @param newSalary Nowe wynagrodzenie pracownika.
     * @return True, je�li operacja si� powiedzie; False, je�li nie uda si� znale�� pracownika o podanym ID.
    */
    bool changeSalary(int id, double newSalary);
    /**
     * @brief Zmienia stanowisko pracownika na podstawie numeru identyfikacyjnego.
     * @param id Numer identyfikacyjny pracownika.
     * @param newPosition Nowe stanowisko pracownika.
     * @throw EmployeeException Wyrzuca wyj�tek, je�li pracownik o podanym ID nie istnieje.
    */
    void changePosition(int id, std::string newPosition);
    /**
     * @brief Zmienia premi� pracownika na podstawie numeru identyfikacyjnego.
     * @param id Numer identyfikacyjny pracownika.
     * @param newBonus Nowa premia pracownika.
     * @return True, je�li operacja si� powiedzie; False, je�li nie uda si� znale�� pracownika o podanym ID.
    */
    bool changeBonus(int id, double newBonus);
  
private:
    /**
     * @brief Sprawdza, czy podane ID pracownika jest unikalne w firmie.
     * @param id Numer identyfikacyjny pracownika.
     * @return True, je�li ID jest unikalne; False, je�li ju� istnieje pracownik o podanym ID.
    */
    bool isIdUnique(int id) const;
    std::vector<Employee*> employees; /**< Kontener przechowuj�cy pracownik�w firmy. */
};

#endif