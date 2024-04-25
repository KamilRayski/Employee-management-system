#ifndef EMPLOYEE_EXCEPTION_H
#define EMPLOYEE_EXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * @file employee_exception.h 
 * @brief Plik nag��wkowy zawieraj�cy definicj� klasy EmployeeException
*/

/**
 * @file employee_exception.h
 * @brief Klasa reprezentuj�ca wyj�tki zwi�zane z operacjami na pracownikach.
 * 
 * Klasa dziedziczy po std::runtime_error i zawiera dodatkowe informacje
 * o rodzaju b��du (ErrorType).
*/

class EmployeeException : public std::runtime_error {
public:
    /**
     * @enum ErrorType
     * @brief Typ wyliczeniowy reprezentuj�cy r�ne rodzaje b��d�w zwi�zanych z pracownikami.
    */
    enum class ErrorType {
        ID_ALREADY_EXISTS, /**< ID pracownika ju� istnieje. */
        ID_NON_EXISTS,     /**< ID pracownika nie istnieje. */
        INVALID_INPUT      /**< Nieprawid�owe dane wej�ciowe. */
    };

    /**
     * @brief Konstruktor klasy EmployeeException.
     * @param type Typ b��du (ErrorType).
     * @param message Komunikat opisuj�cy b��d.
    */
    explicit EmployeeException(ErrorType type, const std::string& message);
    /**
     * @brief Pobiera typ b��du.
     * @return Typ b��du (ErrorType).
    */
    ErrorType getErrorType() const;

private:
    ErrorType errorType; /**< Typ b��du. */
};

#endif
