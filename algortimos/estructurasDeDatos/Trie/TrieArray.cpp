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


/*
 *  El metodo deleteWord() puede ser implementado de dos maneras distintas: La primera es ir al final de una palabra, y en su ultimo nodo, quitarle
 *  el estado de isWord. La segunda manera es directamente poner en NULL los nodos que pertenecen a la palabra. Se veran las dos implementaciones.
 */


void deleteWord1(string word) {

    node *currentNode = trie; //Nos ponemos en el primer nodo del Trie

    for(int i = 0; i<word.size(); i++) { //Iteramos en todos los caracteres de la palabra

        int character = word[i] - 'a'; //Guardamos en formato entero (0-26) el caracter actual

        if(currentNode->children[character] == NULL) { //Si el nodo actual no contiene como hijo nuestro caracter actual, significa que directamente no hay palabra, por lo que no devolvemos nada

            return;

        }

        currentNode = currentNode->children[character]; //En caso de que si lo contenga, nos movemos al hijo, es decir, nuestro actual se vuelve el hijo

    }

    currentNode->isWord = false; //Si llegamos al final, significa que hemos encontrado ya sea una palabra o un prefijo, por lo que en todo caso, quitamos el isWord

}

bool hasChildren(node* node) {

    for(int i = 0; i<26; i++) {

        if(node->children[i]) {

            return true;

        }

    }

    return false;

}

node* deleteWord2(node *currentNode, string word, int level) { //Necesitamos un level para poder guardar constancia de la profundidad del Trie


    if(level == word.length()) { //Caso Base, si llegamos al final de la palabra

        if(currentNode->isWord) {

            currentNode->isWord = false; //Si el ultimo nodo representa una palabra, entonces lo volvemos false

        }

        if(!hasChildren(currentNode)) { //Si el nodo actual no tiene hijos, significa que lo podemos borrar, ya que no es parte de otra palabra la cual no queremos borrar

            delete(currentNode); //Borramos el nodo
            currentNode = nullptr;

        }

        return currentNode;



    }  //Si no, significa que todavia estamos en otra parte de la palabra

    int character = word[level] - 'a'; //Guardamos el caracter que representa el nivel actual de la palabra
    currentNode->children[character] = deleteWord2(currentNode->children[character],word, level+1); //Recursivamente, seguimos al siguiente caracter de la palabra con un siguiente nivel

    if(!hasChildren(currentNode) && !currentNode->isWord) { //Una vez terminada la recursividad, se verifica si el nodo padre todavia tiene hijos, si tiene significa que es parte de otra palabra, por lo tanto no lo borramos

        delete(currentNode);
        currentNode = nullptr;


    }

    return currentNode;


}

int main()

{

    init();

    /* Test Case deleteWord1()


    string word = "ala";

    insertWord(word);
    isThereWord(word);
    deleteWord1(word);
    isThereWord(word);

     */

    /* Test Case deleteWord2()

    string word = "pata";
    string word1 = "patada";

    node *currentNode = trie;
    insertWord(word);
    insertWord(word1);
    isThereWord(word);
    isThereWord(word1);
    deleteWord2(currentNode, word1, 0);
    isThereWord(word);
    isThereWord(word1);

     */





}
