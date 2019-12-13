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
