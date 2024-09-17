#include <iostream>
#include <vector>

// Unsorted vector
// find the lowest value missung  
// that is larger than the smallest which present

int findSmallestMissingNumber(std::vector<int> v) {
    
    int minVal = v[0];
    int maxVal = v[0];

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] < minVal) {
            minVal = v[i];
        }
        if (v[i] > maxVal) {
            maxVal = v[i];
        }
    }

    int range = maxVal - minVal + 1;

    std::vector<bool> tracker(range, false); 
    
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] >= minVal && v[i] <= maxVal) {
            tracker[v[i] - minVal] = true;
        }
    }

    for (int i = 1; i < tracker.size(); ++i) {
        if (tracker[i] == false) {
            return minVal + i;
        }
    }
    return maxVal + 1;
}

int main(){
    int vectorSize;
    std::cout << "How many numbers? ";
    std::cin >> vectorSize;

    std::vector<int> inputVector(vectorSize);
    std::cout << "Please enter the numbers ";

    for ( int i=0; i<vectorSize; i++){
        std::cin >> inputVector.at(i);
    }

    const int smallestMissing = findSmallestMissingNumber(inputVector);
    std::cout << "The smallest missing number is " << smallestMissing << std::endl;

    return 0;
}