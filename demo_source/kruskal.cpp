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
