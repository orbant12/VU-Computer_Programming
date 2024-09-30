#include <stack>
#include <iostream>

template<typename T>
void storedToSorted(std::stack<T>& s, T num) {
    if (s.empty() || s.top() >= num) {  // Changed <= to >=
        s.push(num);
        return;
    }
    
    T top = s.top();
    s.pop();
    
    storedToSorted(s, num);
    s.push(top);
}

template<typename T>
void sortAStack(std::stack<T>& s) {
    if (s.size() < 2) {
        return;
    }
    
    T top = s.top();
    s.pop();
    
    sortAStack(s);
    storedToSorted(s, top);
}

// Helper function to print a stack
template<typename T>
void printStack(std::stack<T> s) {
    std::stack<T> temp;
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> s;
    s.push(0);
    s.push(-3);
    s.push(42);
    
    std::cout << "Original stack: ";
    printStack(s);
    
    sortAStack(s);
    
    std::cout << "Sorted stack: ";
    printStack(s);
    
    return 0;
}