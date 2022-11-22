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
    lexicon=Lexicon(DICTIONARY_FILE);
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

void Boggle::setTable(string tableString){
    grid.resize(BOARD_SIZE,BOARD_SIZE);
    int count = 0;
    for(int y=0;y < BOARD_SIZE;y++){
        for(int x=0;x < BOARD_SIZE;x++){
            grid.set(y,x,tableString[count]);
            count++;
        }
    }
}

bool Boggle::guessWord(string input){
    if(lexicon.contains(input) && input.size() >= MIN_WORD_LENGTH && userWords.find(input) == userWords.end()){
        userWords.insert(input);
        userScore++;
        return true;
    }else{
        return false;
    }
}

bool Boggle::isWordOnBoard(string inputWord){
    for(int y = 0; y < BOARD_SIZE; y++){
        for(int x = 0; x < BOARD_SIZE; x++){
            if (grid.get(x,y) != inputWord[0]){
                continue;
            }
            vector<int,int> emptyVector;
            if(isWordPossibleReq(x,y,inputWord, emptyVector)){
                return true;
            }
        }
    }
}

bool Boggle::isWordPossibleReq(int x, int y, string inputWord, vector<pair<int, int>> visitedCords, string searchPath){
    //Have we found the whole word???
    if(searchPath==inputWord){
        return true;
    }


    //Generate cords for all neighbors
    for(int k = -1; k <= 1; k++){
        for(int i = -1; i <= 1; i++){
            int newX = x+k;
            int newY = y+i;
            if(grid.inBounds(newX,newY) && grid.get(newX, newY) == inputWord[searchPath.length()+1]){

                visitedCords.push_back(pair<int, int>(2, 2));
            }


            isWordPossibleReq(newX,newY,inputWord,visitedCords,searchPath);
        }
    }
};
