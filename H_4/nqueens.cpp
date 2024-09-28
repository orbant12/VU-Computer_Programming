#include <iostream>
#include <vector>

bool behindColTest(const int N, const std::vector< std::vector<bool> >& board, int row, unsigned int column)
{    
    for (int j = 0; j < row; ++j){
        bool currVal = board.at(j).at(column);
        if(currVal){
            return false;
        }
    }

    return true;
}

bool behindRightSideTest(const int N, const std::vector< std::vector<bool> >& board, int row, unsigned int column)
{
    for (int j = row; j >= 0; --j){
        bool currVal = board.at(j).at(column);
        if(currVal){
            return false;
        }
        if(column < N){
            ++column;
        }else {
            break;
        }
    }

    return true;
}


bool behindLeftSideTest(const int N, const std::vector< std::vector<bool> >& board, int row, unsigned int column)
{
    for (int j = row; j >= 0; --j){
        bool currVal = board.at(j).at(column);
        if(currVal){
            return false;
        }
        if(column > 0){
            --column;
        }else {
            break;
        }
    }

    return true;
}

bool placeQueens(int N, std::vector < std::vector <bool> >& board, int row)
{
    unsigned int column;

    if(row == N){
        return true;
    }

    for (column = 0; column < N; ++column){
        bool behindTestResult = behindColTest(N, board, row, column);
        bool leftTestResult = behindLeftSideTest(N, board, row, column);
        bool rightTestResult = behindRightSideTest(N, board, row, column);

        if(behindTestResult && leftTestResult && rightTestResult){
            board.at(row).at(column) = true;
            bool response = placeQueens(N, board, row + 1);
            if(response){
                return true;
            }
            // Backtracking if fails
            board.at(row).at(column) = false;
        }
    }

    return false;
}

void createChessBoard(std::vector< std::vector<bool> >& chessBoard, const int& nQueens)
{
  for (int i = 0; i < (nQueens * nQueens); ++i) {
        std::vector<bool> chessRow(nQueens * nQueens,false);
        chessBoard.push_back(chessRow);
    }
}

void printResult(const bool& placingResponse, const int& nQueens, const std::vector< std::vector<bool> >& chessBoard)
{
    if (!placingResponse) {
        std::cout << "No solution found to place " << nQueens << " queens on a " << nQueens << " by " << nQueens << " chess board" << std::endl;
    } else {
        for (int i = 0; i < nQueens; ++i) {
            for (int j = 0; j < nQueens; ++j) {
                char transformed = chessBoard.at(i).at(j) ? 'Q' : '.';
                std::cout << transformed;
            }
            std::cout << std::endl;
        }
    }
}

int main() 
{
    int nQueens;
    std::cout << "How many queens to place on the board?" << std::endl;
    std::cin >> nQueens;
    std::vector< std::vector<bool> > chessBoard;

    if( !(nQueens > 0) ){
        std::cout << "error: invalid input";
        return 0;
    }

    createChessBoard(chessBoard, nQueens);

    bool placingResponse = placeQueens(nQueens, chessBoard, 0);

    printResult(placingResponse, nQueens, chessBoard);

    return 0;
}