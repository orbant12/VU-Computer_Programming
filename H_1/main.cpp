#include <iostream>


int main(){

    char operatorInput;
    double num1, num2;
    double endValue;

    while (true) {
        
        // Operator input
        std::cout << "Enter the expression: ";
        std::cin >> operatorInput;

        // Check if user want to quit
        if (operatorInput == 'q') {
            break;
        }

        // Number inputs
        std::cin >> num1 >> num2;

        switch (operatorInput) {     
            case '+':
                endValue = num1 + num2;
                std::cout << num1 << " + " << num2 << " = " << endValue << std::endl;
                break;
            case '-':
                endValue = num1 - num2;
                std::cout << num1 << " - " << num2 << " = " << endValue << std::endl;
                break;
            case '*':
                endValue = num1 * num2;
                std::cout << num1 << " * " << num2 << " = " << endValue << std::endl;
                break;
            case '/':
                if (num2 != 0) {
                    endValue = num1 / num2;
                    std::cout << num1 << " / " << num2 << " = " << endValue << std::endl;
                } else {
                    std::cout << "Division by 0 is NaN." << std::endl;
                }
                break;
            default:
                break;
        };

    }

    return 0;
}