#include <iostream>
#include <cstdlib>

int main()
{
    // do NOT change MIN or MAX, otherwise the tests will fail!
    const int MIN = 1;
    const int MAX = 100;

    srand(time(0));
    int secretNumber = rand() % 101;

    int nextGuess;
    bool hasBeenGuessed = false;

    std::cout << "Guess a number in between " << MIN << " and " << MAX << std::endl;

    do {
        std::cin >> nextGuess;
        if ( nextGuess == secretNumber ){
            std::cout << "You made it!" << std::endl;
            hasBeenGuessed = true;
        }else{
            if ( nextGuess < secretNumber ){
                std::cout << "Too small!" << std::endl;
            }else{
                std::cout << "Too big!" << std::endl;
            }
        }
    }
    while ( !hasBeenGuessed );
    

    return 0;
}