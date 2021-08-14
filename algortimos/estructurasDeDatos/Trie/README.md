# Trie
En el mundo de la informática, el Trie, también conocido como Prefix Tree o
Digital Tree es una estructura de datos ordenada basada en árbol, el cual es utilizado
para almaceanar arreglos asociativos, donde las llaves son usualmente strings.

![Trie](http://theoryofprogramming.azurewebsites.net/wp-content/uploads/2015/06/trie12.jpg)

El problema que soluciona el Trie, es el problema de tener que consultar si ciertas palabras existen 
en alguna estructura de datos. Gracias al Trie, podemos resolver este problema en una complejidad O(n).

Un extra que se le puede añadir al Trie, es un método llamado: deleteWord(), en donde se recorre toda la palabra 
que se desea eliminar utilizando recursividad hasta llegar al final de la palabra; posteriormente se van eliminando
los nodos volviendo arriba, verificando que los nodos no tengan hijos restantes, para así no borrar accidentalmente
un nodo que era parte de otra palabra

## Código Base

- [TrieArray (con método deleteWord())](TrieArray.cpp) - _C++_
- [TrieMap](TrieMap.cpp) - _C++_

## Referencias

- [Trie](https://en.wikipedia.org/wiki/Trie)
- [Trie data structure](https://iq.opengenus.org/tries/)
- [Using Tries](https://www.topcoder.com/thrive/articles/Using%20Tries)


