// The MIT License (MIT)

// Copyright (c) 2019 OSS_G6. All rights reserved.

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.



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
