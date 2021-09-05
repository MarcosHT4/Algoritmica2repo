
#include <bits/stdc++.h>
using namespace std;


int binarySearch(int arr[], int left, int right, int x){



    while (left <= right) { //Mientas al izquierda sea menor o igual a la derecha, si esto es falso, significa que hemos procesado todo el arreglo

        int mid = left + (right - left) / 2; //Obtenemos la mitad del arreglo


        if (arr[mid] == x) { //Si este caso es verdadero, significa que hemos encontrado el elemento, por lo que devolvemos su posición
            return mid;
        }


        if (arr[mid] < x) { //Si el elemento en la mitad del arreglo es menor a x, significa que debemos eliminar el medio y la izquierda
            left = mid + 1;
        }


        else { // Si el elemento en la mitad del arreglo es mayor a x, significa que debemos eliminar el medio y la derecha
            right = mid - 1;
        }
    }


    return -1; //Si llegamos a este caso, significa que no existe el elemento
}

int main(void){

    int arr[] = {}; //El arreglo del cual queremos encontrar un elemento
    int x = 0; //El elemento que queremos encontrar
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "El elemento no está presente en el arreglo"
    : cout << "El elemento está presente en el índice " << result<<endl;

    return 0;
}

