#include <vector>

template <typename T>
bool binarySearch(const std::vector<T>& v, int minIndex, int maxIndex, T& searchValue)
{
    if (minIndex > maxIndex) {
        return false;
    }

    int middleIndex = (maxIndex + minIndex) / 2;

    if (searchValue == v.at(middleIndex)) {
        return true;
    } else {
        if (searchValue > v.at(middleIndex)) {
            return binarySearch(v, middleIndex + 1, maxIndex, searchValue);
        } else {
            return binarySearch(v, minIndex, middleIndex - 1, searchValue);
        }
    }
}

int main() {
    // Test with int
    std::vector<int> intVec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int intSearchValue = 5;
    bool intResult = binarySearch(intVec, 0, intVec.size() - 1, intSearchValue);
    
    // Test with double
    std::vector<double> doubleVec = {1.1, 2.2, 3.3, 4.4, 5.5};
    double doubleSearchValue = 3.3;
    bool doubleResult = binarySearch(doubleVec, 0, doubleVec.size() - 1, doubleSearchValue);
    
    // Test with string
    std::vector<std::string> stringVec = {"apple", "banana", "cherry", "date", "fig"};
    std::string stringSearchValue = "cherry";
    bool stringResult = binarySearch(stringVec, 0, stringVec.size() - 1, stringSearchValue);

    return 0;
}
