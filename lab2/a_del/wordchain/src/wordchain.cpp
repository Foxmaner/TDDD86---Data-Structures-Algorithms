/*
 *Programmerare: Eskbr129, Bjoed735
 *Eskil Brännerud, Björn Edblom.
 *
 * I denna har vi ett program som försöker hitta en ordkedja.
 * Användaren matar in 2 ord i följd, och programmet försöker sedan att skapa en ordkedja.
 * En ordkedja är där man går från ord a->b genom att endast ändra
 * 1 bokstav åt gången. Men varje delsteg måste också vara ett giltigt ord
 *
 *
*/

#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

const string ALPHABET  = "abcdefghijklmnopqrstuvwxyz";

/**
 * getNeighbors
 *
 * returns words all words that are only 1 char appart. And are a valid word.
 *
 * @param word,wordDict
 * @return neighbor
 */
set<string> getNeighbors(string word,const set<string> &wordDict){
    set<string> neighbor;
    //Jumps through every char in word
    for(int indexInWord = 0; indexInWord < (int) word.size(); indexInWord++){
        //Tests every char for that position
        for(int indexInAlphabet = 0; indexInAlphabet < (int)ALPHABET.size(); indexInAlphabet++){
            string newWord = word;
            newWord[indexInWord] = ALPHABET[indexInAlphabet];
            //If the word is valid, its added to the list
            if(wordDict.find(newWord) != wordDict.end()){
                //stack<string> copyCurrentStack = currentStack;
                neighbor.insert(newWord);
            }

        }
    }
    return neighbor;
}

/**
 * wordChain
 *
 * The function tries to find a wordchain between firstWord -> lastWord.
 * If found, it prints it.
 *
 * @param firstWord,lastWord,wordDict
 * @return n/a
 */
void wordChain(string firstWord, string lastWord, set<string> &wordDict){
    queue<stack<string>> stackQueue;

    stack<string> currentStack;
    currentStack.push(firstWord);
    set<string> UsedWords;

    stackQueue.push(currentStack);
    stack<string> tempStack;

    set<string> neighbor;

    //Forstätt sålänge stackQueue inte är tom
    while(!stackQueue.empty()){
        currentStack = stackQueue.front();
        stackQueue.pop();

        string wordAtTop = currentStack.top();
        //Om vi hittat ordet. Börja popa stacken och skriva ut
        if(wordAtTop==lastWord){
            cout << "Hitta ordet. listan kommer.... \n";
            while(!currentStack.empty()){
                string partWord = currentStack.top();
                currentStack.pop();
                cout <<  " => " + partWord + "  ";
            }
        }
        else{
            //Annars. Gå igenom varje granne och pusha in i stacken, och sedan i kön
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

/**
 * loadFile
 *
 * loads a set with all words from the dictionary with a specific length.
 * then returns the newly created set.
 *
 * @param wordLength
 * @return wordDict
 */
set<string> loadFile(unsigned wordLenght){
    set<string> wordDict = set<string>();
    ifstream MyReadFile("dictionary.txt");
    string currentWord;
    // While there are more words to be read, keep pushing into vektor
    while (MyReadFile >> currentWord){
        //Only push into vector if its the correct length
        if(currentWord.length() == wordLenght)
        wordDict.insert(currentWord);
    }
    return wordDict;
}

/**
 * main
 *
 * The programs entry-point.
 * It tells the user to inputs 2 words, and then calls the function wordChain() with
 * the users parameters.
 *
 * @param N/A
 * @return N/A
 */
int main() {
    cout << "Welcome to TDDD86 Word Chain." << endl;
    cout << "If you give me two English words, I will transform the" << endl;
    cout << "first into the second by changing one letter at a time." << endl;
    cout << endl;

    cout << "Please type two words: ";

    // Takes in the first and last word.
    string firstWord,lastWord;
    cin >> firstWord >> lastWord;

    //Load in dictionary
    set<string> wordDict = loadFile(firstWord.length());
    wordChain(firstWord,lastWord, wordDict);
    return 0;
}
