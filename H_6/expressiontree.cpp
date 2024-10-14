#include <iostream>
#include <stack>

class Token{
    public:
        bool isOperator;
        char op;
        double value;
};

Token getToken(){
    double val;
    Token retVal;
    std::string rawToken;
    std::cin >> rawToken;

    if ( std::cin.fail() ) throw std::runtime_error("end of file");
    try{
        retVal.value = std::stod(rawToken);
        retVal.isOperator = false;
        return retVal;
    }catch (std::invalid_argument& e){
        // no number, but something else
    }
    if ( rawToken.size() == 0 ){
        retVal.op = 'X';
        return retVal;
    }
    if ( rawToken.size() > 1 ){
        throw std::runtime_error("invalid token");
    }
    char op = rawToken.at(0);
    switch (op){
        case '+':
        case '-':
        case '*':
        case '/':
            retVal.isOperator = true;
            retVal.op = op;
            return retVal;
        default:
            throw std::runtime_error("invalid token");
    }
    return retVal; // never reached
}

std::stack<Token> readFromCin()
{
    std::stack<Token> result;
    bool keepReading = true;
    while ( keepReading ){
        try { 
            Token t = getToken();
            result.push(t);
        }
        catch (...){
            keepReading = false;
        }
    }
    return result;
}

#include "expressiontree.cpp"

int main()
{
    std::stack<Token> tokenStack = readFromCin();
    TreeNode* tree = buildFromTokenStack(tokenStack);
    printTree(tree);
    std::cout << "= " << evaluate(tree) << '\n';
    delete tree;
    return 0;
}