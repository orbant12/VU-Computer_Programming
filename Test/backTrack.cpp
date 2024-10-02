#include <vector>
#include <iostream>

bool recBack(const std::vector<int>& v, int s, int sum, int iter){
    
    if(sum == s){
        return true;
    }

    for(int i = iter;i < v.size(); ++i){
        sum += v.at(i);

        if(sum < s){
            recBack(v, s, sum + v.at(i), i);
        } else {
            recBack(v, s, sum, iter);
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

    bool res = recBack(v, input, 0, 0);

    return 0;
}