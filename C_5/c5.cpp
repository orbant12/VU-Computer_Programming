#include <string>
#include <vector>

class BigInt{
    public:
        BigInt(); // default value is 0
        BigInt(unsigned int value);
        BigInt(std::string digitString); // throws std::runtime_error
        
        BigInt operator+(const BigInt& rightValue);
            // example use:
            // BigInt a,b,c;
            // c = a + b;
        bool operator<(const BigInt& rightValue);
            // example use:
            // BigInt a,b;
            // bool x = a < b;
        std::string toString() const;
            // example use:
            // BigInt a(123);
            // a.toString() yields "123"

    private:
        std::vector<int> digits;
            // data structure(s) for storing numbers with arbitrary many digits
            // private helper functions if/as needed
};

BigInt::BigInt(){
    this->digits.push_back(0);
}

BigInt::BigInt(unsigned int value){
    if(value == 0){
        digits.push_back(0);
    } else {
        std::string s = std::to_string(value);
        std::string tempS = "";

        std::vector<int> temp;
        
        for (int i = 0; i < s.size(); ++i){
            tempS = s.at(i);
            int res = std::stoi(tempS);
            this->digits.push_back(res);
        }

        for (int i = digits.size() - 1; i >= 0; --i){
            temp.push_back(this->digits.at(i));
        }

        this->digits = temp;
    }
    
}



BigInt::BigInt(std::string digitString){
    
    if (digitString.empty()) {
        throw std::runtime_error("Invalid");
    }

    bool isInvalFound = false;
    std::vector<char> validChar = {'0','1','2','3','4','5','6','7','8','9'};
    for (int i = 0; i < digitString.size(); ++i){
        char curr = digitString.at(i);
        bool found = false;
        for (int j= 0; j < validChar.size(); ++j){
            if(curr == validChar.at(j)){
                found = true;
            }
        }
        if(found == true){

        } else {
            isInvalFound = true;
            break;
        }
    }
    
    if(isInvalFound == true){
    throw std::runtime_error("Invalid");
    }else{
        for (int i = digitString.size() - 1; i >= 0; --i){
            int res = digitString.at(i) - '0';
            this->digits.push_back(res);
        }
    }
}


std::string BigInt::toString() const {
    std::string s = "";
    for (int i = digits.size() - 1; i >= 0; --i){
        s += (digits.at(i) + '0');
    }
    return s;
}


BigInt BigInt::operator+(const BigInt& rightValue) {
    BigInt result; 
    result.digits.clear(); 
    int carry = 0;
    int maxLength;

    if(digits.size() > rightValue.digits.size()){
        maxLength =digits.size();
    } else {
        maxLength = rightValue.digits.size();
    }
    
    for (int i = 0; i < maxLength || carry; ++i) {
        int sum = carry;
        if (i < digits.size()){
            sum += digits.at(i);
        }  
        if (i < rightValue.digits.size()){
            sum += rightValue.digits.at(i); 
        }
        result.digits.push_back(sum % 10); 
        carry = sum / 10; 
    }
    return result;
}

bool BigInt::operator<(const BigInt& rightValue) {
    if (digits.size() != rightValue.digits.size()) {
        return digits.size() < rightValue.digits.size();
    }
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits.at(i) != rightValue.digits.at(i)) {
            return digits.at(i) < rightValue.digits.at(i);
        }
    }
    return false; 
}