#ifndef EMPLOYEE_EXCEPTION_H
#define EMPLOYEE_EXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * @file employee_exception.h 
 * @brief Plik nag³ówkowy zawieraj¹cy definicjê klasy EmployeeException
*/

/**
 * @file employee_exception.h
 * @brief Klasa reprezentuj¹ca wyj¹tki zwi¹zane z operacjami na pracownikach.
 * 
 * Klasa dziedziczy po std::runtime_error i zawiera dodatkowe informacje
 * o rodzaju b³êdu (ErrorType).
*/

class EmployeeException : public std::runtime_error {
public:
    /**
     * @enum ErrorType
     * @brief Typ wyliczeniowy reprezentuj¹cy ró¿ne rodzaje b³êdów zwi¹zanych z pracownikami.
    */
    enum class ErrorType {
        ID_ALREADY_EXISTS, /**< ID pracownika ju¿ istnieje. */
        ID_NON_EXISTS,     /**< ID pracownika nie istnieje. */
        INVALID_INPUT      /**< Nieprawid³owe dane wejœciowe. */
    };

    /**
     * @brief Konstruktor klasy EmployeeException.
     * @param type Typ b³êdu (ErrorType).
     * @param message Komunikat opisuj¹cy b³¹d.
    */
    explicit EmployeeException(ErrorType type, const std::string& message);
    /**
     * @brief Pobiera typ b³êdu.
     * @return Typ b³êdu (ErrorType).
    */
    ErrorType getErrorType() const;

private:
    ErrorType errorType; /**< Typ b³êdu. */
};

#endif
