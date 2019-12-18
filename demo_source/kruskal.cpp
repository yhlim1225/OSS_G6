#include<iostream>
#include"Kruskal.h"

int main() {
	Graph* g = new Graph(4);

	g->add_edge(0, 1, 1);
	g->add_edge(0, 3, 2);

	g->add_edge(1, 0, 1);
	g->add_edge(1, 2, 4);
	g->add_edge(1, 3, 3);


	g->add_edge(2, 1, 4);
	g->add_edge(2, 3, 5);

	g->add_edge(3, 0, 2);
	g->add_edge(3, 1, 3);
	g->add_edge(3, 2, 5);

	
	KruskalMST(g);

	system("pause");
}
