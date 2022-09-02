// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <iostream>
#include "grid.h"
#include "lifeutil.h"
#include <string>
#include <fstream>

using namespace std;

void printGrid(const Grid<int>& grid){
    for(int row=0;row<grid.numRows();row++){
        for(int col=0;col<grid.numCols();col++){
            if(grid.get(row,col)==0){
                cout << "-";
            }else{
                cout << "x";
            }
        }
        cout << "\n";
    }

}



int numberOfNeighbor(const Grid<int>& grid, int row, int colum){
    int numberOfNeighbor = 0;

    // Top row
    if(grid.inBounds(row-1,colum-1)){
        if(grid[row - 1][colum - 1] == 1){
            numberOfNeighbor ++;
        }
    }
    if(grid.inBounds(row-1,colum)){
        if(grid[row - 1][colum] == 1){
            numberOfNeighbor ++;
        }
    }
    if(grid.inBounds(row-1,colum + 1)) {
        if(grid[row - 1][colum + 1] == 1){
            numberOfNeighbor ++;
        }
    }


    // Middle row without itself

    if(grid.inBounds(row,colum - 1)) {
        if(grid[row][colum - 1] == 1){
            numberOfNeighbor ++;
        }
    }
    if(grid.inBounds(row ,colum + 1)) {
        if(grid[row ][colum + 1] == 1){
            numberOfNeighbor ++;
        }
    }

    // Bottom row

    if(grid.inBounds(row+1,colum - 1)) {
        if(grid[row + 1][colum - 1] == 1){
            numberOfNeighbor ++;
        }
    }
    if(grid.inBounds(row+1,colum)) {
        if(grid[row + 1][colum] == 1){
            numberOfNeighbor ++;
        }
    }
    if(grid.inBounds(row+1,colum + 1)) {
        if(grid[row + 1][colum + 1] == 1){
            numberOfNeighbor ++;
        }
    }


    return numberOfNeighbor;
}

void tick( Grid<int>& grid,int nrOfRows, int nrOfColumns){
    for(int row = 0; row <nrOfRows;row ++ ){
        for(int colum = 0; colum<nrOfColumns; colum ++){
            int count = numberOfNeighbor(grid,row,colum);

            if(count <= 1){
                grid.set(row,colum,0);
            }

            else if(count == 3){
                grid.set(row,colum,1);
            }

            else if(count >= 3){
                grid.set(row,colum,0);
            }
        }
    }
}


int main() {
    //Filename for initGame. max 20 long
    string fileName;
    //Store message as a string
    string welcomeMessage = "Welcooidme to the TDDD86 Game of Life,"
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
    ifstream MyReadFile(fileName);

    MyReadFile >> nrOfRows;
    MyReadFile >> nrOfColumns;
    //Creates new grid with correct width/height
    Grid<int> grid = Grid<int>(nrOfRows,nrOfColumns);

    string nextLine;

    for(int i=0;i<nrOfRows;i++){
        MyReadFile >> nextLine;
        for(int j=0;j<nrOfColumns;j++){
            if(nextLine[j]=='X'){
                grid.set(i,j,1);
            }
        }
    }
    // Close the file
    MyReadFile.close();

    //Running
    char choice;
    bool cont = true;
    while(cont){
        printGrid(grid);
        cout << "\n a)nimate, t)ick, q)uit?";

        cin >> choice;
        if(choice=='q'){
            cont=false;
        }else if(choice=='t'){
            tick(grid,nrOfRows,nrOfColumns);
            //Do one tick on the grid
        }else if(choice=='a'){
            //Do 10 ticks on grid with some pauses inbetween
        }else{
            cout << "Try again!\n";
        }
    }
    //_______________________________________
    cout << "Have a nice Life!\n";
    return 0;
}





