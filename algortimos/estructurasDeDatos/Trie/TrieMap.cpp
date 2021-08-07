#include <iostream>
#include <bits/stdc++.h>
using namespace std;



struct node {
    
    map<char, node*> mapero;
    bool isWord;

} *trie;

void init() {

    trie = new node();
    trie->isWord = false;

}

void insertWord(string word) {

    node *currentNode = trie;

    for(int i = 0; i< word.length(); i++) {

        if(!currentNode->mapero[word[i]]) {

            currentNode->mapero[word[i]] = new node();

        }

        currentNode->isWord = false;

    }

    currentNode->isWord = true;

}

int main()
{
    
    
    
    return 0;
}
