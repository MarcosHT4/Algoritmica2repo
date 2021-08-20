#include <iostream>
#include<bits/stdc++.h>

using namespace std;

string number; //El numero de la derecha, seria como b
int dp[20][2][20]; //20 ya que 10^18 tiene 20 digitos, 2 ya que solo es V o F, y 20 ya que en el peor, todas las posiciones seran pares

int solveDP(int pos, int mayor, int pares) {

    if(pos > number.size()) { //Cuando nuestra posicion ya se paso de la cantidad de digitos del numero dado, ya no nos interesa

        return 0;

    }



    if(pos==number.size()) {

        if(pares==2) { //Tiene dos pares el numero?

            return 1;

        }

        else {

            return 0;

        }

    }



    if(dp[pos][mayor][pares]==-1) { //Preguntamos si es que no hemos calculado esta posicion antes

        int tope = 9;  //Si el mayor es false, significa que no existe numero que pueda sobrepasar a number, por lo que se queda en 9

        if(mayor==1) { //Si el mayor es true, significa que el numero que vamos a crear, puede llegar a ser mayor que number

            tope = number[pos] - '0'; //Creamos el tope con la posicion actual que puede llegar a causar conflicto, es decir, solo podemos usar los numeros de 0 a tope

        }

        dp[pos][mayor][pares] = 0; //Inicializamos la posicion en la matriz

        for(int digito = 0; digito<=tope; digito++) { //Recorremos los digitos hasta tope

            if(digito==tope) {


                dp[pos][mayor][pares] += solveDP(pos+1, 1,pares + (digito%2==0)); //Si estamos en el tope, significa que puede haber un numero mayor, por lo que mayor es 1, pasamos a la siguiente posicion y añadimos 1 si el digito es un par


            } else {

                dp[pos][mayor][pares] += solveDP(pos+1, 0,pares + (digito%2==0)); //Lo mismo, pero ahora mayor es 0, ya que, no estamos en el tope, y no puede haber un numero mayor a number

            }



        }

    }

    return dp[pos][mayor][pares];


}


int main() {

    //Hallar los numeros que tengan 2 pares en su interior

    int a = 10;

    number = to_string(a-1);
    memset(dp,-1, sizeof(dp));
    int paresHastaA = solveDP(0, 1, 0);
    int b = 20;
    memset(dp,-1, sizeof(dp));
    number = to_string(b);
    int paresHastaB = solveDP(0,1,0);
    cout<<paresHastaB-paresHastaA<<endl;




    return 0;
}
