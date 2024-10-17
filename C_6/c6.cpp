#include <iostream>

void doSomethingWith(int n){

}

int main(){

// STREAMS IN A BOOLEAN CONTEXT
// 1.) Streams in cpp can be used in boolean contexts because they have an overloaded conversion operator that allows them to be evaluated in conditions.
// 2.) Base Class for streams : std::basic_ios -> operator void*() or operator bool()

// BOOLEAN CONTEXT

// Checking the state of the stream.
// 1 = no errors have occurred
// 0 = false other wise
// This means the loop will continue as long as the stream is ready for input and no errors have been encountered.

    int number;
    while ( std::cin ) {
        std::cin >> number;
        if ( std::cin.good() ){
            doSomethingWith(number);
        }
    }

// =========================================================================================================
// The std::cin >> number Expression in a Boolean Context
// Checking whether the input operation was successful
// If reading into number succeeds, the stream remains in a good state, and the loop continues.

    int number;
    while ( std::cin >> number ) {
        doSomethingWith(number);
    }

    return 0;
}


//The std::cin >> number Expression in a Boolean Context


// How It Works Under the Hood
//The stream classes overload the conversion to bool
//Purpose of operator void*()


/* 
Characteristics of void*:

Type Agnostic: A void* can hold the address of any data type (e.g., int, double, char, user-defined types).
Cannot Be Dereferenced Directly: Since void does not specify a data type, you cannot access the value pointed to by a void* without first casting it to a pointer of a specific type.
Used for Generic Programming: void* pointers are often used in scenarios where functions need to handle data of various types, similar to generic programming.

*/
