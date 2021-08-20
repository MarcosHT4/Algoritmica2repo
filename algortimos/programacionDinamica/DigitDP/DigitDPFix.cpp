#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

// el numero maximo sera 10^18
// 1000000000000000000
string number = "307"; //El numero de la derecha, seria como b
int dp[20][2][20][200]; //20 ya que 10^18 tiene 20 digitos, 2 ya que solo es V o F, y 20 ya que en el peor, todas las posiciones seran pares



int solve_dp(int pos, int mayor,int pares, int suma) {
    if(pos > number.size()) { //Cuando nuestra posicion ya se paso de la cantidad de digitos del numero dado, ya no nos interesa
        return 0;
    }

    if(pos == number.size()) {

        if(pares == 2) { //Tiene dos pares el numero?

            return 1;

        }
        else {

            return 0;
        }
    }
    if(dp[pos][mayor][pares][suma] == -1) {//Preguntamos si es que no hemos calculado esta posicion antes

        int tope = 9; //Si el mayor es false, significa que no existe numero que pueda sobrepasar a number, por lo que se queda en 9

        if(mayor == true) {  //Si el mayor es true, significa que el numero que vamos a crear, puede llegar a ser mayor que number

            tope = number[pos]-'0';  //Creamos el tope con la posicion actual que puede llegar a causar conflicto, es decir, solo podemos usar los numeros de 0 a tope

        }
        dp[pos][mayor][pares][suma] = 0; //Inicializamos la posicion de la matriz

        for(int digito = 0; digito <= tope; digito++) {

            if(digito == tope ) {

                int total= suma +digito;
                int esPar = (total > 0) && (digito%2 == 0);
                dp[pos][mayor][pares][suma] += solve_dp(pos+1, true, pares + esPar, total ); //Si estamos en el tope, significa que puede haber un numero mayor, por lo que mayor es 1, pasamos a la siguiente posicion y añadimos 1 si el digito es un par
            }
            else { // 0 1 2
                //cout<<pares<<" "<<digito<<" "<< (digito%2 == 0) <<endl;
                int total = suma + digito;
                int esPar = (total > 0) && (digito%2 == 0);
                dp[pos][mayor][pares][suma] += solve_dp(pos+1, false, pares + esPar, total); //Lo mismo, pero ahora mayor es 0, ya que, no estamos en el tope, y no puede haber un numero mayor a number
            }
        }
    }
    return dp[pos][mayor][pares][suma];
}



int main(){

    // hallar los numeros que tengan 2 pares en su interior del rango 20 hasta 30

    int  a = 10;
    int b = 20;
    // calculando f(a)
    number = to_string(a-1);
    memset(dp, -1, sizeof(dp));
    int pares_hasta_a = solve_dp(0, true, 0,0);
    // calculando f(b)
    memset(dp, -1, sizeof(dp));
    number = to_string(b);
    int pares_hasta_b = solve_dp(0, true, 0, 0);
    // total para f(a,b) = f(b) - f(a-1)
    cout<< pares_hasta_b-pares_hasta_a;
    return 0;
}
