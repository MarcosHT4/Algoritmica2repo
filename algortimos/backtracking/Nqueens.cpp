#include <bits/stdc++.h>

using namespace std;

# define N 4

bool esValido(int tablero[N][N], int fila, int col) { //Queremos poner una reina en la posicion fila,col; pero queremos saber si es que hay reinas que choquen

    for(int i = 0; i<col; i++) {

        if(tablero[fila][i]) { //Verificar si a la izquierda de la reina hay reinas, partimos desde la mas izquierda de la fila, y vamos avanzando hacia la derecha, buscando reinas

            return false;

        }

    }

    for(int i = fila, j = col; i>=0 && j>=0; i--, j--) {

        if(tablero[i][j]) {//Verificar si en la diagonal izquierda superior de la reina hay reinas

            return false;

        }

    }

    for(int i = fila, j = col; i<N && j>=0; i++, j--) {

        if(tablero[i][j]) {//Verificar si en la diagonal izquierda inferior de la reina hay reinas

            return false;

        }

    }

    //No se neceitan más metodos, ya que el método solve, es el que se encargará que solo haya una reina en cada
    //columna, por lo que no es necesario verificar arriba y abajo

    return true;



}

bool solve_queen(int tablero[N][N],int col) { //Seria el metodo f()

    if(col>=N) { //Ya se pusieron todas las reinas, caso base, final de el proceso entero

        return true;

    }

    for(int i = 0; i<N; i++) { //Nos va a servir para ser backtracking, es decir, para borrar una reina, e ir a la siguiente fila en la misma columna a poner la siguiente

        if(esValido(tablero, i, col)) {

            tablero[i][col] = 1; //Por el momento, no hay una reina la cual se choque con la que ponemos, pero ojo, esto puede llegar a cambiar (backtracking)

            if(solve_queen(tablero, col+1)) { //Verifica si en la siguiente columna se puede poner la reina, obviamente este metodo se va a llamar muchsa veces para las posteriores posiciones

                return true; //Solo va a pasar esto si el ultimo llamado llega al caso base, es decir, esto indica que todo ha terminado

            }

            tablero[i][col] = 0; //En el caso de que todo el llamado recursivo termine en false, hacemos backtracking y quitamos la reina, posteriormente el for pondra la reina en la siguiente fila de la columna


        }



    }

    return false; //Si no se pudo poner la reina en ninguna de las filas de la columna, el metodo devuelve false


}

void printSolution(int tablero[N][N]) {

    for(int i = 0; i<N; i++) {

        for(int j = 0; j<N; j++) {

            cout<<tablero[i][j]<<endl;

        }

    }

}
