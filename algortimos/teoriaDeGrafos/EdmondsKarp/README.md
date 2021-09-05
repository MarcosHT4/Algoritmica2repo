# Edmonds Karp

En el mundo de la informática, el algoritmo de Edmonds Karp, es un algoritmo
de la teoría de grafos que sirve para poder encontrar el flujo máximo en 
una red de flujo. En sí mismo, el algoritmo de Edmonds Karp es una adaptación del algoritmo de
Ford Fulkerson, el cual soluciona los problemas más conocidos del algoritmo de Ford Fulkerson.

![EdmondsKarp](https://www.maplesoft.com/SizedImages/image.ashx?file=f5530eba27e20193c9ba0ad4cb0ec14a_364_280.png)

La manera en la que funciona Edmonds Karp, es utilizando el famoso algoritmo de BFS, el cual ayuda a poder
encontrar el cámino con menos aristas, para luego obtener el peso mínimo de ese camino y usarlo para el 
flujo máximo. A esto se le conoce como camino aumentante. La complejidad del algoritmo de Edmonds Karp es de:
O(nm^2).

## Código Base

- [EdmondsKarp.cpp](https://github.com/MarcosHT4/Algoritmica2repo/blob/master/algortimos/teoriaDeGrafos/EdmondsKarp/EdmondsKarp.cpp) - _C++_

## Referencias

- [Edmonds-Karp algorithm](https://en.wikipedia.org/wiki/Edmonds%E2%80%93Karp_algorithm)
- [Edmonds-Karp Algorithm](https://brilliant.org/wiki/edmonds-karp-algorithm/)
- [The Edmonds-Karp Max-Flow Algorithm](https://www.cs.cornell.edu/courses/cs4820/2011sp/handouts/edmondskarp.pdf)