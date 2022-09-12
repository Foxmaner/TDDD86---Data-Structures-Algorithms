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
            cout<<currentWord + "\n";
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
        int selectedWordLength;
        cin >> selectedWordLength;

        if(selectedWordLength==0){
            cout << "Du kan ju inte välja ett ord med 0 bokstäver idiot!";
        }else{
            if(!myMap.count(selectedWordLength)){
                cout << "Finns inga sånna ord bror!";
            }
        }

    }

    return 0;
}
