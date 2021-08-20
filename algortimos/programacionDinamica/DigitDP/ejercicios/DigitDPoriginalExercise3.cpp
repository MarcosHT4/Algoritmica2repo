//Contar todos los numeros entre a y b que son divisbles entre 5
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

string number = "307"; //El numero de la derecha, seria como b
int dp[20][2][20]; //20 ya que 10^18 tiene 20 digitos, 2 ya que solo es V o F, y 20 ya que en el peor, todas las posiciones seran pares


int solveDP(int pos, int mayor, int digitoU) {

    if(pos > number.size()) { //Cuando nuestra posicion ya se paso de la cantidad de digitos del numero dado, ya no nos interesa

        return 0;

    }



    if(pos==number.size()) {

        if(digitoU==5 || digitoU==0) {// Si el ultimo digito del numero es divisible entre 5, su ultimo numero va a ser ya sea 5 o 0

            return 1;

        }

        else {

            return 0;

        }

    }

    if(dp[pos][mayor][digitoU]==-1) { //Preguntamos si es que no hemos calculado esta posicion antes

        int tope = 9;  //Si el mayor es false, significa que no existe numero que pueda sobrepasar a number, por lo que se queda en 9

        if(mayor==1) { //Si el mayor es true, significa que el numero que vamos a crear, puede llegar a ser mayor que number

            tope = number[pos] - '0'; //Creamos el tope con la posicion actual que puede llegar a causar conflicto, es decir, solo podemos usar los numeros de 0 a tope

        }

        dp[pos][mayor][digitoU] = 0;

        for(int digito = 0; digito<=tope; digito++) { //Recorremos los digitos hasta tope

            if(digito==tope) {

                dp[pos][mayor][digitoU] += solveDP(pos+1, 1,digito); //Simplemente almacenamos el digito actual, el cual se va a ir reemplazando hasta llegar al ultimo digito


            } else {

                dp[pos][mayor][digitoU] += solveDP(pos+1, 0, digito); //Lo mismo, pero ahora mayor es 0, ya que, no estamos en el tope, y no puede haber un numero mayor a number

            }



        }

    }

    return dp[pos][mayor][digitoU];


}


int main() {

    //Hallar los numeros que tengan 2 pares en su interior

    int a = 1;

    number = to_string(a-1);
    cout<<number<<endl;
    memset(dp,-1, sizeof(dp));
    int paresHastaA = solveDP(0, 1, 0);


    long long b = 15;
    memset(dp,-1, sizeof(dp));
    number = to_string(b);
    int paresHastaB = solveDP(0,1,0);


    cout<<paresHastaB-paresHastaA<<endl;





    return 0;
}

