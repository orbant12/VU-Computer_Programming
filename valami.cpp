#include <iostream>
#include <vector>
using namespace std;


int main(){

    char valamiV; 
    vector<char> v;
    

    do {
        cin >> valamiV;
        v.push_back(valamiV);
    } while (!cin.fail());

    for(char ch : v){
        cout << ch << endl;
    }
    return 0;
}