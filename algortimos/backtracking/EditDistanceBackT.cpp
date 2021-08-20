#include <iostream>
#include<bits/stdc++.h>

using namespace std;

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

    if(a[positionFirst - 1] == b[positionSecond - 1]) {

        return solveDistance(a, b, positionFirst - 1, positionSecond - 1);

    } else {

        return 1+ minimumThree(solveDistance(a,b,positionFirst-1, positionSecond), solveDistance(a,b,positionFirst, positionSecond-1),solveDistance(a,b,positionFirst-1,positionSecond-1)); //Añadir - Quitar -

    }

    //Si las longitudes de ambas palabras, son iguales, entonces hacemos reemplazo
    //Si la primera palabra es mayor que la segunda, añadimos a la segunda
    //Si la segunda palabra es mayor que la primera, quitamos a la segunda



}

int main() {

    cout<<solveDistance("aeo", "ac", 3, 2);


    return 0;
}

//pedro -> ""


//pacvo
//0123
//pavo
//0123



