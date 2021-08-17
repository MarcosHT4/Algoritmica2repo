#include <bits/stdc++.h>

using namespace std;


bool esValido(int tablero[8][8], int fila, int col) {

    for(int i = 0; i<col; i++) {

        if(tablero[fila][i]) { //Verificar si a la izquierda de la reina hay reinas

            return false;

        }

    }

    for(int i = fila, j = col; i>=0 && j>=0; i--, j--) {

        if(tablero[i][j]) {//Verificar si en la diagonal izquierda superior de la reina hay reinas

            return false;

        }

    }

    for(int i = fila, j = col; i<8 && j>=0; i++, j--) {

        if(tablero[i][j]) {//Verificar si en la diagonal izquierda inferior de la reina hay reinas

            return false;

        }

    }

    //No se neceitan más metodos, ya que el método solve, es el que se encargará que solo haya una reina en cada
    //columna, por lo que no es necesario verificar arriba y abajo

    return true;



}

