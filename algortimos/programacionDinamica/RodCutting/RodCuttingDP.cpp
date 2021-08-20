#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int length[] = {1,3,5,7}; //Los tamaños en los que se puede partir la barra
int precios[] = {20,15,30,50}; //Los precios de cada corte de la barra

int dp[1000000];

//Vamos a usar topDown

int solveDP(int sizeBarra) {

    if(sizeBarra==0) { //Si el tamano es 0, no hay ganancia

        return 0;

    }

    if(dp[sizeBarra]==-1) { //Si nunca hemos calculado la porcion de la barra

        int gananciaMaxima = -1; //Empezamos no teniendo ganancias para un corte en especifico

        for(int i = 0; i<sizeof(length)/sizeof(length[0]); i++) { //Ahora, iteramos por todos los cortes que se podrian llegar realizar {1,3,5,7}

            if(sizeBarra>=length[i]) { //Si podemos realizar el corte de la barra

                gananciaMaxima=max(gananciaMaxima,precios[i] + solveDP(sizeBarra-length[i])); //Para la segunda parte tel max, la ganancia se va a volver la ganancia actual mas la ganncia del corte que se esta haciendo actualmente. Ej. Calculamos la ganancia de la barra de 10, y luego de una barra de 9 si el corte es de 1
                //Posteriormente, obtenemos el maximo entre la ganancia que se tiene el momento (de un anterior corte) y la nueva ganancia
            }

        }

        dp[sizeBarra] = gananciaMaxima;

    }

    return dp[sizeBarra];

}

int main() {

    memset(dp,-1,sizeof(dp));

    cout<<solveDP(10)<<endl;


    return 0;
}

