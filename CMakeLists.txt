cmake_minimum_required(VERSION 3.20)
project(Algoritmica2repo)

set(CMAKE_CXX_STANDARD 14)


add_executable(SegmentTree "algortimos/estructurasDeDatos/SegmentTree/SegmentTree.cpp")
add_executable(TrieArray "algortimos/estructurasDeDatos/Trie/TrieArray.cpp")
add_executable(TrieMap "algortimos/estructurasDeDatos/Trie/TrieMap.cpp")
add_executable(CostOfData "algortimos/estructurasDeDatos/Trie/ejercicios/CostOfData.cpp")
add_executable(SearchEngine "algortimos/estructurasDeDatos/Trie/ejercicios/SearchEngine.cpp")
add_executable(8queens algortimos/backtracking/8queens.cpp)