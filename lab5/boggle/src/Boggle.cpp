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


void Boggle::shuffleBoggle(){
    grid.resize(4,4);


    int boardPlace = 0;
    //Places the cube on the board;
    for(int y=0;y < BOARD_SIZE;y++){
        for(int x=0;x < BOARD_SIZE;x++){
            grid.set(x,y,CUBES[boardPlace][randomInteger(0,CUBE_SIDES)]) ;
            boardPlace++;
        }
    }
    shuffle(grid);
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
    if(lexicon.contains(input) && input.size() >= MIN_WORD_LENGTH && userWords.find(input) == userWords.end() && isWordOnBoard(input)){
        userWords.insert(input);
        userScore = userScore + input.size()-3;
        return true;
    }else{
        return false;
    }
}

bool Boggle::isWordOnBoard(string inputWord){

    for(int y = 0; y < BOARD_SIZE; y++){
        for(int x = 0; x < BOARD_SIZE; x++){
            if (grid.get(y,x) == inputWord[0]){
                set<pair<int, int>> emptyVector;
                if(isWordPossibleReq(y,x,inputWord, emptyVector)){
                    return true;
                    }
                
                }
            }
        }
    
    return false;
    }


bool Boggle::isWordPossibleReq(int y, int x, string inputWord, set<pair<int, int>> visitedCords){
    //Have found the whole word
    if(inputWord.length() == 0){
        return true;
    }

    // Check if current char is on the given cords
    if(inputWord[0] != grid.get(y, x)){
        return false;
    }

    // Check if the visited cord so it is not possible to backtrack
    if (visitedCords.find(pair<int ,int>(y, x)) != visitedCords.end()){
            return false;
        }


    
    // Mark current visited cord
    visitedCords.insert(pair<int, int>(y,x));

    //Generate cords for all neighbors
    for(int k = -1; k <= 1; k++){
        for(int i = -1; i <= 1; i++){
            int newX = x+k;
            int newY = y+i;
            
            // Check the coord is not outside of the grid and you are not taking char from the current cord
            if(grid.inBounds(newY,newX) && !(k == 0 && i == 0)){
                if(isWordPossibleReq(newY,newX,inputWord.substr(1),visitedCords)){
                    return true;
                }
            }
        }
    }
    return false;
};

void Boggle::findAllWords(){
    for(int y = 0; y < BOARD_SIZE; y++){
        for(int x = 0; x < BOARD_SIZE; x++){
            set<pair<int, int>> emptyVector;
            string newString="";
            findAllWordsFromPlace(y,x,newString,emptyVector);
            }
        }

}

bool Boggle::wordAlreadyTaken(string input){
    if(userWords.find(input) != userWords.end() || computerWords.find(input) != computerWords.end()){
        return true;
    }
}

void Boggle::findAllWordsFromPlace(int y, int x, string inputWord, set<pair<int, int>> visitedCords){

    // Check if the visited cord so it is not possible to backtrack
    if (visitedCords.find(pair<int ,int>(y, x)) != visitedCords.end()){
            return;
        }

    // Mark current visited cord
    visitedCords.insert(pair<int, int>(y,x));

    //Create new word in string
    inputWord.push_back(grid.get(y,x));

    // See if there is still a chance, otherwise return
    if(!lexicon.containsPrefix(inputWord)){
            return;
        }

    //See if we can already create a word
    if(inputWord.length()>=MIN_WORD_LENGTH && lexicon.contains(inputWord) && !wordAlreadyTaken(inputWord)){
        possibleWords.insert(inputWord);
    }

    //Jump one more step req

    //Generate cords for all neighbors
    for(int k = -1; k <= 1; k++){
        for(int i = -1; i <= 1; i++){
            int newX = x+k;
            int newY = y+i;

            // Check the coord is not outside of the grid and you are not taking char from the current cord
            if(grid.inBounds(newY,newX) && !(k == 0 && i == 0)){
                findAllWordsFromPlace(newY,newX,inputWord,visitedCords);
            }
        }
    }


}
