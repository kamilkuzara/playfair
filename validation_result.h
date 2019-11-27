#ifndef VALIDATION_RESULT_H
#define VALIDATION_RESULT_H

#include <string>

using std::string;

class ValidationResult{
private:
    bool formatValid;
    string errorMessage;

public:
    ValidationResult(bool flag, string message)
        : formatValid(flag), errorMessage(message)
    {
    }

    ValidationResult(bool flag)
        : formatValid(flag), errorMessage("")
    {
    }

    void operator=(const ValidationResult &other)
    {
        formatValid = other.isFormatValid();
        errorMessage = other.getMessage();
    }

    bool isFormatValid() const
    {
        return formatValid;
    }

    string getMessage() const
    {
        return errorMessage;
    }
};

#endif
