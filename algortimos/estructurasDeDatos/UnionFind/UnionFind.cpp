#include <bits/stdc++.h>
using namespace std;


int parent[10000];
int rango[10000];

const int n;
void init() {
    for(int i=0;  i<= n; i++) {
        parent[i] = i;
        rango[i] = 0;
    }
}

int find(int x) { //Nos encuentra el padre mas alto, el decir, el padre de todos los nodos.
    if(x == parent[x]) { //Si x = parent[x] significa que un nodo es padre de si mismo, es decir, es el padre mas alto, por lo que lo devolvemos
        return x;
    }
    else {
        parent[x] = find(parent[x]); //Con esto hacemos que todos los hijos se vuelvan hijos del padre mas alto, para poder compactar el arbol
        return parent[x]; //Si no, significa que los nodos todavia tienen padres distintos, por lo que recursivamente nos vamos al padre de nodo, para consultar al padre del padre
    }
}

void unionRango(int x,int y) {  //Sirve igualmente para hacer una union, pero nos ayuda a que el arbol no se desbalancee
    int xRaiz = find(x); // Encontramos el padre mas grande de x, tambien nos ayuda a compactar el arbol.
    int yRaiz = find(y); //Encontramos el padre mas grande de y. Es decir, en vez de unir los nodos en si, unimos los padres mas grandes.
    if(rango[xRaiz] > rango[yRaiz]) { //Si el nodo x tiene mas niveles por abajo que y
        parent[yRaiz] = xRaiz; //x se vuelve el padre de y, solo eso
    } else { //Si no significa que o y tiene mas niveles que x, o que x & y tienen la misma cantidad de niveles
        parent[xRaiz] = yRaiz; //En todo caso, y se vuelve el padre de x, y se queda hasta aqui si y tiene mas niveles de x
        if(rango[xRaiz] == rango[yRaiz]){ //Pero, si y & x tienen los mismos niveles
            rango[yRaiz]++; //El rango de y aumenta, porque tenian niveles iguales, por lo que minimo, el rango de y tiene que aumentar por uno

        }
    }
}
}

int main() {
    input;
    cin>>n;
    init();
    int nrounionRangoes;
    cin>>nrounionRangoes;
    while(nrounionRangoes--) {
        int x,y;
        cin>>x>>y;
        unionRango(x,y);
    }
    for(int i=0;i<=n;i++){
        cout<<"["<<i<<"] ";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<"[" <<parent[i]<<"] ";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<"[" <<rango[i]<<"] ";
    }
    cout<<endl;


    return 0;
}







