/*
 Petar 'PetarV' Velickovic
 Algorithm: Dinic's Algorithm
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#define MAX_N 500
#define INF 987654321
using namespace std;
typedef long long lld;

struct Node
        {
    vector<int> adj;
        };
Node graf[MAX_N];

struct Edge
        {
    int u, v, cap;
    int flow;
        };
vector<Edge> E;

int v, e;
int s, t;
int dist[MAX_N];
int upTo[MAX_N];

int idd = 0;

//Dinicov algoritam za nalazenje maksimalnog protoka izmedju dva cvora u grafu
//Slozenost: O(V^2 * E)

inline bool BFS()
{
    for (int i=1;i<=v;i++) dist[i] = -1; //Toma todos los niveles y lo pone en -1
    queue<int> bfs_queue; //Crea la cola bfs
    bfs_queue.push(s);
    dist[s] = 0;
    while (!bfs_queue.empty())
    {
        int xt = bfs_queue.front();  //Guarda el nodo actual
        bfs_queue.pop();  //Quita el nodo
        for (int i=0;i<graf[xt].adj.size();i++) //Recorremos los vecinos
            {
            int currID = graf[xt].adj[i];
            int xt1 = E[currID].v;
            if (dist[xt1] == -1 && E[currID].flow < E[currID].cap) //Preguntamos si podemos agregar al vecino
                {
                bfs_queue.push(xt1); //Ponemos al vecino en la cola
                dist[xt1] = dist[xt] + 1; //Aumentamos la distancia en uno (los niveles)
                }
            }
    }
    return (dist[t] != -1); //Se pregunta si es que hemos llegado a t, es decir, existe un camino de s a t.
}

inline int DFS(int xt, int minCap)
{
    if (minCap == 0) return 0; //Pregunta si la capacidad minima es cero
    if (xt == t) return minCap;
    while (upTo[xt] < graf[xt].adj.size())
    {
        int currID = graf[xt].adj[upTo[xt]];
        int xt1 = E[currID].v;
        if (dist[xt1] != dist[xt] + 1)
        {
            upTo[xt]++;
            continue;
        }
        int aug = DFS(xt1, min(minCap, E[currID].cap - E[currID].flow));
        if (aug > 0)
        {
            E[currID].flow += aug;
            if (currID&1) currID--; else currID++;
            E[currID].flow -= aug;
            return aug;
        }
        upTo[xt]++;
    }
    return 0;
}

inline int Dinic()
{
    int flow = 0;
    while (true)
    {
        if (!BFS()) break;
        for (int i=1;i<=v;i++) upTo[i] = 0; //Creamos un for para todos los DFS
        while (true) //Este while se ocupara de obtener absolutamente todos los caminos DFS
            {
            int currFlow = DFS(s, INF); //El currflow se vuelve el DFS, buscamos los caminos partiendo desde s
            if (currFlow == 0) break; //Si ya no hay caminos, rompemos todo el proceso DFS
            flow += currFlow; //Añadimos al flujo maximo
            }
    }
    return flow;
}

inline void addEdge(int u, int v, int cap) //Crea una arista
{
    Edge E1, E2;

    E1.u = u, E1.v = v, E1.cap = cap, E1.flow = 0;
    E2.u = v, E2.v = u, E2.cap = 0, E2.flow = 0;

    graf[u].adj.push_back(idd++);
    E.push_back(E1);
    graf[v].adj.push_back(idd++);
    E.push_back(E2);
}

int main()
{
    v = 4, e = 5;
    s = 1, t = 4;

    addEdge(1, 2, 40);
    addEdge(1, 4, 20);
    addEdge(2, 4, 20);
    addEdge(2, 3, 30);
    addEdge(3, 4, 10);

    printf("%d\n",Dinic());

    return 0;
}
