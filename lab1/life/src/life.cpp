/*
 * Programmerare: Eskbr129, Bjoed735
 * Eskil Brännerud, Björn Edblom
 * Vår labb var att skapa spelet Life,
 * det går utt på att bakterier kommer växa
 * och dö beroende på hur många granar den har.
 * En position som har noll eller en granne kommer att vara tom i nasta generation. Om en cell fanns där så dör den¨
 * En position med tva grannar ˚ ar stabil. Om den hade en cell inneh ¨ aller den fortfarande en cell. Om den
 * var tom fortsatter den att vara tom. ¨
 * En position med tre grannar kommer att innehalla en cell i n ˚ asta generation. Om positionen var tom föds ¨
 * en ny cell. Om den for närvarande innehåller en cell, kvarststår cellen. ˚
 * En position med fyra eller fler grannar kommer att vara tom i nasta generation. Om det finns en cell i ¨
 * den positionen dor den av ¨ overbefolkning.
 */

#include <iostream>
#include "grid.h"
#include "lifeutil.h"
#include <string>
#include <fstream>

using namespace std;

/**
 * Prints grid
 *
 * This function prints the whole grid
 * - is an empty cell
 * and x is an occupied cell
 *
 * @param grid
 * @return n/a
 */
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


/**
 * Return number of neighbors
 *
 * This function returns the number of neighbors
 * for a specific position
 *
 * @param grid,row,column
 * @return nrOfNeighbor
 */
int numberOfNeighbor(const Grid<int>& grid, int row, int colum){
    int numberOfNeighbor = 0;

    // Checks neibor on top row
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


    // Check middle row without itself
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

    // Check bottom row
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
/**
 * Ticks the game one step forward
 *
 * This function ticks the game one step forward
 * according to the game rules. It creates a new grid which is then
 * returned to be later used
 *
 * @param grid,nrOfRows,nrOfColumns
 * @return new grid
 */

 Grid<int> tick(const Grid<int>& grid,int nrOfRows, int nrOfColumns){
     // Create a new grid
    Grid<int> newGrid = Grid<int>(nrOfRows,nrOfColumns);
    // Goes thorugh every tile to check the numbers of neighbors
    // and add/remove cells accordingly
    for(int row = 0; row <nrOfRows;row ++ ){
        for(int colum = 0; colum<nrOfColumns; colum ++){
            int count = numberOfNeighbor(grid,row,colum);
            // If one neighbor the cell dies
            if(count <= 1){
                newGrid.set(row,colum,0);
            }
            // If three neighbors the cell filled
            else if(count == 3){
                newGrid.set(row,colum,1);
            }
            // If two neighbors keep the previous value
            else if(count == 2){
                // Check start value
                newGrid.set(row,colum,grid[row][colum]);
            }
            // If three or more the cell dies
            else if(count >= 3){
                newGrid.set(row,colum,0);
            }
        }
    }
    return newGrid;
}

 /**
  * Main function
  *
  * This function is the main function
  * It initilizes the the game, and then
  * handle user imputs to determine what to do.
  *
  * @param n/a
  * @return n/a
  */
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

    // Fills the empty game board with occupied cells
    // according to the text file
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
        clearConsole();
        printGrid(grid);
        cout << "\n a)nimate, t)ick, q)uit?";
        cin >> choice;
        if(choice=='q'){
            cont=false;
        }else if(choice=='t'){
            grid = tick(grid,nrOfRows,nrOfColumns);
            //Do one tick on the grid
        }else if(choice=='a'){
            //Do 10 ticks on grid with some pauses inbetween
            for(int i = 0; i < 10; i++){
                clearConsole();
                grid = tick(grid,nrOfRows,nrOfColumns);
                cout << flush;
                printGrid(grid);
                //pauses program for 100ms
                pause(100);
            }
        }else{
            cout << "Try again!\n";
        }
    }
    //_______________________________________
    cout << "Have a nice Life!\n";
    return 0;
}





