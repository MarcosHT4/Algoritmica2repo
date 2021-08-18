cmake_minimum_required(VERSION 3.20)
project(Algoritmica2repo)

set(CMAKE_CXX_STANDARD 14)


add_executable(SegmentTree "algortimos/estructurasDeDatos/SegmentTree/SegmentTree.cpp")
add_executable(TrieArray "algortimos/estructurasDeDatos/Trie/TrieArray.cpp")
add_executable(TrieMap "algortimos/estructurasDeDatos/Trie/TrieMap.cpp")
add_executable(CostOfData "algortimos/estructurasDeDatos/Trie/ejercicios/CostOfData.cpp")
add_executable(SearchEngine "algortimos/estructurasDeDatos/Trie/ejercicios/SearchEngine.cpp")
add_executable(8queens algortimos/backtracking/Nqueens.cpp)
add_executable(6139 algortimos/estructurasDeDatos/SegmentTree/ejercicios/6139.cpp)
add_executable(UnionFind algortimos/estructurasDeDatos/UnionFind/UnionFind.cpp)
add_executable(CityAndFlood algortimos/estructurasDeDatos/UnionFind/ejercicios/CityAndFlood.cpp)
add_executable(BIT algortimos/estructurasDeDatos/BIT/BIT.cpp)