#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

const string ALPHABET  = "abcdefghijklmnopqrstuvwxyz";

void wordChain(string firstWord, string lastWord, vector<string>& wordDict){
    queue<stack<string>> stackQueue;

    stack<string> firstWordStack;
    firstWordStack.push(firstWord);

    stackQueue.push(firstWordStack);

    while(stackQueue.size()){
        stack<string> currentStack = stackQueue.front();
        stackQueue.pop();

        string wordAtTop = currentStack.top();

        if(wordAtTop==lastWord){
            cout << "Hitta ordet. listan kommer.... \n";
            while(!currentStack.empty()){
                string partWord = currentStack.top();
                std::cout << partWord;
                currentStack.pop();
            }
        }else{
            for(int indexInWord = 0; indexInWord < (int) firstWord.size(); indexInWord++){
                for(int indexInAlphabet = 0; indexInAlphabet < (int)ALPHABET.size(); indexInAlphabet++){
                    firstWord[indexInWord] = ALPHABET[indexInAlphabet];
                    if(std::find(wordDict.begin(), wordDict.end(), firstWord) != wordDict.end() ){
                        stack<string> copyCurrentStack = currentStack;
                        copyCurrentStack.push(firstWord);
                        stackQueue.push(copyCurrentStack);
                    }
                }
            }
        }
    }
}

vector<string> loadDictToVector(){
    vector<string> wordDict;
    ifstream MyReadFile("dictionary.txt");
    string currentWord;
    // While there are more words to be read, keep pushing into vektor
    while (MyReadFile >> currentWord){
        wordDict.push_back(currentWord);
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
    vector<string> wordDict = loadDictToVector(); 
    wordChain(firstWord,lastWord, wordDict);
    loadDictToVector();
    return 0;
}
