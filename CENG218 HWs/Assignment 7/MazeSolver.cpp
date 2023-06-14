#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Maze {
private:
   vector<vector<char>> MD;
   int rows;
   int cols;
   int startRow;
   int startCol;
   int goalRow;
   int goalCol;

public:
   Maze(int nr = 0, int nc = 0) {
      rows = nr;
      cols = nc;
   }

   void readMazeFile(string fname) {
      // read Maze data from text file
      ifstream f;
      f.open(fname);
      string mazerow;
      string NrowsNcols, Start, Goal;
      getline(f, NrowsNcols);
      int nr = std::stoi(NrowsNcols);
      cout << "nr = " << nr << endl;
      cout << "substr: " << NrowsNcols.substr(NrowsNcols.find(',') + 1) << endl;
      int nc = stoi(NrowsNcols.substr(NrowsNcols.find(',') + 1));
      cout << "nc = "<< nc << endl;

      getline(f, Start);
      getline(f, Goal);
      rows = nr;
      cols = nc;
      //get number-of-rows and number-of-columns

      //get Goal position
      startRow = stoi(Start.substr(Start.find('=') + 1, Start.find(',') - Start.find('=') - 1));
      startCol = stoi(Start.substr(Start.find(',') + 1));
      goalRow = stoi(Goal.substr(Goal.find('=') + 1, Goal.find(',') - Goal.find('=') - 1));
      goalCol = stoi(Goal.substr(Goal.find(',') + 1));

      for(int i = 0; i < rows; i++) {
         vector<char> tmp(cols);  //empty row
         MD.push_back(tmp);  // insert into Maze Array
      }

      int row = 0;
      while(getline(f, mazerow)) {
         for(int col = 0; col < cols; col++) {
            MD[row][col] = mazerow[col];
        }
        
        row++; 
      }

     f.close();
   }

   void printMaze()
   {
      cout << endl;

      for (size_t i = 0; i < rows; i++)
      {
         for (size_t j = 0; j < cols; j++)
         {
            cout << MD[i][j] << " ";
         }
         
         cout << endl;
      }
      
   }

   void SolveMaze()
   {
      stack<pair<int, int>> pathStack;

      pathStack.push(make_pair(startRow, startCol));

      while (!pathStack.empty()) {
         pair<int, int> currentPos = pathStack.top();
         int row = currentPos.first;
         int col = currentPos.second;

         if (row == goalRow && col == goalCol) {
               cout << "Goal reached!" << endl;
               return;
         }

         MD[row][col] = 'V';
         printMaze();

         if (isValidMove(row, col + 1)) 
            pathStack.push(make_pair(row, col + 1));
          
         else if (isValidMove(row + 1, col))  
               pathStack.push(make_pair(row + 1, col));
         
         else if (isValidMove(row, col - 1))
               pathStack.push(make_pair(row, col - 1));
         
         else if (isValidMove(row - 1, col))
               pathStack.push(make_pair(row - 1, col));
         
         else 
            pathStack.pop();
      }

      cout << "No path found to the goal!" << endl;
   }

   bool isValidMove(int row, int col) {
      return row >= 0 && row < rows && col >= 0 && col < cols && MD[row][col] == 'O';
   }

};

int main() {
   Maze M1(14,15);
   M1.readMazeFile("Maze1.txt");
   M1.printMaze();
   M1.SolveMaze();

   return 0;
}