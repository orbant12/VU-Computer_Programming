// #include <stack>
// #include <vector>
// #include <iostream>
// // please implement all your classes in this file

// const int POSITION_X = 0;
// const int POSITION_Y = 1;

// class Coordinate {
//     public:
//         Coordinate(int x, int y);
//         int at(int index) const { return coordinate.at(index); };
//         void addConnection(const Coordinate& coor) { connections.push_back(coor); }
//         bool hasBottomConnection() const;
//         bool hasRightConnection() const;
//     private:
//         std::vector<int> coordinate;
//         std::vector<Coordinate> connections;
// };

// bool Coordinate::hasBottomConnection() const 
// {
//     for (int i = 0; i < connections.size();  ++i){
//         if(( connections.at(i).at(POSITION_Y) + 1 == (coordinate.at(POSITION_Y))) && ( connections.at(i).at(POSITION_X) == coordinate.at(POSITION_X)) )
//         {
//             return true;
//         }
//     }
//     return false;
// }

// bool Coordinate::hasRightConnection() const 
// {
//     for (int i = 0; i < connections.size();  ++i){
//         if(( connections.at(i).at(POSITION_Y) == (coordinate.at(POSITION_Y))) && ((connections.at(i).at(POSITION_X)) == coordinate.at(POSITION_X) +  1) )
//         {
//             return true;
//         }
//     }
//     return false;
// }

// Coordinate::Coordinate(int x, int y){
//     coordinate.push_back(x);
//     coordinate.push_back(y);
// };

// // your class Maze must implement the public: interface shown here (or it won't compile)
// // the private: part of the class is completely up to you
// class Maze{
//     public:
//         Maze(int rows, int columns);

//         void generate();
//         // generates the maze for the given size (rows and columns) using the recursive backtracker algorithm
//         // explained in the video linked to on Canvas

//         bool findPath(Coordinate from, Coordinate to);
//         // finds a path from the coordinate (0,0) (top left corner) to the coordinate (rows-1,columns-1) (bottom right corner)
//         // using the algorithm explained on Canvas

//         // the following five functions return basic information about the maze, allowing it to be printed
//         // the latter three bool functions only need to work after both the maze has been created and the path has been found
//         int getColumns();
//         int getRows();
//         bool hasConnectionToTheRightNeighbour(int row, int column);
//         // returns whether the wall in between (row,column) and (row,column+1) has been removed
//         bool hasConnectionToTheBottomNeighbour(int row, int column);
//         // returns whether the wall in between (row,column) and (row+1,column) has been removed
//         bool isPartOfPath(int row, int column);
//         // returns whether (row,column) is on the path from the top-left to the bottom-right corner

//     private:
//         int rows;
//         int columns;
//         std::stack<Coordinate> mazeStack;
//         std::vector<std::vector<Coordinate>> maze;
//         std::vector<Coordinate> visitedTracker;
//         std::vector<Coordinate> randomChoice ( Coordinate coor);
//         bool checkIfVisited (Coordinate coor);
//         bool recursiveBacktracking (Coordinate coor);
// };

// bool Maze::checkIfVisited (Coordinate coor) {
//     for(int i = 0; i < visitedTracker.size(); ++i){
//         if( (visitedTracker.at(i).at(POSITION_X) == coor.at(POSITION_X)) && (visitedTracker.at(i).at(POSITION_Y) == coor.at(POSITION_Y)) ) {
//             return true;
//         }
//     }

//     return false;
// }

// std::vector<Coordinate> Maze::randomChoice ( Coordinate coor ){
//     std::vector<Coordinate> options;

//     if(coor.at(POSITION_X) - 1 >= 0){
//         Coordinate currCoor(coor.at(POSITION_X) - 1,coor.at(POSITION_Y));
//         bool checkResult = checkIfVisited(currCoor);
//         if(!checkResult){
//             options.push_back(currCoor);
//         }
//     }

//     if(coor.at(POSITION_Y) - 1 >= 0){
//         Coordinate currCoor(coor.at(POSITION_X),coor.at(POSITION_Y) - 1);
//         bool checkResult = checkIfVisited(currCoor);
//         if(!checkResult){
//             options.push_back(currCoor);
//         }
//     } 

//     if(coor.at(POSITION_X) + 1  < rows){
//         Coordinate currCoor(coor.at(POSITION_X) + 1,coor.at(POSITION_Y));
//         bool checkResult = checkIfVisited(currCoor);
//         if(!checkResult){
//             options.push_back(currCoor);
//         }
//     }

//     if(coor.at(POSITION_Y) + 1 < columns){
//         Coordinate currCoor(coor.at(POSITION_X),coor.at(POSITION_Y) + 1);
//         bool checkResult = checkIfVisited(currCoor);
//         if(!checkResult){
//             options.push_back(currCoor);
//         }
//     } 

//     return options;
// }

// Maze::Maze(int r, int c) : rows(r), columns(c) {
//     for (int i = 0; i < rows; ++i) {
//         std::vector<Coordinate> row;
//         for (int j = 0; j < columns; ++j) {
//             row.emplace_back(j, i);
//         }
//         maze.push_back(row);
//     }
// }

// bool Maze::recursiveBacktracking(Coordinate coor) {
//     visitedTracker.push_back(coor);

//     auto allOptions = randomChoice(coor);
//     while (!allOptions.empty()) {
//         int randomIndex = rand() % allOptions.size();
//         Coordinate next = allOptions[randomIndex];

//         // Add connections
//         if (next.at(POSITION_X) == coor.at(POSITION_X) && next.at(POSITION_Y) == coor.at(POSITION_Y) + 1) { // Down
//             coor.addConnection(next);
//             next.addConnection(coor);
//         } else if (next.at(POSITION_X) == coor.at(POSITION_X) && next.at(POSITION_Y) == coor.at(POSITION_Y) - 1) { // Up
//             coor.addConnection(next);
//             next.addConnection(coor);
//         } else if (next.at(POSITION_X) == coor.at(POSITION_X) + 1 && next.at(POSITION_Y) == coor.at(POSITION_Y)) { // Right
//             coor.addConnection(next);
//             next.addConnection(coor);
//         } else if (next.at(POSITION_X) == coor.at(POSITION_X) - 1 && next.at(POSITION_Y) == coor.at(POSITION_Y)) { // Left
//             coor.addConnection(next);
//             next.addConnection(coor);
//         }

//         if (recursiveBacktracking(next)) return true;

//         allOptions.erase(allOptions.begin() + randomIndex); // Remove this option
//     }

//     return false;
// }

// void Maze::generate() {
//     Coordinate start(0, 0);
//     recursiveBacktracking(start);
// }

// bool Maze::findPath(Coordinate from, Coordinate to){

//    /* if( (to.at(POSITION_X) == from.at(POSITION_X)) && (to.at(POSITION_Y) == from.at(POSITION_Y)) ){
//         return true;
//     }
    
//     mazeStack.push(from);
//     visitedTracker.push_back(from);
    
//     std::vector<Coordinate> allOptions = randomChoice(from);
//     if(allOptions.size() == 0){
//         mazeStack.pop();
//         bool res = findPath(mazeStack.top(), to);
//         if(res){
//             return true;
//         }
//     } else {
//         srand(time(0));
//         int randomIndex = rand() % allOptions.size();
//         bool res = findPath( allOptions.at(randomIndex), to);
//         if(res){
//             return true;
//         }
//     }

//     return true;*/
//     return true;
// }

// int Maze::getColumns(){
//     return columns;
// }

// int Maze::getRows(){
//     return rows;
// }

// bool Maze::hasConnectionToTheBottomNeighbour(int row, int col){

//     for (int i = 0; i < visitedTracker.size(); ++i){
//         if( ( visitedTracker.at(i).at(POSITION_X) == row ) && ( visitedTracker.at(i).at(POSITION_Y) == col ) ){
//             bool res = visitedTracker.at(i).hasBottomConnection();

//             if(res){
//                 return true;
//             }
//         }
//     }


//     return false;
// }
// bool Maze::hasConnectionToTheRightNeighbour(int row, int col){
//     for (int i = 0; i < visitedTracker.size(); ++i){
//     if( ( visitedTracker.at(i).at(POSITION_X) == row ) && ( visitedTracker.at(i).at(POSITION_Y) == col ) ){
//             bool res = visitedTracker.at(i).hasRightConnection();

//             if(res){
//                 return true;
//             }
//         }
//     }


//     return false;
// }
// bool Maze::isPartOfPath(int row, int col){
//     return false;
// }
