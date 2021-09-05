#include <bits/stdc++.h>
using namespace std;
#define MAX_N 101

int grafo[MAX_N][MAX_N];
int path[MAX_N];


int maxFlow(int s,int t) {
    // s nodo inicial
    // t nodo final
    int maxFlow = 0;
    while(true) {
        //BFS
        memset(path, -1, sizeof(path)); //Todavia no hemos visitado
        queue<int> Q; //Creamos la cola
        Q.push(s); //Añadimos el nodo s (el nodo fuente)
        path[s] = s; //Añadimos el nodo al camino
        while(!Q.empty() && path[t]==-1) { //Recorremos la pila siempre que no este vacia
            int currentNode = Q.front(); //Obtenemos el nodoActual
            Q.pop(); //Lo sacamos de la cola
            for(int i = 0 ; i < MAX_N ; i++) { //Iteramos a los vecinos del nodoActual
                if(path[i]==-1 && grafo[currentNode][i] > 0) {  // La capacidad de esa arista es mayor a 0, y ademas, el nodo esta visistado?
                    path[i] = currentNode;                       // El nodo actual se convierte en el primer nodo que veamos
                    Q.push(i);                                  // Ese nodo lo ponemos a la cola (el vecino)
                }
            }
        }


        if(path[t]==-1) { //Nos preguntantamos si todo el proceso a llegado a T, ya que el path nos dice que ya no hay camino
            break;
        }
        int minFlow = 1e9; //Creamos una variable para almacenar la variable minima del recorrido

        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {
            minFlow = min(minFlow,grafo[from][to]); //El minimo se convierte en el minimo de todos los pesos de las aristas que hemos recorrido
        }

        // Sumar y restar ese minimo                                            // sumar todos os diferentes a -1
        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {

            grafo[from][to] -= minFlow;  //Posteriormente le restamos esa cantidad minima, al grafo real
            grafo[to][from] += minFlow; //Y al grafo residual le sumamos esa cantidad minima

        }

        maxFlow += minFlow; //Vamos sumando al maximo flujo

    }
    return maxFlow;
}



int main() {

    int nodes, aristas, nroCases = 1;
    while(cin>>nodes && nodes) {
        int s,t; //s es el nodo incial (fuente), t es el ultimo nodo (terminal)
        cin >> s >> t >> aristas;
        memset(grafo,0,sizeof(grafo));
        for(int i=0; i < aristas; i++) {
            int from, to, capacity;   //Pedimos el nodo inicial, el final y la capacidad
            cin>>from>>to>>capacity;
            grafo[from][to] = capacity;          // camino capacidad
            grafo[to][from] = 0;                //  flujo camino residual
        }
        cout<<maxFlow(s,t)<<endl; //Mandamos e imprimimos el maximo flujo
    }
}
