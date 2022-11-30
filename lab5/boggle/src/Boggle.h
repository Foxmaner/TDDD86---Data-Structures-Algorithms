#ifndef _boggle_h
#define _boggle_h

#include <iostream>
#include <string>
#include <set>
#include "grid.h"
#include "lexicon.h"


using namespace std;

class Boggle {
public:
    const string DICTIONARY_FILE = "EnglishWords.dat";
    const int MIN_WORD_LENGTH = 4;
    const int BOARD_SIZE = 4;


    Boggle();

    /*
    * Shuffles the cubes and insert them on random positions on the grid.
    */
    void shuffleBoggle();


    /*
    * Print out the table with all the chars
    */
    void printTable();

    /*
    * Let user set up a custom table with 16 letters
    */
    void setTable(const string tableString);

    /*
    * Lets user guess a word and check if it is valid
    */
    bool guessWord(const string input);

    /*
    * Goes through all x and y and call isWordPossibleReq
    */
    bool isWordOnBoard(const string inputWord);


    /*
    * Try recusivly find the given word
    */
    bool isWordPossibleReq(const int x, const int y, string inputWord, set<pair<int, int>> visitedCords);


    /*
    * Goes through all x and y and call findAllWordsFromPLace
    */
    void findAllWords();


    /*
    * Check if the word is long enough and not already taken
    */
    bool wordAlreadyTaken(const string input);

    /*
    * Try recusivly find a new word from x and y position
    */
    void findAllWordsFromPlace(const int x,const int y, string inputWord, set<pair<int, int>> visitedCords);

    /*
    * Geters and seters
    */
    set<string> getUserWords() const;
    void setUserWords(const set<string> &value);

    set<string> getPossibleWords() const;
    void setPossibleWords(const set<string> &value);

    int getUserScore() const;
    void setUserScore(int value);

    int getComputerScore() const;
    void setComputerScore(int value);

    /*
    * reset game variables for a new run
    */
    void resetGame();

private:
    // TODO: decide the private member variables/functions and declare them
    Grid<char> grid;
    Lexicon lexicon;

    set<string> userWords;
    set<string> possibleWords;
    int userScore = 0;
    int computerScore = 0;
};

#endif

