// You will edit and turn in this CPP file.
// Also remove these comments here and add your own.
// TODO: remove this comment header and replace with your own

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Boggle.h"
#include "bogglemain.h"
#include "strlib.h"
// TODO: include any other header files you need

bool isAllChars(string input){
    for(unsigned int i = 0; i<input.size(); i++){
       if((input[i] < 'A') || (input[i]>'Z' && input[i]<'a') || input[i]>'z'){
           return false;
       }
    }
    return true;
};

/*
 * Plays one game of Boggle using the given boggle game state object.
 */
void playOneGame(Boggle& boggle) {
    // TODO: implement this function (and add any other functions you like to help you)
    //boggle.shuffle();
    //boggle.printTable();
    //Ask if we wanna set own table
    if (yesOrNo("Do you want to set your own table? (Y/N)? ")) {
            string boardString;
            while(boardString.length()!=16 || !isAllChars(boardString)){
                cout << "Please type in a string with 16 letters" << endl;
                cin >> boardString;
            }
            boggle.setTable(boardString);

    }else{
        //Randomise table
        boggle.shuffle();
    }


    //Play loop

    while(true){
        //clearConsole();

        string inputWord;

        cout << "Its your turn!" << endl;
        boggle.printTable();

        cout << "Your words (" << boggle.userWords.size() << "): " << endl;

        cout << "Your score: " << boggle.userScore << endl;

        cout << "Type a word (or press Enter to end your turn): " << endl;

        cin >> inputWord;
        boggle.guessWord(toUpperCase(inputWord));



    }



}

/*
 * Erases all currently visible text from the output console.
 */
void clearConsole() {
#if defined(_WIN32) || defined(_WIN64)
    std::system("CLS");
#else
    // assume POSIX
    std::system("clear");
#endif
}


