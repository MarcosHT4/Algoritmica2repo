#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int maxPriority;

struct node {
    char currentCharacter;       
    bool isWord;               
    int countWords = 0; 
    int priority = 0;
    struct node *children[27]; 
}*trie; 

void init() {
    trie = new node();
    trie->isWord = false;
    trie->countWords = 0;
    trie->priority = 0;
}

void insertWord(string word, int priority) {   
    node *currentNode =  trie;  
    for (int i = 0; i< word.length(); i++) {
        int character = word[i] - 'a';       
        if(currentNode->children[character] == NULL ) {
            currentNode->children[character] = new node();
            currentNode->children[character]->countWords = 0;
            currentNode->children[character]->priority = priority;
        
            
        }
        currentNode = currentNode->children[character];
        currentNode->priority = max(currentNode->priority, priority);
        currentNode->currentCharacter = word[i];
        currentNode->countWords++;
        currentNode->isWord = false; 
    }
    currentNode->isWord = true;
}

bool findPrefix(string prefix) {   

    node *currentNode =  trie;  
    for (int i = 0; i< prefix.length(); i++) {
        int character = prefix[i] - 'a';       
        if(currentNode->children[character] == NULL ) {
           return false;
        }
        currentNode = currentNode->children[character];
    }
    maxPriority = currentNode->priority;
    return true;

}





int main()
{

    int numberOfWords,numberOfQueries;
    cin>>numberOfWords>>numberOfQueries;
    maxPriority = 0;
    init();
    while(numberOfWords--) {

        string word;
        int weight;
        cin>>word>>weight;
        insertWord(word, weight);

    }

    while(numberOfQueries--) {

        string query;
        cin>>query;
        if(findPrefix(query)) {

            cout<<maxPriority<<endl;

        }

    }

    
    
    
   
    return 0;
}
