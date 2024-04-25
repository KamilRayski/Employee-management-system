#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "employee.h"

/**
 * @file developer.h
 * @brief Plik nag³ówkowy zawieraj¹cy definicjê klasy Developer.
*/

/**
 * @class Developer
 * @brief Klasa reprezentuj¹ca pracownika typu Developer.
 *
 * Klasa dziedziczy po klasie Employee i zawiera dodatkowe informacje
 * specyficzne dla pracownika typu Developer, takie jak jêzyk programowania.
*/

class Developer : public Employee {
public:
    /**
     * @brief Konstruktor klasy Developer.
     * @param firstName Imiê pracownika.
     * @param lastName Nazwisko pracownika.
     * @param id Numer identyfikacyjny pracownika.
     * @param salary Wynagrodzenie pracownika.
     * @param bonus Premia pracownika.
     * @param programmingLanguage Jêzyk programowania pracownika.
    */
    Developer(std::string firstName, std::string lastName, int id, double salary, double bonus, std::string programmingLanguage);
    /**
     * @brief Destruktor klasy Developer.
    */
    virtual ~Developer();
    /**
     * @brief Przyjazna funkcja operatora << do wypisywania informacji o obiekcie Developer.
     * @param os Strumieñ wyjœciowy.
     * @param developer Obiekt klasy Developer.
     * @return Strumieñ wyjœciowy.
    */
    friend std::ostream& operator<<(std::ostream& os, const Developer& developer);
    /**
     * @brief Metoda do wypisywania informacji o obiekcie Developer.
    */
    void displayInfo() const override;

private:
    std::string programmingLanguage; /**< Jêzyk programowania pracownika. */
protected:
    /**
     * @brief Metoda zwracaj¹ca jêzyk programowania pracownika.
     * @return Jêzyk programowania pracownika.
    */
    std::string getProgrammingLanguage() const;
};

#endif
