#include <iostream>

class Stream {

    public:
        
        Stream(std::istream& is = std::cin) : inputStream(is), state(true) {};

        // Overload for int
        Stream& operator>>(int& number) {
            if (inputStream >> number) {
                state = true;
            } else {
                state = false;
                inputStream.clear(); 
                char discard;
                inputStream >> discard;
            }
            return *this;
        }

        // Overload for double
        Stream& operator>>(double& number) {
        if (inputStream >> number) {
            state = true;
        } else {
            state = false;
            inputStream.clear();
            char discard;
            inputStream >> discard;
        }
        return *this;
    }

        // Overload for std::string
        Stream& operator>>(std::string& text) {
            if (inputStream >> text) {
                state = true;
            } else {
                state = false;
                inputStream.clear();
                char discard;
                inputStream >> discard;
            }
            return *this;
        }

        // Overload the conversion to bool
        operator bool() const {
            return state;
        }

        operator void*() const {
            return state ? (void*)this : nullptr;
        }

        bool operator!() const {
            return !state;
        }

    private:
        std::istream& inputStream;
        bool state; 
};





