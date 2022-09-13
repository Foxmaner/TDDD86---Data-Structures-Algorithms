#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <map>
using namespace std;

const string ALPHABET  = "abcdefghijklmnopqrstuvwxyz";


void runGame(int& electedWordLength, int& selectedGuesses, set<string>& availableWords){
    set<char> usedAlpabet;
    char inputChar;
    int nrOfTriesLeft = selectedGuesses;
    string guessWord(electedWordLength,'_');


    while(nrOfTriesLeft){
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
        cout << "Försök kvar: " << nrOfTriesLeft << "\n";
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
        cout << "\n Välj längden på ordet";
        cin >> selectedWordLength;



        while(!myMap.count(selectedWordLength)){
            cout << "Ord längden finns inte \n";
            cin >> selectedWordLength;
        }
        //Load with available words
        availableWords=myMap.at(selectedWordLength);


        cout << "\n välj antal gisningar";
        cin >> selectedWordLength;

        while(selectedGuesses<=0) {
            cout << "Antal gisnigar måste vara mellan 1 och 26 \n";
            cin >> selectedGuesses;
        }
        int inputTest;
        cout << "\n type 1/0 för att se antalet kvarvarande ord";
        cin >> inputTest;

        if(inputTest){
            for(set<string>::iterator it=availableWords.begin(); it!=availableWords.end(); ++it)
                cout << *it +", " << endl;
        }
        
        runGame(selectedWordLength,selectedGuesses,availableWords);


    }

    return 0;
}
