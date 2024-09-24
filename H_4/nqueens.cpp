#include <iostream>
#include <vector>

bool behindColTest(const int N, const std::vector< std::vector<bool> >& board, int row, unsigned int i)
{    
    for (int j = 0; j < row; ++j){
        bool currVal = board.at(j).at(i);
        if(currVal){
            return false;
        }
    }

    return true;
}

bool behindRightSideTest(const int N, const std::vector< std::vector<bool> >& board, int row, unsigned int i)
{
    for (int j = row; j >= 0; --j){
        bool currVal = board.at(j).at(i);
        if(currVal){
            return false;
        }
        if(i < N){
            ++i;
        }else {
            break;
        }
    }

    return true;
}


bool behindLeftSideTest(const int N, const std::vector< std::vector<bool> >& board, int row, unsigned int i)
{
    for (int j = row; j >= 0; --j){
        bool currVal = board.at(j).at(i);
        if(currVal){
            return false;
        }
        if(i > 0){
            --i;
        }else {
            break;
        }
    }

    return true;
}

bool placeQueens(int N, std::vector < std::vector <bool> >& board, int row){
    unsigned int i; // column

    if(row == N){
        return true;
    }

    for (i = 0; i < N; ++i){
        bool behindTestResult = behindColTest(N, board, row, i);
        bool leftTestResult = behindLeftSideTest(N, board, row, i);
        bool rightTestResult = behindRightSideTest(N, board, row, i);

        if(behindTestResult && leftTestResult && rightTestResult){
            board.at(row).at(i) = true;
            bool response = placeQueens(N, board, row + 1);
            if(response){
                return true;
            }
            // Backtracking if fails
            board.at(row).at(i) = false;
        }
    }

    return false;
}

int main() {

    int nQueens;
    std::cout << "How many queens to place on the board?" << std::endl;
    std::cin >> nQueens;

    if( !(nQueens > 0) ){
        std::cout << "error: invalid input";
        return 0;
    }

    std::vector< std::vector<bool> > chessBoard;

    for (int i = 0; i < (nQueens * nQueens); ++i){
        std::vector<bool> chessRow(nQueens * nQueens,false);
        chessBoard.push_back(chessRow);
    }

    bool res = placeQueens(nQueens, chessBoard, 0);

    if (!res) {
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

    return 0;
}