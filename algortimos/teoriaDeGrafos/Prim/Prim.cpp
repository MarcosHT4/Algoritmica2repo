#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;
bool visited[MAX];
vector<pair<long long, int>> graph[MAX];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> colaPrioridad;

long long primMST(int x) {

    int vecinos; //Variable que se utilizará para guardar a los vecinos de los nodos

    long long pesoTotal = 0;

    pair<long long, int> nodoActual; //Creamos una variable para el vertice actual junto a su peso

    colaPrioridad.push(make_pair(0, x)); //Ponemos a la cola de prioridad nuestro primer vertice, junto con peso 0
    while(!colaPrioridad.empty()) { //Mientras la cola de prioridad no esté vacía, significa que todavía se está procesando el árbol

        nodoActual = colaPrioridad.top(); //El primer elemento de la cola de prioridad es el elemento que se debe procesar a continuación, por lo que lo guardamos
        colaPrioridad.pop(); //Luego lo quitamos de la cola de prioridad
        x = nodoActual.second; //Guardamos en la variable x, el vértice.

        if(visited[x]) { //Si ya hemos visitado el vértice, no hacemos nada, y vamos al siguiente

            continue;

        }

        pesoTotal+= nodoActual.first; //En el caso de que no lo hayamos visitado, entonces sumamos su peso al pesoTotal, y luego lo marcamos como visitado
        visited[x] = true;

        for(int i = 0; i<graph[x].size(); i++) { //Ahora, usando el grafo, iteraremos por todos los vecinos del vértice actual

            vecinos = graph[x][i].second; //En la variable antes definida, guardamos el vecino actual
            if(!visited[vecinos]) { //Si el vecino no lo hemos visitado, pues lo ponemos en la colaDePrioridad (no lo marcamos como visitado, ya que todavia hay que procesarlo)

                colaPrioridad.push(graph[x][i]);

            }

        }

    }

    return pesoTotal;


}

int main() {

    int n, m;

    cin>>n>>m;

    int x, y, peso;

    for(int i = 0; i<m; i++) {

        cin>>x>>y>>peso;

        graph[x].push_back(make_pair(peso,y));
        graph[y].push_back(make_pair(peso,x));

    }

    long long minCost = primMST(0); //Reemplazar con cualquiera de los nodos en el grafo
    cout<<minCost<<endl;


    return 0;
}

