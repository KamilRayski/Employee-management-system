#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"

/**
 * @file manager.h
 * @brief Plik nag��wkowy zawieraj�cy definicj� klasy Manager.
*/

/**
 * @class Manager
 * @brief Klasa reprezentuj�ca pracownika typu Manager.
 *
 * Klasa dziedziczy po klasie Employee i zawiera dodatkowe informacje
 * specyficzne dla pracownika typu Manager, takie jak dzia�.
*/

class Manager : public Employee {
public:
    /**
     * @brief Konstruktor klasy Manager.
     * @param firstName Imi� pracownika.
     * @param lastName Nazwisko pracownika.
     * @param id Numer identyfikacyjny pracownika.
     * @param salary Wynagrodzenie pracownika.
     * @param bonus Premia pracownika.
     * @param department Dzia�, kt�rym zarz�dza pracownik typu Manager.
    */
    Manager(std::string firstName, std::string lastName, int id, double salary, double bonus, std::string department);
    /**
     * @brief Destruktor klasy Manager.
    */
    virtual ~Manager();
    /**
     * @brief Przyjazna funkcja operatora << do wypisywania informacji o obiekcie Manager.
     * @param os Strumie� wyj�ciowy.
     * @param manager Obiekt klasy Manager.
     * @return Strumie� wyj�ciowy.
    */
    friend std::ostream& operator<<(std::ostream& os, const Manager& manager);
    /**
     * @brief Metoda do wypisywania informacji o obiekcie Manager.
    */
    void displayInfo() const override;

private:
    std::string department; /**< Dzia�, kt�rym zarz�dza pracownik typu Manager. */
protected:
    /**
     * @brief Metoda zwracaj�ca dzia�, kt�rym zarz�dza pracownik typu Manager.
     * @return Dzia� pracownika typu Manager.
    */
    std::string getDepartment() const;
};

#endif
