// This is the .cpp file you will edit and turn in.
// We have provided a minimal skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header and replace it with your own

#include <sstream>
#include "Boggle.h"
#include "random.h"
#include "shuffle.h"
#include "strlib.h"

static const int NUM_CUBES = 16;   // the number of cubes in the game
static const int CUBE_SIDES = 5;   // the number of sides on each cube
static string CUBES[NUM_CUBES] = {        // the letters on all 6 sides of every cube
   "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
   "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
   "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
   "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};



// TODO: implement the members you declared in Boggle.h

Boggle::Boggle(){
    shuffle();
    printTable();
}


void Boggle::shuffle(){
    grid.resize(4,4);
    
    int boardPlace = 0;
    //Places the cube on the board;
    for(int y=0;y < BOARD_SIZE;y++){
        for(int x=0;x < BOARD_SIZE;x++){
            grid.set(x,y,CUBES[boardPlace][randomInteger(0,CUBE_SIDES)]) ;
            boardPlace++;
        }
    }


    //Shuffles every cube with a random cube on the board.
    for(int y=0;y < BOARD_SIZE;y++){
        for(int x=0;x < BOARD_SIZE;x++){
            int randomX = randomInteger(0,3);
            int randomY = randomInteger(0,3);

            char temp = grid.get(randomY,randomX);

            grid.set(randomY,randomX, grid.get(y,x));
            grid.set(y, x, temp);
        }
    }
}; 


void Boggle::printTable(){
    for(int y=0;y < BOARD_SIZE;y++){
        for(int x=0;x < BOARD_SIZE;x++){
            cout << grid.get(y,x) << " ";
        }
        cout << "\n" ;
    }
}
