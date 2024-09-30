// implement your function here!
#include <stack>
#include <iostream>


template<typename T>
void storedToSorted(std::stack<T>& s, T num) {
    
    if (s.empty() || s.top() >= num) {
        s.push(num);
        return;
    }
    
    T top = s.top();
    s.pop();
    
    storedToSorted(s, num);
    s.push(top);
}

template<typename T>
void sortAStack(std::stack<T>& s)
{
    
    if(s.size() < 2){
        return;
    } 

    T top = s.top();
    s.pop();

    sortAStack(s);

    storedToSorted(s, top);
}
