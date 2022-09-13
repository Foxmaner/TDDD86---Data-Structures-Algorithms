#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

const string ALPHABET  = "abcdefghijklmnopqrstuvwxyz";

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
            cout << currentWord << "<- currentWord \n";
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


void runGame(int& electedWordLength, int& selectedGuesses, set<string>& availableWords){
    set<char> usedAlpabet;
    char inputChar;
    int nrOfTriesLeft = selectedGuesses;
    string guessWord(electedWordLength,'_');


    while(nrOfTriesLeft){
        cout << "Försök kvar: " << nrOfTriesLeft << "\n";
        cout << "Ordet:" << guessWord << "\n";
        cout << "Använda bokstäver: ";
        for(set<char>::iterator it=usedAlpabet.begin(); it!=usedAlpabet.end(); ++it){
            cout << *it;
        }
        cout << "\n Skriv in en bokstav:";
        cin>>inputChar;
        cin.ignore(10000, '\n');
        usedAlpabet.insert(inputChar);
        nrOfTriesLeft--;
        availableWords = largestWordGroup(inputChar, availableWords);

        if(availableWords.size()==0){
            //Fel
        }else{
           for(unsigned int i = 0; i<availableWords.rbegin()->size(); i++){
                if(availableWords.rbegin()->at(i)==inputChar){
                    guessWord.at(i)=inputChar;
                }
           }
        }
        cout << guessWord;
        if(availableWords.size()==0){
            cout << "Du har klarat spelet!!! \n ";
            break;
        }
        /*
        for(set<string>::iterator it=availableWords.begin(); it!=availableWords.end(); ++it)
            std::cout << *it << std::endl;
        */
    }

    int playAgainInput;
    cout << "\n Spelet är över. Vill du spela igen? 1/0: ";
    cin >> playAgainInput;
    if(playAgainInput){
        return;
    }else{
        exit(EXIT_SUCCESS);
    }
}

/*
Creates a map of sets with strings.
It groups strings together with words of same length.
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


int main() {
    cout << "Welcome to Hangman." << endl;

    // TODO: Finish the program!
    map<int, set<string>> myMap = loadFile();

    while(1){
        int selectedWordLength = 0;
        int selectedGuesses = 0;
        set<string> availableWords;
        cout << "\n Välj längden på ordet: ";
        cin >> selectedWordLength;



        while(!myMap.count(selectedWordLength)){
            cout << "Ord längden finns inte, skriv nytt: ";
            cin >> selectedWordLength;
        }
        //Load with available words
        availableWords=myMap.at(selectedWordLength);


        cout << "\n Välj antal gisningar: ";
        cin >> selectedGuesses;

        while(selectedGuesses<=0) {
            cout << "Antal gisnigar måste vara mellan 1 och 26, försök igen: ";
            cin >> selectedGuesses;
        }
        int inputTest;
        cout << "Skriv 1/0 för att se antalet kvarvarande ord: ";
        cin >> inputTest;

        if(inputTest){
            for(set<string>::iterator it=availableWords.begin(); it!=availableWords.end(); ++it)
                cout << *it +", " << endl;
        }
        
        runGame(selectedWordLength,selectedGuesses,availableWords);


    }

    return 0;
}
