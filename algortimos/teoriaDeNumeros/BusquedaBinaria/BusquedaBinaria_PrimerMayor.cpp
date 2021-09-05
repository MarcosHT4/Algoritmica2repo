#include <bits/stdc++.h>
using namespace std;
int n;
int x;
int A[100010];

bool f(int number) { //Una funcion con el numero (la mitad).

    return number>x; //Comprobamos si el numero (la mitad) es mayor a x (Modificar)


}

void binarySearch() {

    int ini = 0; //La posicion inicial
    int fin = n-1; //La posicion final

    while(ini<fin) { //Mientras la posicion inical sea menor a la final

        counter++;

        int mid = (ini + fin) /2; //Obtenemos la mitad
        if(f(A[mid])) { //Si la mitad es mayor a x  (Modificar)

            fin = mid; //Cuando la mitad sea mayor a x, toda la derecha es verdadera, por lo que todavia mantenemos el mid, pero ya no usamos el resto de la derecha

        } else {

            ini = mid + 1; //Cuando la mitad sea menor a x, toda la izquierda se vuelve falsa, incluyendo el mid, por lo que ya no usamos ni la izquierda ni el mid

        }

    }

    if(f(A[ini])) {

        cout<<A[ini]<<endl;

    } else {

        cout<<"No hay"<<endl;
    }


}

int main() {

    cin>>n;

    for(int i = 0; i<n; i++) {

        cin>>A[i];

    }

    cin>>x;

    binarySearch();


    return 0;


}



