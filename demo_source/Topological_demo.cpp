#include <iostream>
#include <string>
#include "Topological.h"
using namespace std;


int main() {

	AGraph* graph_1 = new AGraph(8);

	graph_1->addDirectedEdge(1, 2);
	graph_1->addDirectedEdge(1, 4);
	graph_1->addDirectedEdge(1, 6);

	graph_1->addDirectedEdge(3, 2);
	graph_1->addDirectedEdge(3, 8);

	graph_1->addDirectedEdge(5, 1);

	graph_1->addDirectedEdge(7, 1);
	graph_1->addDirectedEdge(7, 8);

	graph_1->addDirectedEdge(8, 6);

	cout << "Graph 1 " << endl;
	graph_1->printTopologicalSort();
	cout << endl;
	cout << endl;

	AGraph* graph_2 = new AGraph(4);

	graph_2->addDirectedEdge(1, 2);
	graph_2->addDirectedEdge(1, 4);
	graph_2->removeDirectedEdge(1, 4);
	cout << endl;


	graph_2->addDirectedEdge(2, 3);

	graph_2->addDirectedEdge(3, 4);

	graph_2->addDirectedEdge(4, 2);
	cout << "Graph 2 " << endl;
	graph_2->printTopologicalSort();
	cout << endl;

	cout << endl;
	int x;
	cin >> x;
}
