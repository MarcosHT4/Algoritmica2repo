
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int dp[10000][10000];

int minimumThree(int a, int b, int c) {

    return min(min(a,b),c);

}

int solveDistance(string a, string b, int positionFirst, int positionSecond) {

    if(a==b) {

        return 0;
    }

    if(positionFirst == 0) {

        return positionSecond;

    }

    if(positionSecond == 0) {

        return positionFirst;

    }

    if(dp[positionFirst][positionSecond]==-1) {


        if(a[positionFirst - 1] == b[positionSecond - 1]) {

            dp[positionFirst][positionSecond] = solveDistance(a, b, positionFirst - 1, positionSecond - 1); //Si los caracteres son iguales, no hacemos nada, y solo nos movemos

        } else {

            dp[positionFirst][positionSecond] = 1+ minimumThree(solveDistance(a,b,positionFirst-1, positionSecond), solveDistance(a,b,positionFirst, positionSecond-1),solveDistance(a,b,positionFirst-1,positionSecond-1)); //Añadir - Quitar -

        }

        //Si las longitudes de ambas palabras, son iguales, entonces hacemos reemplazo
        //Si la primera palabra es mayor que la segunda, añadimos a la segunda
        //Si la segunda palabra es mayor que la primera, quitamos a la segunda
    }

    return dp[positionFirst][positionSecond];



}

int main() {

    memset(dp,-1,sizeof(dp));

    cout<<solveDistance("abc", "xbz", 3, 3);


    return 0;
}

//pedro -> ""


//pacvo
//0123
//pavo
//0123



