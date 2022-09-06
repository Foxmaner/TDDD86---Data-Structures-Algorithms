#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

const string ALPHABET  = "abcdefghijklmnopqrstuvwxyz";

void wordChain(string firstWord, string lastWord){
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

        }

    }
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

    wordChain(firstWord,lastWord);

    return 0;
}
