#include <iostream>
using namespace std;

struct node {

    char currentCharacter; //Es el caracter que representa el nodo
    bool isWord = false; //Es el punto que nos dice si es una palabra, es decir, es el nodo que representa el ultimo caracter de una palabra
    int countWords = 0; //Cuantas veces se repite un prefijo
    struct node *children[27]; //El array dentro del nodo que representa al alfabeto, cada elemento del array representa un nodo, si es null, significa que no tiene un hijo con ese caracter


}*trie;

void init() {

    trie = new node(); //Inicializamos con un nodo vacio (array del nodo vacio)
    trie->isWord = false; //Tampoco es palabra
    trie->countWords = 0; //Como esta vacio, tampoco tiene contador 

}

void insertWord(string word) {

    node *currentNode = trie; //Nos ponemos en el nodo inicial del trie
    for(int i = 0; i<word.length(); i++) { //Recorremos las letras de la palabra ("alto" por ejemplo)

        int character = word[i] - 'a';//Obtenemos el valor del caracter

        if(currentNode->children[character]==NULL) { //Si no existe el nodo del caracter como hijo del nodo actual, lo creamos (si existe, directamente se pasa a ponerlo como currentNode)

            currentNode -> children[character] = new node();
            currentNode -> children[character]-> countWords = 0;

        }

        currentNode = currentNode->children[character]; //El nodo actual se vuelve el nodo que representa el caracter actual
        currentNode->currentCharacter = word[i]; //Le recordamos el caracter que representa
        currentNode->countWords++; //Aumentamos el contador de prefijo, es decir, ahora este prefijo es utilizado una vez


    }

    currentNode->isWord = true; //Este si que es el ultimo caracter de la palabra, por lo tanto, si es palabra


}

bool searchWord(string word) { //Buscar si existe la palabra

    node *currentNode  = trie; //Nos ponemos en el nodo inicial
    for(int i = 0; i<word.length(); i++) {

        int character = word[i] - 'a'; //Obtenemos el valor del careacter

        if(currentNode->children[character]==NULL) { //Si uno de los caracteres no existe, significa que no existe la palabra

            return false;

        }

        currentNode = currentNode->children[character]; //El nodo actual se el nodo que representa el caracter actual



    }

    return currentNode->isWord; //Si llegamos al final (es decir, habia todos los prefijos), la palabra existe solo si el ultimo nodo dice: Es palabra



}

int findWords(string prefix) {    // Para poder saber cuantas veces se utiliza un prefijo en el trie

    node *currentNode =  trie;  //Nos ponemos en el nodo inicial

    for (int i = 0; i< prefix.length(); i++) {

        int character = prefix[i] - 'a';  

        if(currentNode->children[character] == NULL ) {  // Si uno de los nodos que representan los prefijos no existe, entonces no existe el prefijo completo

           return 0;
        }

        currentNode = currentNode->children[character]; //El nodo actual se vuelve el nodo que representa el caracter actual
    }

    return currentNode->countWords; //Si logramos llegar al ultimo nodo, nos devuelve su valor de countWords
}



void isThereWord(string word) {

    if(searchWord(word)) {

        cout<<"Si existe: "<< word << " en el trie "<<endl;

    } else {

        cout<<"No existe xd" << endl;

    }

}


int main()

{

    init();
    string word = "ala";
    string word1 = "alan";
    insertWord(word);
    isThereWord(word);
    insertWord(word1);
    isThereWord(word1);
    isThereWord(word);







int main() {



    
    
    
    return 0;
}
