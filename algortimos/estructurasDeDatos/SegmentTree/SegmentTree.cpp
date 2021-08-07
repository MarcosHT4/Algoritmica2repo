
#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int nums []  = {5,4,7,8,3,2,-1,-6,5,4,6};

struct node {

    int minimo; //Variable para los queries de minimo
    int maximo; //Variable para los queries de maximo
    int suma; //Varaible para los queries de suma


}segmentTree[1000000]; //El array de nodos, en donde se guardara el segment tree

void init(int ini, int fin, int currentNode) { //Necesitamos 3 valores, desde donde vamos a empezar (0), hasta donde vamos a ir (tamaño del arreglo original) y cual es el nodo actual

    if(ini==fin) { //El caso base es cuando ini==fin, ya que significa que el nodo ya no guarda el minimo de un intervalo, si no un solo numero, la base del arbol

        segmentTree[currentNode].minimo = nums[ini]; //Debido a que solo hay un numero, lo guardamos en el segment tree como minimo
        segmentTree[currentNode].maximo = nums[ini]; //Debido a que solo hay un numero, lo guardamos en el segment tree como maximo
        segmentTree[currentNode].suma = nums[ini]; //Debido a que solo hay un numero, lo guardamos en el segment tree como suma

    } else { //Si ini y fin no son iguales, significa que estamos en algun nodo de arriba que almacena el minimo de un intervalo

        int medio = (ini + fin)/2; //Obtenemos la mitad de ini y fin
        int hijoIzquierda =  2*currentNode+1; //Se sabe que 2*nodoActual+1 devuelve el hijo de la izquierda
        int hijoDerecha = 2*currentNode+2; //Se sabe que 2*nodoActual+2 devuelve el hijo de la derecha
        init(ini, medio, hijoIzquierda); //Llamamos recursivamente a init para el hijo de la izquierda, ya que su intervalo siempre es [0-n/2]
        init(medio+1, fin, hijoDerecha); //Llamamos recursivamente a init, para el hijo de la derecha, ya que su intervalo siempre es [n/2 + 1 - n ]

        segmentTree[currentNode].minimo = min(segmentTree[hijoIzquierda].minimo, segmentTree[hijoDerecha].minimo); //Actualizamos el nodo actual, ya que su valor es el minimo de los valores de sus hijos
        segmentTree[currentNode].maximo = max(segmentTree[hijoIzquierda].maximo, segmentTree[hijoDerecha].maximo); //Actualizamos el nodo actual, ya que su valor es el maximo de los valores de sus hijos
        segmentTree[currentNode].suma = segmentTree[hijoIzquierda].suma + segmentTree[hijoDerecha].suma;


    }


}

node query(int ini, int fin, int currentNode, int i, int j) { //ini y fin = Inicio y final del arreglo de numeros, i,j = Intervalo del query, min(i,j)

    if(ini >= i && fin<=j) { //Caso base, en el que nuestro rango de (i,j) es igual o mayor al tamaño que hemos designado para el arreglo

        return segmentTree[currentNode]; //Debido a que es caso base, nos devuelve el valor que queriamos

    } else { //Si el rango de (i,j) no esta dentro del intervalo del arreglo

        int medio = (ini + fin)/2;  //Obtenemos la mitad de ini y fin para poder ver por cual rama ir
        int hijoIzquierda =  2*currentNode+1; //Se sabe que 2*currentNode+1 devuelve el hijo de la izquierda
        int hijoDerecha = 2*currentNode+2; //Se sabe que 2*currentNode+2 devuelve el hijo de la derecha

        if(j<=medio) { //Si el lado derecho es menor al medio

            return query(ini, medio, hijoIzquierda, i,j); //Nos vamos por la derecha, ya que eliminamos el lado de la izquierda


        } else if(i>medio) { //Si el lado izquierdo es mayor al medio, no nos sirve el lado izquierdo

            return query(medio +1, fin, hijoDerecha, i,j); //Nos vamos por la derecha, ya que eliminamos el lado de la izquierda

        } else { //Si el rango de (i,j) esta en dos ramas diferentes

              node queryIzq = query(ini, medio, hijoIzquierda, i,j); //Obtenemos el query por la rama de la izquierda
              node queryDer = query(medio+1, fin, hijoDerecha, i, j); // Obtenemos el query por la rama de la derecha

              node resultado;
              resultado.minimo = min(queryIzq.minimo, queryDer.minimo); //Obtenemos el minimo entre amobs queries
              resultado.maximo = max(queryIzq.maximo, queryDer.maximo); //Obtenemos el maximo entre ambos queries
              resultado.suma = queryIzq.suma + queryDer.suma;
              return resultado;

        }




    }


}

int main() {

    init(0,10,0); //El primer nodo es el de la posicion 0, el utlimo nodo esta en la posicion 7 y el nodo actual empieza en la posicion 0
    cout << query(0,10,0,0,10).suma<<endl; //Queremos el minimo

    return 0;

}