#include <bits/stdc++.h>
using namespace std;

int BIT[10001];
int tamanhoVector;

void update(int posicion, int valor ) { //Sirve para ya sea poder crear o actualizar el BIT, nos pasan las posiciones y los valores de la siguiente manera:
    // valores = [4,6,3,2,5]
    // posiciones = [1,2,3,4,5], ya que la posicion 0 esta reservada para el nodo fantasma
    for(;posicion <= tamanhoVector ;posicion += posicion&-posicion) { //Empezamos en la posicion del valor actual (se van cambiando los valores en el main)
        //Posteriormente, en esa posicion, añadimos el valor corresponidiente.
        BIT[posicion] += valor;                                       //La posicion del BIT donde se guardan los valores, va cambiando, ya que se le suna a la posicion, su bit menos significativo
    }                                                                 //Cada uno de los numeros que representan las posiciones, se ven representados en el dibujo como las rayas
}

int query(int posicion){ // F(x) = 0+....+x                       //En el query,queremos desde 0 hasta posicion

    int result = 0 ;

    for(;posicion > 0 ;posicion -= posicion&-posicion) {        //Partimos desde la posicion, es decir, desde el numero mas alto, y desde ahi, le vamos quitando su bit menos significativo, hasta llegar al nodo fantasma
        //Esto es asi, ya que, hay que recordar que la posicion del padre de un nodo equivale a PosicionPadre = PosicionHijo - BMS(PosicionHijo)
        result += BIT[posicion];

    }
    return result;
}

int query2(int inicio, int final) {

    return query(final)-query(inicio-1);
}

int main() {

    int queries;

    cin>>tamanhoVector>>queries;

    for(int i=0;i<tamanhoVector;i++) {

        int x;cin>>x;

        update(i+1, x);
    }
    for(int i =0 ;i<= tamanhoVector; i++){

        cout<<"["<< BIT[i]<<"]";
    }
    cout<<endl;

    while(queries--) {

        int x,y; cin>>x>>y;

        cout<<query2(x,y)<<endl;
    }
    return 0;
}




