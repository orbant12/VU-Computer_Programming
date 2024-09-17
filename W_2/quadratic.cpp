#include <iostream>
#include <cmath>


double calcDiscriminant(double aVal, double bVal, double cVal){
    
    return pow(bVal, 2) - (4 * aVal * cVal);;
}

int evaluateSolutions(double disc){
    if (disc > 0)
        return 2; 
    else if (disc == 0)
        return 1; 
    else
        return 0; 
}

void computeResults(double aVal, double bVal, double disc) {
    if (disc > 0) {
        double x_1 = (-bVal + sqrt(disc)) / (2 * aVal);
        double x_2 = (-bVal - sqrt(disc)) / (2 * aVal);
        std::cout << "There are 2 solutions." << std::endl;
        std::cout << std::endl;
        std::cout << "The solutions are: " << x_1 << " and " << x_2 << std::endl;
    }
    else if (disc == 0) {
        double x = -bVal / (2 * aVal);
        std::cout << "There is 1 solution." << std::endl;
        std::cout << std::endl;
        std::cout << "The solution is: " << x << std::endl;
    }
    else {
        std::cout << "There is no solution." << std::endl;
    }
}

int main() {

    double aVal, bVal, cVal;

    std::cout << "Please enter the values of a, b, and c: ";
    std::cin >> aVal >> bVal >> cVal;
    
    double disc = calcDiscriminant(aVal, bVal, cVal);

    int nOfSolution = evaluateSolutions(disc);

    computeResults(aVal, bVal, disc);

    return 0;
}