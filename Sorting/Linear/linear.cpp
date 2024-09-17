#include <iostream>
#include <vector>

int findSmallestMissingNumber(const std::vector<int>& v) {
    // Step 1: Find the minimum and maximum values in the input vector
    int minVal = v[0];
    int maxVal = v[0];
    for (int num : v) {
        if (num < minVal) {
            minVal = num;
        }
        if (num > maxVal) {
            maxVal = num;
        }
    }

    // Step 2: Create a tracker vector to track numbers from minVal to maxVal
    int range = maxVal - minVal + 1;
    std::vector<bool> tracker(range, false); // Track numbers between minVal and maxVal

    // Step 3: Mark the numbers in the tracker
    for (int num : v) {
        if (num >= minVal && num <= maxVal) {
            tracker[num - minVal] = true;  // Mark that the number is present
        }
    }

    for (int i = 0; i < tracker.size(); ++i) {
        std::cout << tracker[i] << ", ";
    }
    std::cout << std::endl;
    int math = (maxVal + 1) - tracker.size();
    std::cout << math << std::endl;

    // Step 4: Find the first missing number in the tracker larger than minVal
    for (int i = 0; i < tracker.size(); ++i) {
        if (tracker[i] == false) {
            return minVal + i;  // Return the smallest missing number
        }
    }

    // If no missing number is found, return the next number after the maxVal
    return maxVal + 1;
}

int main() {
    int vectorSize;
    std::cout << "How many numbers? ";
    std::cin >> vectorSize;

    std::vector<int> inputVector(vectorSize);
    std::cout << "Please enter the numbers: ";

    for (int i = 0; i < vectorSize; ++i) {
        std::cin >> inputVector[i];
    }

    int smallestMissing = findSmallestMissingNumber(inputVector);
    std::cout << "The smallest missing number is " << smallestMissing << std::endl;

    return 0;
}
