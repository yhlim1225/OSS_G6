# OSS_G6

This project is for SKKU SOSC term project. 

C++ Modulized Algorithms 
----
Trying to develop modulized algorithms in addition to the standard library, i.e. \<algorithm\>. The implementation would use template in C++ for ease of use the modulized works and further development.

All the implemented algorithms are in [algorithm\_headers](algorithm_headers/) and test source codes are in [demo\_source](demo_source/)

Data Structures
----
Some of the implemented algorithms used the data structure defined in different header and may have demo for themselves. The headers for the specific data structure involves their own operations. Please check out the links below for further information.

* [Trie](algorithm_headers/trie.h)
* [Red-Black Tree](algorithm_headers/rbt.h)
* [Segment Tree](algorithm_headers/rquery.h)
* [Persistent Segment Tree](algorithm_headers/rquery.h)
* [Skip List](algorithm_headers/skip_list.h)

Implemented algorithms
----

This is the list of algorithms that currently implemented on this project and there would be some that are going to be added as future works.

 * [Prim Minimum Spanning Tree](algorithm_headers/PrimMst.h) 
 * [Dijkstra](algorithm_headers/dijkstra.h)
 * [Kruskal](algorithm_headers/kruskal.h)
 * [BST](algorithm_headers/BST.h)
 * [Disjoint Set](algorithm_headers/disset.h)
 * [floydwarshall](algorithm_headers/floydwarshall.h)
 * [Heap Sort](algorithm_headers/Heapsort.h)
 * [Bubble Sort](algorithm_headers/bubble_sort.h)
 * [Quick Sort](algorithm_headers/quick_sort.h)
 * [Insertion Sort](algorithm_headers/insertion_sort.h)
 * [Selection Sort](algorithm_headers/selection_sort.h)
 * [Merge Sort](algorithm_headers/merge_sort.h)
 * [Radix Sort](algorithm_headers/radix.h)
 * [Topological Sort](algorithm_headers/Topological.h) 
 * [Shell Sort](algorithm_headers/shell_sort.h)
 * [Dinic's Maximum Flow](algorithm_headers/network_flow.h)
 * [Hopcroft-Karp Maximum Bipartite Matching](algorithm_headers/network_flow.h)
 
Put the headers that is going to be used with your source code at the same directory and simply include and use the functions. 

```C++
#include "PrimMst"
```
or
```C++
#include <PrimMst>
```
By copying the header files into the glibc include directory (ex. /usr/include/c++/VERSIONS/) which might be only for linux glibc, but please bear in mind that this project does not guarantee that the functions will be completely fine with other standard libraries.

Demos
----
You can try the demo source files as an example of how to use the implemented algorithms after correctly adding those headers. Simply just compile the demo source with g++ and run would be the whole process. We have designed to do so since the simplicity is very important on understanding and comfortably get used on. 


How to contribute
---
To be sure, this project is for learning and practicing algorithms with C++ language.

Anyone who wants to practice algorithms in c++ without standard algorithm header files is welcomed to contribute on our project!
Please raise issues when needed for bugs or requesting new features.

Any algorithms that uses C++ to be implemented would be accepted with the following conditions completed:
* Separate header files of the algorithm function
* A demo source code for the algorithm
* All the files with MIT License included at the top of the files

We would appreciate very much with the translation of the documents.

These are our Team Members, and there is no need of hesitation for contact

Team Member (collaborators)
----
* [nighthalllo](https://github.com/nighthalllo) 장태영
* [WoosolAhn](https://github.com/WoosolAhn) 안우솔
* [youngyoung1021](https://github.com/youngyoung1021) 김영진
* [yhlim1225](https://github.com/yhlim1225) 임영훈
----


