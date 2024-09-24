#include <vector>

bool binarySearch(const std::vector<std::string>& v, int minIndex, int maxIndex, std::string& searchValue)
{
    if (minIndex > maxIndex){
        return false;
    }
    
    int middleIndex = (maxIndex + minIndex) / 2;
    
    if(searchValue == v.at(middleIndex)){
        return true;
    } else {
        if( searchValue > v.at(middleIndex) ){
            binarySearch(v, middleIndex + 1, maxIndex, searchValue);
        } else {
            binarySearch(v, minIndex, middleIndex - 1, searchValue);
        }
    }
}

bool binarySearch(const std::vector<int>& v, int minIndex, int maxIndex, int& searchValue)
{
    if (minIndex > maxIndex){
        return false;
    }
    
    int middleIndex = (maxIndex + minIndex) / 2;
    
    if(searchValue == v.at(middleIndex)){
        return true;
    } else {
        if( searchValue > v.at(middleIndex) ){
            binarySearch(v, middleIndex + 1, maxIndex, searchValue);
        } else {
            binarySearch(v, minIndex, middleIndex - 1, searchValue);
        }
    }
}

bool binarySearch(const std::vector<double>& v, int minIndex, int maxIndex, double& searchValue)
{
    if (minIndex > maxIndex){
        return false;
    }
    
    int middleIndex = (maxIndex + minIndex) / 2;
    
    if(searchValue == v.at(middleIndex)){
        return true;
    } else {
        if( searchValue > v.at(middleIndex) ){
            binarySearch(v, middleIndex + 1, maxIndex, searchValue);
        } else {
            binarySearch(v, minIndex, middleIndex - 1, searchValue);
        }
    }
}
