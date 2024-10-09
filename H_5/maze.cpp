#include <stack>
#include <vector>

const int POSITION_X = 0;
const int POSITION_Y = 1;

class Coordinate {
public:
    Coordinate(int x, int y);
    int at(const int& index) const { return coordinate.at(index); }
    void setBottomConnect(const bool& val) { connectToBottom = val; }
    void setRightConnect(const bool& val) { connectToRight = val; }
    void setTopConnect(const bool& val) { connectToTop = val; }
    void setLeftConnect(const bool& val) { connectToLeft = val; }

    bool getConnectRight() const { return connectToRight; }
    bool getConnectBottom() const { return connectToBottom; }
    bool getConnectTop() const { return connectToTop; }
    bool getConnectLeft() const { return connectToLeft; }

    bool getVisited() const { return isVisited; }
    void setVisited(const bool& val) { isVisited = val; }
    bool getPartOf() const { return partOfPath; }
    void setPartOf(const bool& val) { partOfPath = val; }

private:
    std::vector<int> coordinate;
    bool connectToTop = false;
    bool connectToBottom = false;
    bool connectToRight = false;
    bool connectToLeft = false;
    bool isVisited = false;
    bool partOfPath = false;
};

Coordinate::Coordinate(int x, int y)
{
    coordinate.push_back(x);
    coordinate.push_back(y);
}

// your class Maze must implement the public: interface shown here (or it won't compile)
// the private: part of the class is completely up to you
class Maze {
public:
    Maze(int rows, int columns);

    void generate();
    // generates the maze for the given size (rows and columns) using the recursive backtracker algorithm
    // explained in the video linked to on Canvas

    bool findPath(Coordinate from, Coordinate to);
    // finds a path from the coordinate (0,0) (top left corner) to the coordinate (rows-1,columns-1) (bottom right corner)
    // using the algorithm explained on Canvas

    // the following five functions return basic information about the maze, allowing it to be printed
    // the latter three bool functions only need to work after both the maze has been created and the path has been found
    int getColumns();
    int getRows();
    bool hasConnectionToTheRightNeighbour(int row, int column);
    // returns whether the wall in between (row,column) and (row,column+1) has been removed
    bool hasConnectionToTheBottomNeighbour(int row, int column);
    // returns whether the wall in between (row,column) and (row+1,column) has been removed
    bool isPartOfPath(int row, int column);
    // returns whether (row,column) is on the path from the top-left to the bottom-right corner

private:
    int rows;
    int columns;
    std::stack<std::vector<int> > mazeStack;
    std::vector<std::vector<Coordinate> > maze;
    void generateMazeCoordinates();

    std::vector<std::vector<int> > generateOptions(int& row, int& col);
    void removeSide(int& currX, int& currY, int& newX, int& newY);
    std::vector<Coordinate> createConnectionsVector(int& fromX, int& fromY);
};

Maze::Maze(int rows, int columns){
    this-> rows = rows;
    this-> columns = columns;
    generateMazeCoordinates();
}

void Maze::generateMazeCoordinates() {
    for (int x = 0; x < this-> rows; ++x) {
        std::vector<Coordinate> row;
        for (int y = 0; y < this-> columns; ++y) {
            row.push_back(Coordinate(x, y));
        }
        maze.push_back(row);
    }
}

std::vector<std::vector<int> > Maze::generateOptions(int& row, int& col) {
    std::vector<std::vector<int> > options;

    if (row - 1 >= 0 && !maze.at(row - 1).at(col).getVisited()) {
        std::vector<int> currPositonV = {row - 1, col};
        options.push_back(currPositonV);
    }
    
    if (col - 1 >= 0 && !maze.at(row).at(col - 1).getVisited()) {
        std::vector<int> currPositonV = {row, col - 1};
        options.push_back(currPositonV);
    }
    
    if (row + 1 < this -> rows && !maze.at(row + 1).at(col).getVisited()) {
        std::vector<int> currPositonV = {row + 1, col};
        options.push_back(currPositonV);
    }
    
    if (col + 1 < this -> columns && !maze.at(row).at(col + 1).getVisited()) {
        std::vector<int> currPositonV = {row, col + 1};
        options.push_back(currPositonV);
    }

    return options;
}

void Maze::removeSide(int& currX, int& currY, int& newX, int& newY) 
{    
    if (newX == currX - 1 && newY == currY) { 
        maze.at(currX).at(currY).setTopConnect(true);
        maze.at(newX).at(newY).setBottomConnect(true);
    } else if (newX == currX + 1 && newY == currY) { 
        maze.at(currX).at(currY).setBottomConnect(true);
        maze.at(newX).at(newY).setTopConnect(true);
    } else if (newX == currX && newY == currY - 1) { 
        maze.at(currX).at(currY).setLeftConnect(true);
        maze.at(newX).at(newY).setRightConnect(true);
    } else if (newX == currX && newY == currY + 1) { 
        maze.at(currX).at(currY).setRightConnect(true);
        maze.at(newX).at(newY).setLeftConnect(true);
    }
}

void Maze::generate() 
{
    maze.at(0).at(0).setVisited(true);
    std::vector<int> startPos = {0, 0};
    mazeStack.push(startPos);

    while (!mazeStack.empty()) {

        std::vector<int> currPos = mazeStack.top();
        int currX = currPos.at(POSITION_X);
        int currY = currPos.at(POSITION_Y);
        
        std::vector<std::vector<int> > options = generateOptions(currX, currY);

        if (!options.size() == 0 /* All options are exhausted */) {
            
            int randIndex = rand() % options.size();

            std::vector<int> nextPos = options.at(randIndex);
            int newX = nextPos.at(POSITION_X);
            int newY = nextPos.at(POSITION_Y);

            removeSide(currX, currY, newX, newY);

            maze.at(newX).at(newY).setVisited(true);
            mazeStack.push(nextPos);
        } else {
            /* 
            [ Backtracking ]
                Desc: It will exhaust each possible Coordinate Object's possibleOptions while 
                1.) breaking down walls in connection -> removeSide() , 
                2.) Setting each Coordinate Object's Visited with -> .setVisited() method, 
                3.) And exhaust their individual options generateOptions && options.size() for Logic
            */
            mazeStack.pop();
        }
    }
}

std::vector<Coordinate> Maze::createConnectionsVector(int& fromX, int& fromY)
{
     std::vector<Coordinate> options;

    if (maze.at(fromX).at(fromY).getConnectTop() && fromX - 1 >= 0) {
        options.push_back(maze.at(fromX - 1).at(fromY));
    }

    if (maze.at(fromX).at(fromY).getConnectRight() && fromY + 1 < this-> columns) {
        options.push_back(maze.at(fromX).at(fromY + 1));
    }

    if (maze.at(fromX).at(fromY).getConnectBottom() && fromX + 1 < this-> rows) {
        options.push_back(maze.at(fromX + 1).at(fromY));
    }
    
    if (maze.at(fromX).at(fromY).getConnectLeft() && fromY - 1 >= 0) {
        options.push_back(maze.at(fromX).at(fromY - 1));
    }

    return options;
}

bool Maze::findPath(Coordinate from, Coordinate to)
{
    int fromX = from.at(POSITION_X);
    int fromY = from.at(POSITION_Y);

    if(fromX == 0 && fromY == 0){
        for (int row = 0; row < this-> rows; ++row) {
            for (int col = 0; col < this-> columns; ++col) {
                maze.at(row).at(col).setVisited(false);
                maze.at(row).at(col).setPartOf(false);
            }
        }
    }
 
    maze.at(fromX).at(fromY).setVisited(true);
 
    if (fromX == to.at(POSITION_X) && fromY == to.at(POSITION_Y)) {
        maze.at(fromX).at(fromY).setPartOf(true);
        return true;
    }

    std::vector<Coordinate> options = createConnectionsVector(fromX, fromY);

    for (int i = 0; i < options.size(); ++i) {
        Coordinate newCoor = options.at(i);
        int newX = newCoor.at(POSITION_X);
        int newY = newCoor.at(POSITION_Y);

        if (!maze.at(newX).at(newY).getVisited()) {
            if (findPath(newCoor, to)) {
                maze.at(fromX).at(fromY).setPartOf(true);
                return true;
            }
        }
    }

    maze.at(fromX).at(fromY).setVisited(false);
    return false;
}


int Maze::getColumns() 
{
    return this-> columns;
}

int Maze::getRows() 
{
    return this-> rows;
}

bool Maze::hasConnectionToTheRightNeighbour(int row, int col) 
{
    return maze.at(row).at(col).getConnectRight();
}

bool Maze::hasConnectionToTheBottomNeighbour(int row, int col) 
{
    return maze.at(row).at(col).getConnectBottom();
}

bool Maze::isPartOfPath(int row, int col) 
{
    return maze.at(row).at(col).getPartOf();
}











