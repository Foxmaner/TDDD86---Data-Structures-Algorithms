#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

const string ALPHABET  = "abcdefghijklmnopqrstuvwxyz";


set<string> getNeighbors(string word,set<string> &wordDict){
    set<string> neighbor;
    for(int indexInWord = 0; indexInWord < (int) word.size(); indexInWord++){
        for(int indexInAlphabet = 0; indexInAlphabet < (int)ALPHABET.size(); indexInAlphabet++){

            string newWord = word;
            newWord[indexInWord] = ALPHABET[indexInAlphabet];
            if(wordDict.find(newWord) != wordDict.end()){
                //stack<string> copyCurrentStack = currentStack;
                neighbor.insert(newWord);
            }

        }
    }
    return neighbor;
}

void wordChain(string firstWord, string lastWord, set<string> &wordDict){
    queue<stack<string>> stackQueue;

    stack<string> currentStack;
    currentStack.push(firstWord);
    set<string> UsedWords;

    stackQueue.push(currentStack);
    stack<string> tempStack;

    set<string> neighbor;
    while(!stackQueue.empty()){
        currentStack = stackQueue.front();
        stackQueue.pop();

        string wordAtTop = currentStack.top();

        if(wordAtTop==lastWord){
            cout << "Hitta ordet. listan kommer.... \n";
            while(!currentStack.empty()){
                string partWord = currentStack.top();
                currentStack.pop();
                cout <<  " => " + partWord + "  ";
            }
        }
        else{

            neighbor = getNeighbors(wordAtTop,wordDict);

            //vector <string> neighbors = neighbor;



            for(string w : neighbor) {

                //string word = neighbor.at(neighborCheck);

                if(UsedWords.find(w) == UsedWords.end()){
                    tempStack = currentStack;

                    tempStack.push(w);
                    stackQueue.push(tempStack);
                    UsedWords.insert(w);
                }
            }
        }
    }

}

set<string> loadFile(unsigned wordLenght){
    set<string> wordDict = set<string>();
    ifstream MyReadFile("dictionary.txt");
    string currentWord;
    // While there are more words to be read, keep pushing into vektor

    while (MyReadFile >> currentWord){
        if(currentWord.length() == wordLenght)
        wordDict.insert(currentWord);
    }
    return wordDict;
}

int main() {
    cout << "Welcome to TDDD86 Word Chain." << endl;
    cout << "If you give me two English words, I will transform the" << endl;
    cout << "first into the second by changing one letter at a time." << endl;
    cout << endl;

    cout << "Please type two words: ";

    // Takes in the first and last word.
    string firstWord,lastWord;
    cin >> firstWord >> lastWord;
    set<string> wordDict = loadFile(firstWord.length());
    wordChain(firstWord,lastWord, wordDict);
    return 0;
}
