#include <iostream>

int dayInYear(int day, int month, int year);

int main( ){
    
    int testResult;
    std::cout << "Starting (13) Tests:" << std::endl;

    try{
        // None Leap Year Tests
        std::cout << "25/01/2023 expecting 25, got: ";
        testResult = dayInYear(25,1,2023);
        std::cout << testResult << std::endl;
        if (testResult != 25){
            throw std::runtime_error("Test 1 Failed: (none leap year test) 25/01/2023 expected 25, got: " + testResult);
        }

        std::cout << "31/12/2021 expecting 365, got: ";
        testResult = dayInYear(31,12,2021);
        std::cout << testResult << std::endl;
        if (testResult != 365){
            throw std::runtime_error("Test 2 Failed: (none leap year test) 31/12/2021 expected 365, got: " + testResult);
        }
        // Leap Year Tests
        std::cout << "29/02/2020 expecting 60, got: ";
        testResult = dayInYear(29,2,2020);
        std::cout << testResult << std::endl;
        if (testResult != 60){
            throw std::runtime_error("Test 3 Failed: (leap year test) 29/02/2020 expected 60, got: " + testResult);
        }

        std::cout << "31/12/2020 expecting 366, got: ";
        testResult = dayInYear(31,12,2020);
        std::cout << testResult << std::endl;
        if (testResult != 366){
            throw std::runtime_error("Test 4 Failed: (leap year test) 31/12/2020 expected 366, got: " + testResult);
        }
        // Edge Cases First Day 
        std::cout << "01/01/2021 expecting 1, got: ";
        testResult = dayInYear(1,1,2021);
        std::cout << testResult << std::endl;
        if (testResult != 1){
            throw std::runtime_error("Test 5 Failed: (leap year test) 01/01/2021 expected 1, got: " + testResult);
        }

        // Edge Cases Last Day
        std::cout << "31/12/2021 expecting 365, got: ";
        testResult = dayInYear(31,12,2021);
        std::cout << testResult << std::endl;
        if (testResult != 365){
            throw std::runtime_error("Test 6 Failed: (leap year test) 31/12/2021 expecting 365, got: " + testResult);
        }

        std::cout << "31/12/2020 expecting 366, got: ";
        testResult = dayInYear(31,12,2020);
        std::cout << testResult << std::endl;
        if (testResult != 366){
            throw std::runtime_error("Test 7 Failed: (leap year test) 31/12/2020 expecting 366, got: " + testResult);
        }
        // Transitions
         
        std::cout << "28/02/2021 expecting 59, got: ";
        testResult = dayInYear(28,2,2021);
        std::cout << testResult << std::endl;
        if (testResult != 59){
            throw std::runtime_error("Test 8 Failed: (leap year test) 28/02/2021 expecting 59, got: " + testResult);
        }

        std::cout << "28/02/2020 expecting 59, got: ";
        testResult = dayInYear(28,2,2020);
        std::cout << testResult << std::endl;
        if (testResult != 59){
            throw std::runtime_error("Test 8 Failed: (leap year test) 28/02/2020 expecting 59, got: " + testResult);
        }

        std::cout << "01/03/2020 expecting 61, got: ";
        testResult = dayInYear(01,3,2020);
        std::cout << testResult << std::endl;
        if (testResult != 61){
            throw std::runtime_error("Test 8 Failed: (leap year test) 01/03/2020 expecting 61, got: " + testResult);
        }

        // Invalid Date
        std::cout << "30/02/2021 expecting 61 got: ";
        testResult = dayInYear(30,2,2021);
        std::cout << testResult << std::endl;
        if (testResult != 61){
            throw std::runtime_error("Test 8 Failed: (leap year test) 01/03/2020 expecting 61, got: " + testResult);
        }

        std::cout << "31/04/2022 expecting 121, got: ";
        testResult = dayInYear(31,4,2022);
        std::cout << testResult << std::endl;
        if (testResult != 121){
            throw std::runtime_error("Test 8 Failed: (leap year test) 01/03/2020 expecting 61, got: " + testResult);
        }
  

        std::cout << "31/04/2022 expecting 121, got: " << dayInYear(31,4,2022) << std::endl;
        std::cout << "31/04/2022 expecting 121, got: ";
        testResult = dayInYear(31,4,2022);
        std::cout << testResult << std::endl;
        if (testResult != 121){
            throw std::runtime_error("Test 8 Failed: (leap year test) 31/04/2022 expecting 121, got: " + testResult);
        }

        // Out of range
        
        testResult = dayInYear(15,13,2023);
        std::cout << testResult << std::endl;
        if (testResult != 380){
            throw std::runtime_error("Test 8 Failed: (leap year test) 31/04/2022 expecting 121, got: " + testResult);
        }

        testResult =  dayInYear(0,12,2023);
        std::cout << testResult << std::endl;
        if (testResult != 334){
            throw std::runtime_error("Test 8 Failed: (leap year test) 31/04/2022 expecting 121, got: " + testResult);
        }
        
        testResult =  dayInYear(1,12,0000);
        std::cout << testResult << std::endl;
        if (testResult != 336){
            throw std::runtime_error("Test 8 Failed: (leap year test) 31/04/2022 expecting 121, got: " + testResult);
        }

        testResult =  dayInYear(1,00,2000);
        std::cout << testResult << std::endl;
        if (testResult != 1){
            throw std::runtime_error("Test 8 Failed: (leap year test) 31/04/2022 expecting 121, got: " + testResult);
        }

        testResult =  dayInYear(-1,12,2000);
        std::cout << testResult << std::endl;
        if (testResult != 334){
            throw std::runtime_error("Test 8 Failed: (leap year test) 31/04/2022 expecting 121, got: " + testResult);
        }

           testResult =  dayInYear(-1,-12,-2000);
        std::cout << testResult << std::endl;
        if (testResult != -1){
            throw std::runtime_error("Test 8 Failed: (leap year test) 31/04/2022 expecting 121, got: " + testResult);
        }
        

    


    } catch (std::runtime_error& error){
        std::cout << error.what() << std::endl;
        return 1;
    } 


    return 0;
}