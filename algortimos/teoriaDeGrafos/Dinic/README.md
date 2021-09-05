# Dinic

En el mundo de la informática, el algoritmo de Dinic, es un algoritmo
de la teoría de grafos que sirve para poder encontrar el flujo máximo en
una red de flujo. Tal y como lo hace Edmonds Karp, el algoritmo de Dinic es capaz de solucionar los problemas 
más básicos que trae el algoritmo de Ford Fulkerson.

![Dinic](https://cdn-images-1.medium.com/max/484/1*OnW4o0giSCRq5A5UGIBdmA.png)

La manera en la que opera Dinic, es aplicando BFS para poder encontar los posiblemente varios
caminos los cuáles contienen el mínimo número de aristas desde el nodo fuente hasta el nodo objetivo. Posteriormente
se utiliza DFS para poder recorrerlos todos, y hacer todas las aumentaciones en solo un paso. La complejidad del
algoritmo de Dinic es de O(n^2m).

## Código Base

- [Dinic.cpp](https://github.com/MarcosHT4/Algoritmica2repo/blob/master/algortimos/teoriaDeGrafos/Dinic/Dinic.cpp) - _C++_

## Referencias

- [Dinic's Algorithm](https://en.wikipedia.org/wiki/Dinic%27s_algorithm)
- [Dinic' Max Flow Algorithm](https://basics.sjtu.edu.cn/~dominik/teaching/material/dinic-slides.pdf)
- [Dinic's algorithm for Maximum flow in a graph](https://iq.opengenus.org/dinics-algorithm/)