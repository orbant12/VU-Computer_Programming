#include <vector>
#include <iostream>

bool binarySearch(const std::vector<int>& v,int min, int max, const int& s){

    if(min > max){
        return false;
    }

    int midd = (max + min) / 2;

    if(v.at(midd) == s){
        return true;
    } else {
        if(v.at(midd) > s){
            bool r = binarySearch(v, min, midd - 1, s);
            if(r){
                return true;
            }
        } else {
            bool r = binarySearch(v, midd + 1, max, s);
            if(r){
                return true;
            }
        }
    }
}

int main(int argc, char* argv[]){

    std::vector<int> v;

    v.push_back(4);
    v.push_back(10);
    v.push_back(20);
    v.push_back(22);
    v.push_back(26);
    v.push_back(35);
    v.push_back(39);
    v.push_back(40);
    v.push_back(55);
    v.push_back(80);

    int input = std::atoi(argv[1]);

    bool r = binarySearch(v,0,v.size() - 1, input);

    if(r){
        std::cout << input << " found" << std::endl;
    } else {
        std::cout << input <<  " not" << std::endl;
    }

    return 0;
}