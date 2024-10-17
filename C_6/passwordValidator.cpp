#include <iostream>
#include <string>
#include <cctype>

class PasswordValidator {
public:
    PasswordValidator() : isValid(false) {}

    // Overload the insertion operator to input the password
    friend std::istream& operator>>(std::istream& is, PasswordValidator& validator) {
        std::getline(is, validator.password);
        validator.validate(); // Automatically validate after input
        return is;
    }

    bool operator()() {
        validate();
        return isValid;
    }

    operator bool() const {
        return isValid;
    }

    operator void*() const {
        return isValid ? (void*)this : nullptr;
    }   

    // Lennght
    bool operator==(const std::string& other) const {
        return password.length() == other.length();
    }

    bool operator<(const PasswordValidator& other) const {
        return password.length() < other.password.length();
    }

    
    const std::string& getMessage() const {
        return message;
    }

private:
    std::string password;
    bool isValid;
    std::string message;

    void validate() {
        isValid = true; // Assume valid until a rule is violated
        message.clear();

        if (password.length() < 8) {
            isValid = false;
            message = "Password must be at least 8 characters long.";
            return;
        }

        bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
        for (char ch : password) {
            if (std::isupper(ch)) hasUpper = true;
            else if (std::islower(ch)) hasLower = true;
            else if (std::isdigit(ch)) hasDigit = true;
            else if (std::ispunct(ch)) hasSpecial = true;
        }

        if (!hasUpper) {
            isValid = false;
            message = "Password must contain at least one uppercase letter.";
            return;
        }
        if (!hasLower) {
            isValid = false;
            message = "Password must contain at least one lowercase letter.";
            return;
        }
        if (!hasDigit) {
            isValid = false;
            message = "Password must contain at least one digit.";
            return;
        }
        if (!hasSpecial) {
            isValid = false;
            message = "Password must contain at least one special character.";
            return;
        }

        message = "Password is valid.";
    }
};
