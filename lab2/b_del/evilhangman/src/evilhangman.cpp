/*
 *Programmerare: Eskbr129, Bjoed735
 * Eskil Brännerud, Björn Edblom.
 * I denna labb skapar vi en svårare version av evilhangman.
 * Istället för att spelet väljer 1 ord i början, så byter den istället
 * ord under spelets gång för att göra det så svårt som möjligt för spelaren.
 * Spelet avslutas när spelaren gissat rätt, eller mer troligt, fått slut på försök...
 *
 *
*/

#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

const string ALPHABET  = "abcdefghijklmnopqrstuvwxyz";


/**
 * largestWordGroup
 *
 * The function which runs the game.
 *
 * When the game is over, it returns (to the main function) for a restart. Or it exists the program.
 *
 * @param guess, possibleWords
 * @return set<String> largestWordGroup
 */
set<string> largestWordGroup(char& guess, set<string> possibleWords){
    map<int,set<string>> wordGroups;


    for(set<string>::iterator it=possibleWords.begin(); it!=possibleWords.end(); ++it){
        string currentWord = *it;
        int keyValue = 0;
        for (unsigned int n = 0; n < currentWord.size(); n++){
            if(currentWord[n] == guess){
                keyValue += pow(2,n);
            }
        }


        if(!wordGroups.count(keyValue)){
            //Key does not already exist, creates a new one
            set<string> tempSet;
            tempSet.insert(currentWord);
            wordGroups.insert(pair<int, set<string>>(keyValue, tempSet));
        }else{
            //Key already exist. Insert at correct key.
            wordGroups.at(keyValue).insert(currentWord);
        }
    }
    set<string> largestElement;
    for ( auto it = wordGroups.begin(); it != wordGroups.end(); ++it  ){
       set<string> currentElement = it->second;

       if(largestElement.size()<currentElement.size()){
           largestElement=currentElement;
       }
    }
    return largestElement;
}

/**
 * runGame
 *
 * The function which runs the game.
 *
 * When the game is over, it returns (to the main function) for a restart. Or it exits the program.
 *
 * @param selectedWordLength, selectedNrOfGuesses, availableWords, debugState
 * @return N/A
 */
void runGame(int& electedWordLength, int& selectedGuesses, set<string>& availableWords, int debugState){
    set<char> usedAlpabet;
    char inputChar;
    int nrOfTriesLeft = selectedGuesses;
    //The "guessword" only filled with _ at the start
    string guessWord(electedWordLength,'_');

    //Run the game as long as there are guesses left
    while(nrOfTriesLeft> 0){
        cout << "Försök kvar: " << nrOfTriesLeft << "\n";
        cout << "Ordet:" << guessWord << "\n";
        cout << "Använda bokstäver: ";
        for(set<char>::iterator it=usedAlpabet.begin(); it!=usedAlpabet.end(); ++it){
            cout << *it;
        }
        cout << "\n Skriv in en bokstav:";
        cin>>inputChar;
        //Used to only accept the first character which is entered.
        cin.ignore(10000, '\n');
        //Adds it to the table of used chars
        usedAlpabet.insert(inputChar);
        nrOfTriesLeft--;
        //Fetches all the available words, from the largest word group
        availableWords = largestWordGroup(inputChar, availableWords);


        if(availableWords.size()==0){
            //Fel
        }else{

           //Removes the "unknown" spaces in the guess-word and replaces with the real char
           for(unsigned int i = 0; i<availableWords.rbegin()->size(); i++){
                if(availableWords.rbegin()->at(i)==inputChar){
                    guessWord.at(i)=inputChar;
                }
           }
        }

        //If debug state is activated, output availableWords
        if(debugState == 1){
            for(set<string>::iterator it=availableWords.begin(); it!=availableWords.end(); ++it)
                std::cout << *it << std::endl;
        }
        auto ThelastWord = *(availableWords.begin());
        //If true, the player has won
        if(availableWords.size()==1 && ThelastWord == guessWord ){
            cout << "\n" "Du har klarat spelet!!! \n ";
            cout << "Här har du det gissande ordet -->" << guessWord;
            break;
        }
        cout << "Här har du det gissande ordet -->" << guessWord << "\n";
    }

    //After the wile loop
    //Checks if there are words left. If so, the player has lost
    if((availableWords.size()>=1) && !(*(availableWords.begin()) == guessWord)){
    auto endingWord = *(availableWords.begin());
    cout << "You lost this is the word -->" <<endingWord;
    }
    //Ask if user want to play again. Return to main, or closes the program.
    int playAgainInput;
    cout << "\n Spelet är över. Vill du spela igen? 1/0: ";
    cin >> playAgainInput;
    if(playAgainInput){
        return;
    }else{
        exit(EXIT_SUCCESS);
    }
}

/**
 * loadFile
 *
 * Returns a map with sets of strings. The map-keys correspond to
 * the words length.
 *
 * @param N/A
 * @return map<int, set<string>> dictionary
 */
map<int, set<string>> loadFile(){
    map<int, set<string>> dictionary;
    //Dictionary
    ifstream MyReadFile("dictionary.txt");
    string currentWord;

    // While there are more words to be read, keep pushing into vektor
    //Read new words.
    while (MyReadFile >> currentWord){
        if(currentWord.length() == 0){
            continue;
        }else if(!dictionary.count(currentWord.length())){
            //Key does not already exist, creates a new one
            set<string> tempSet;
            tempSet.insert(currentWord);
            dictionary.insert(pair<int, set<string>>(currentWord.length(), tempSet));
        }else{
            //Key already exist. Insert at correct key.
            dictionary.at(currentWord.size()).insert(currentWord);
        }
    }
    return dictionary;
}

/**
 * Main function
 *
 * The programs entry-point.
 * It is used for menu, so to collect users input to finaly start the game
 * with the users settings applied.
 *
 * @param N/A
 * @return N/A
 */
int main() {
    cout << "Welcome to Hangman." << endl;

    map<int, set<string>> myMap = loadFile();

    while(true){
        int selectedWordLength = 0;
        int selectedGuesses = 0;

        //Asks for the word length, until a word is found
        set<string> availableWords;
        cout << "\n Välj längden på ordet: ";
        cin >> selectedWordLength;
        while(!myMap.count(selectedWordLength)){
            cout << "Ord längden finns inte, skriv nytt: ";
            cin >> selectedWordLength;
        }
        //Load with available words
        availableWords=myMap.at(selectedWordLength);

        //Asks for the number of guesses
        cout << "\n Välj antal gisningar: ";
        cin >> selectedGuesses;

        while(selectedGuesses<=0) {
            cout << "Antal gisnigar måste vara mellan 1 och 26, försök igen: ";
            cin >> selectedGuesses;
        }

        //Asks if debug-mode should be enabled
        int inputTest;
        cout << "Skriv 1/0 för att se antalet kvarvarande ord: ";
        cin >> inputTest;

        if(inputTest){
            for(set<string>::iterator it=availableWords.begin(); it!=availableWords.end(); ++it)
                cout << *it +", " << endl;
        }
        //Runs game with all collected parametrs
        runGame(selectedWordLength,selectedGuesses,availableWords,inputTest);


    }

    return 0;
}
