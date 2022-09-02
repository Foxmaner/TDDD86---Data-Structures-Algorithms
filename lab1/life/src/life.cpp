// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <iostream>
#include "grid.h"
#include "lifeutil.h"
#include <string>
#include <fstream>

using namespace std;
int main() {
    //Filename for initGame. max 20 long
    string fileName;
    //Store message as a string
    string welcomeMessage = "Welcome to the TDDD86 Game of Life,"
                            " a simulation of the lifecycle of a bacteria colony."
                            " \nCells (X) live and die by the following rules:"
                            " \n - A cell with 1 or fewer neighbours dies."
                            " \n - Locations with 2 neighbours remain stable."
                            " \n - Locations with 3 neighbours will create life."
                            " \n - A cell with 4 or more neighbours dies."
                            " \n \n Grid input file name?";
    //Write out wellcome message
    cout << welcomeMessage << endl;
    //Take in filename
    cin >> fileName;
    //_______________________________________
    //READ TEXT CONTENT

      string myText;
      int nrOfRows;
      int nrOfColumns;

      // Read from the text file
      ifstream MyReadFile("../" + fileName);

      MyReadFile >> nrOfRows;
      MyReadFile >> nrOfColumns;
      //Creates new grid with correct width/height
      Grid<int> grid = Grid<int>(nrOfRows,nrOfColumns);

      string nextLine;
      for(int i=0;i<nrOfRows;i++){
         MyReadFile >> nextLine;
         for(int j=0;j<nrOfColumns;j++){
           if(nextLine[j]=='x'){
            grid.set(i,j,1);
           }
         }
      }
        cout << grid.toString();
      // Close the file
      MyReadFile.close();



    //_______________________________________

    return 0;
}

