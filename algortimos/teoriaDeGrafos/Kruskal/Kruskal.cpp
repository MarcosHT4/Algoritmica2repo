#include <bits/stdc++.h>


#define MAX_N 10000 //Se refiere al maximo numero de nodos que tiene el problema

using namespace std;

int parent[MAX_N]; //
int rango[MAX_N];  // Ambos parent y rango son parte del Union Find

int n, m; //n numero de nodos, m numero de aristas

void init() { //Hacemos inicializacion del Union Find
    for(int i=0;  i<= MAX_N; i++) {
        parent[i] = i; //Todo nodo es padre de si mismo
        rango[i] = 0; //Todo nodo tiene rango cero
    }
}

int find(int x) { //Metodo find de Union Find
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

bool sameComponent(int nodeA,int nodeB) {
    return find(nodeA) == find(nodeB); //Sirve para comprobar si los nodos crean un ciclo, nos preguntamos si los nodos tienen los mismos padres, es decir, pertenencen al mismo grupo.
}


void unionRango(int x,int y) { //Metodo union de Union Find
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

struct Arista{ //Nos creamos una estructura, la cual va a contener una arista con: NodoInicio, NodoFinal y Peso
    int origen; //NodoInicio
    int destino; //NodoFinal
    double peso; //Peso de la arista
    Arista(){} //Constructor

    bool operator<(const Arista &a) const { //Creamos una sobrecarga del operador menor, el cual modifica la funcion sort, para que la funcion ordene a partir del peso de menor a mayor

        if(peso == a.peso) { //En el caso de que los pesos son iguales, ordenamos de mayor a menor a partir del origen

            return origen < a.origen;

        }

        return peso < a.peso;
    }
}aristas[MAX_N]; //Creamos un array de aristas, este sera el grafo inicial que se mande en el main

Arista MST[MAX_N]; //Arreglo que representa el arbol de expansion minima, que se va creando en el proceso

int numAristasArbol = 0; //Creamos una variable para almacenar el numero de aristas que tendrá el arbol de expansión mínima

double kruskal(int nroNodos, int nroAristas) { //Creamos el metodo Kruskal con el numero de nodos y el numero de aristas (N y M)

    int origen, destino; //Creamos variables para luego almacenar los datos de la arista
    double peso;

    double total = 0; //Este va a ser el total del arbol de expansion minimo, todo el peso



    init(); // Inicializamos el union Find

    sort(aristas,aristas + nroAristas);  // Haciendo este paso, ordenamos las aristas (el arreglo de aristas de arriba) de menor a mayor, en base al peso.

    for (int i = 0; i < nroAristas; i++) //Recorremos cada una de las aristas
        {
        origen = aristas[i].origen; //Ponemos todos los datos en variables
        destino = aristas[i].destino;
        peso = aristas[i].peso;

        if(!sameComponent(origen,destino)) { //Nos preguntamos si el origen y el destino crean un ciclo (están en el mismo componente), si crea, nos saltamos el paso, ya que no debe haber ciclos
            total+=peso; //Si entra, no forma un ciclo, y se suma el peso de arista al peso total
            unionRango(origen,destino); //Hacemos union de los nodos, esto nos sirve para luego comprobar si no existe un ciclo con una arista futura
            MST[numAristasArbol] = aristas[i]; //Aqui añadimos la arista actual en la posicion actual en el arreglo que representa el arbol de expansion minima
            numAristasArbol++; //Incrementamos la posicion para la proxima arista que venga
        }
        }
    return total; //Aqui se devuelve el peso total del arbol de expansion minima
}



int main(){



    while(cin>>n>>m) {

        for(int i = 0; i<m; i++) {

            cin>>aristas[i].origen>>aristas[i].destino>>aristas[i].peso; //Pedimos todas las aristas, el for se ocupa de cambiar de arista

        }

        cout<<kruskal(n,m)<<endl; //Imprimimos el valor del total del arbol de expansion minima

        for(int i = 0; i<numAristasArbol; i++) { //Imprimimos todo el arbol de expansion minima

            cout<<" "<<MST[i].origen<<" "<<MST[i].destino<<" "<<MST[i].peso<<endl;

        }

    }

    return 0;
}


