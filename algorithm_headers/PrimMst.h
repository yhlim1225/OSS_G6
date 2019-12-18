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
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <unordered_set>   //required for queue
#define p pair < int, int >
#define pa pair < int, p >
#define infinite 32767
#define nil 32767

using namespace std;
bool debug;

unordered_set <int> Q;
int N, E;
vector<int> pie, key, V; //In CLRS, pie depicts 'parent of'

/*
 * minE is a max priority_queue holding pairs of vertices and their costs
 * in format:
 *   pair< cost, pair <v1, v2> >
 */
priority_queue < pa, vector<pa>, greater<pa> > minE;

/*
 * Graph and costs/weights of edges are held in 2D matrices
 */
vector < vector <int> > w, G;

void init() {
	w.resize(N);
	G.resize(N);
	for (int i = 0; i < N; i++) {
		V.push_back(i);
		w[i].resize(N);
	}
	pie.resize(N);
	key.resize(N);
}

void addToQueue(int x) {
	for (int y : G[x]) {
		minE.push(pa(w[x][y], p(x, y))); //pushes (edge-cost connecting to MST, vertex pair)
		if (debug == true) {
			cout << "\t added " << y + 1 << " from" << x + 1;
		}
	}
}

/*
 * The MST-PRIM(r) funtion finds the MST
 */
void MST_PRIM(int r = 0) {
	for (auto u : V) {   //for each vertex in G
		key[u] = infinite;
		pie[u] = nil;
	}

	key[r] = 0; addToQueue(r);

	while (minE.empty() != true) {

		if (debug == true) cout << "\tInside loop\n";

		int u = minE.top().second.first;
		int v = minE.top().second.second;
		int c = minE.top().first;
		minE.pop();

		if (c < key[v]) {
			pie[v] = u;
			key[v] = c;
			addToQueue(v);
		}
	}
}
