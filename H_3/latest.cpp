#include <iostream>
#include <fstream>
#include <vector>

bool processInputFromFile(std::string& inputString, std::string fileName)
{    
    std::ifstream inFS;

    inFS.open(fileName);

    if(!inFS.is_open()){
        std::cout << "cannot open input file " << fileName << std::endl;
        return false;
    }

    inFS >> inputString;

    while(!inFS.fail()){
        std::string tempInput;
        inFS >> tempInput;

        inputString += tempInput;
    }

    return true;
}

void processInputFromCin(std::string& inputString)
{
     std::cin >> inputString;

    while (!std::cin.fail()){
        std::string tempInput;
        std::cin >> tempInput;

        inputString += tempInput;
    }
}

void CreateValidVectorFromString( std::vector<char>& validInputChars, std::string& inputString)
{    
    for (int i = 0; i < inputString.size(); ++i){
        char currentLetter = inputString.at(i);
        if(std::isalpha(currentLetter)){
            validInputChars.push_back(currentLetter);
        }
    }
}

void TransformCharVecToAllLower(std::vector<char>& inputVector) 
{
    for (int i = 0; i < inputVector.size(); ++i){
        char lower = std::tolower(inputVector.at(i));
        inputVector.at(i) = lower;
    }
}

std::vector<std::vector<int>> GenerateCounterMatrix(std::vector<char>& validInputChars) 
{
    std::vector<std::vector<int>> counterMatrix;

    for (char letter = 'a'; letter <= 'z'; ++letter ){
        std::vector<int> tempVec = {letter, 0};
        counterMatrix.push_back(tempVec);
    }

    for (int i = 0; i < validInputChars.size(); ++i){
        int currentChar = validInputChars.at(i);
        for (int j = 0; j < counterMatrix.size(); ++j){
            if(counterMatrix.at(j)[0] == currentChar){
                counterMatrix.at(j)[1] += 1;
                break;
            }
        }
    }

    return counterMatrix;
}

void FindAndPrintLetterStats(std::vector<std::vector<int>>& counterMatrix)
{
    char maxVowel = 'a'; 
    int maxVowelCount = 0;

    char maxConstans = 'b'; 
    int maxConstansCount = 0;

    char mostFrequent = 'a'; 
    int mostFrequentCount = 0;

    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    
    for (int i = 0; i < counterMatrix.size(); ++i){
        std::vector<int> currVec = counterMatrix.at(i);
        bool found = false;

        // Check for vowels
        for (int j = 0; j < vowels.size(); ++j){
            int currentVowelToAsci = vowels.at(j);
            if(currentVowelToAsci == currVec[0]){
                found = true;
                if(maxVowelCount < currVec[1]){
                    maxVowelCount = currVec[1];
                    maxVowel = currVec[0];
                }
            }
        }

        // If not vowel then constans
        if(!found){
            if(maxConstansCount < currVec[1]){
                    maxConstansCount = currVec[1];
                    maxConstans = currVec[0];
            }
        }
    }

    if(maxVowelCount > maxConstansCount){
        mostFrequent = maxVowel;
        mostFrequentCount = maxVowelCount;
    } else if (maxVowelCount < maxConstansCount){
        mostFrequent = maxConstans;
        mostFrequentCount = maxConstansCount;
    } else {
        if(maxVowel > maxConstans){
            mostFrequent = maxConstans;
            mostFrequentCount = maxConstansCount;
        } else {
            mostFrequent = maxVowel;
            mostFrequentCount = maxVowelCount;
        }
    }

    std::cout << "Most frequent vowel: " << maxVowel << " (" << maxVowelCount << " times" << ")" << std::endl;
    std::cout << "Most frequent consonant: " << maxConstans << " (" << maxConstansCount << " times" << ")" << std::endl;
    std::cout << "Most frequent letter, overall: " << mostFrequent << " (" << mostFrequentCount << " times" << ")" << std::endl;
}

int main(int argc, char* argv[])
{
    std::string inputString;
    std::vector<char> validInputChars;
   
    if(argc == 1){
        processInputFromCin(inputString);
    } else if (argc == 2){
        bool result = processInputFromFile(inputString, argv[1]);
        if(!result){
            return 1;
        }
    } else {
         std::cout << "cannot handle parameter list" << std::endl;
         return 1;
    }

    CreateValidVectorFromString(validInputChars, inputString);

    TransformCharVecToAllLower(validInputChars);

    std::vector<std::vector<int>> counterMatrix = GenerateCounterMatrix(validInputChars);

    FindAndPrintLetterStats(counterMatrix);
    
    return 0;
}