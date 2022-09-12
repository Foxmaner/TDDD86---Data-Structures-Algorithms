#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <map>
using namespace std;

const string ALPHABET  = "abcdefghijklmnopqrstuvwxyz";

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


    /*
    set<string> si = myMap.at(3);
    for(std::set<string>::iterator it=si.begin(); it!=si.end(); ++it)
        std::cout << *it << std::endl;
    */

    while(1){
        int selectedWordLength = 0;
        int selectedGuesses = 0;
        cout << "\n Välj längden på ordet";
        cin >> selectedWordLength;



        while(!myMap.count(selectedWordLength)){
              cout << "Ord längden finns inte \n";
              cin >> selectedWordLength;

        }

        cout << "\n välj antal gisningar";
        cin >> selectedWordLength;

        while(selectedGuesses <=0) {
            cout << "Antal gisnigar måste vara mellan 1 och 26 \n";
            cin >> selectedGuesses;
        }
        int inputTest;
        cout << "\n type 1/0 för att se antalet kvarvarande ord";
        cin >> inputTest;
        


    }

    return 0;
}
