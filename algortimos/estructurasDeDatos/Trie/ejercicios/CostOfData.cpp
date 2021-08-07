#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int counter = 0;

struct node {
    char currentCharacter;       
    bool isWord;               
    int countWords = 0; 
    struct node *children[27]; 
}*trie; 

void init() {
    counter = 1;
    trie = new node();
    trie->isWord = false;
    trie->countWords = 0;
}

void insertWord(string word) {   
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';       
        if(currentNode->children[character] == NULL ) {
            currentNode->children[character] = new node();
            currentNode->children[character]->countWords = 0;
            counter++;
        }
        currentNode = currentNode->children[character];
       
        currentNode->currentCharacter = word[i];
        currentNode->countWords++;
        currentNode->isWord = false; 
    }
    currentNode->isWord = true;
}




int main()
{

    int numberOfWords;
    cin>>numberOfWords;
    init();
    while(numberOfWords--) {

        string word;
        cin>>word;
        insertWord(word);

    }

    cout<<counter<<endl;
    
    
   
    return 0;
}
