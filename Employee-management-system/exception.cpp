#include "exception.h"

EmployeeException::EmployeeException(ErrorType type, const std::string& message)
    : std::runtime_error(message), errorType(type) {}

EmployeeException::ErrorType EmployeeException::getErrorType() const {
    return errorType;
}
