#include <iostream>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <cmath>


void SetupPossibleChars(std::vector<char>& possibleLetters) {
    
    for (char letter = 'a'; letter <= 'z'; ++letter ) {
        possibleLetters.push_back(letter);
    }

    for (char letter = 'A'; letter <= 'Z'; ++letter ) {
        possibleLetters.push_back(letter);
    }
}

int main(){

    std::string inputString;
    std::vector<char> possibleLetters;
    std::vector<char> userInputedChars;

    SetupPossibleChars(possibleLetters);

    while (!std::cin.fail()){
        std::string tempString;

        std::cin >> tempString;

        inputString += tempString;
    }

    // Transform string strictly to lower case
    for (int i = 0; i < inputString.size(); ++i) {
        char c = tolower(inputString.at(i));
        inputString.at(i) = c;
    }

    for (int i = 0; i < inputString.size(); ++i) {
        char currentChar = inputString.at(i);

        for (int j = 0; j < possibleLetters.size(); ++j){
            if( currentChar == possibleLetters.at(j) ){
                userInputedChars.push_back(currentChar);
                break;
            }
        }
    }

    if ( userInputedChars.size() > 0 ) {
        int sum = 0;
    
        for (int i = 0; i < userInputedChars.size(); ++i) {
            int asci = userInputedChars.at(i) - 'a' + 1;
            sum += asci;
        }
        
        int avarage =  sum  / userInputedChars.size();
        
        char letterFromAsci = static_cast<char>(avarage + 'a' - 1);

        std::cout << "The average letter is " <<  letterFromAsci << "." << std::endl;
        
    } else {
        std::cout << "No letters found." << std::endl;
    }
    
    return 0;
}

