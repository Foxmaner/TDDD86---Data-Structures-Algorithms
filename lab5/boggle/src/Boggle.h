// This is the .h file you will edit and turn in.
// We have provided a minimal skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own, as well as on the members.
// TODO: remove this comment header and replace it with your own

#ifndef _boggle_h
#define _boggle_h

#include <iostream>
#include <string>
#include <set>
#include "grid.h"
#include "lexicon.h"
// TODO: include any other header files you need

using namespace std;

class Boggle {
public:
    const string DICTIONARY_FILE = "EnglishWords.dat";
    const int MIN_WORD_LENGTH = 4;
    const int BOARD_SIZE = 4;

    set<string> userWords;
    set<string> computerWords;
    int userScore = 0;
    int computerScore = 0;
    set<string> possibleWords;

    Boggle();
    // TODO: decide the public member functions and declare them

    //Shuffles the cubes and insert them on random positions on the grid.
    void shuffleBoggle();
    void printTable();
    void setTable(string tableString);
    bool guessWord(string input);
    bool isWordOnBoard(string inputWord);
    bool isWordPossibleReq(int x, int y, string inputWord, set<pair<int, int>> visitedCords);

    void findAllWords();

    bool wordAlreadyTaken(string input);
    void findAllWordsFromPlace(int x, int y, string inputWord, set<pair<int, int>> visitedCords);
private:
    // TODO: decide the private member variables/functions and declare them
    Grid<char> grid;
    Lexicon lexicon;
};

#endif

