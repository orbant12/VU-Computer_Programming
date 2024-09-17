#include <iostream>
#include <vector>

std::vector<int> partialSums(std::vector<int> v){
    std::vector<int> outV;
    int sum = 0;

    for (int i = 0; i < v.size(); ++i){
            sum += v[i];
            outV.push_back(sum);
    }
    return outV;
}

void printVector(std::vector<int>& v) {
    if(v.size() != 0){
        for (int i = 0; i < v.size(); ++i){
            if(i != v.size() - 1){
                std::cout << v[i] << ", ";
            } else {
                std::cout << v[i] << std::endl;
            }
        }
    } else {
        std::cout << "" << std::endl;
    }
}

int secondSmallestOrElse42(std::vector<int> v) {
    bool noSec = true;

    if(v.size() != 0){

        int min = v[0];

        for (int i = 0; i < v.size(); ++i){
            if(v[i] < min){
                min = v[i];
            }     
        }

        int secSmallest = v[0] == min ? v[1] : v[0];
        
        for (int i = 0; i < v.size(); ++i){
            if(( v[i] < secSmallest ) && (v[i] > min) ){
                secSmallest = v[i];
                noSec = false;
            } else if ((min != secSmallest) && (secSmallest == v[i])){
                noSec = false;
            }
        }

        if(noSec == false){
            return secSmallest;
        }
    } 
    return 42;
}

int main()
{
    std::vector<int> inputNumbers;
    std::cout << "Please enter some numbers (q to quit)\n";
    do{
        int nextNumber;
        std::cin >> nextNumber;
        if ( std::cin.good() ){
            inputNumbers.push_back(nextNumber);
        }
    } while ( std::cin.good() );

    std::vector<int> partials = partialSums(inputNumbers);
    printVector(partials);
    std::cout << "The second smallest partial sum is " << secondSmallestOrElse42(partials) << std::endl;

    return 0;
}