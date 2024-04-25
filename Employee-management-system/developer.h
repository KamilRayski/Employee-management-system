#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "employee.h"

/**
 * @file developer.h
 * @brief Plik nag��wkowy zawieraj�cy definicj� klasy Developer.
*/

/**
 * @class Developer
 * @brief Klasa reprezentuj�ca pracownika typu Developer.
 *
 * Klasa dziedziczy po klasie Employee i zawiera dodatkowe informacje
 * specyficzne dla pracownika typu Developer, takie jak j�zyk programowania.
*/

class Developer : public Employee {
public:
    /**
     * @brief Konstruktor klasy Developer.
     * @param firstName Imi� pracownika.
     * @param lastName Nazwisko pracownika.
     * @param id Numer identyfikacyjny pracownika.
     * @param salary Wynagrodzenie pracownika.
     * @param bonus Premia pracownika.
     * @param programmingLanguage J�zyk programowania pracownika.
    */
    Developer(std::string firstName, std::string lastName, int id, double salary, double bonus, std::string programmingLanguage);
    /**
     * @brief Destruktor klasy Developer.
    */
    virtual ~Developer();
    /**
     * @brief Przyjazna funkcja operatora << do wypisywania informacji o obiekcie Developer.
     * @param os Strumie� wyj�ciowy.
     * @param developer Obiekt klasy Developer.
     * @return Strumie� wyj�ciowy.
    */
    friend std::ostream& operator<<(std::ostream& os, const Developer& developer);
    /**
     * @brief Metoda do wypisywania informacji o obiekcie Developer.
    */
    void displayInfo() const override;

private:
    std::string programmingLanguage; /**< J�zyk programowania pracownika. */
protected:
    /**
     * @brief Metoda zwracaj�ca j�zyk programowania pracownika.
     * @return J�zyk programowania pracownika.
    */
    std::string getProgrammingLanguage() const;
};

#endif
