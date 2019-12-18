#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <unordered_set>  

#include "PrimMst.h"

int main() {
	debug = false;
	cout << "Prim's MST algo.\n Enter number of Vertices and Edges: ";
	cin >> N >> E;
	cout << "\nEnter all edges in the graph in format - v1 v2 edge-cost : \n [starting from 1, the root]";
	int tmp1, tmp2, tmp3;
	init();
	for (int i = 0; i < E; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		G[tmp1 - 1].push_back(tmp2 - 1);
		G[tmp2 - 1].push_back(tmp1 - 1);
		w[tmp1 - 1][tmp2 - 1] = tmp3;
		w[tmp2 - 1][tmp1 - 1] = tmp3;
	}
	int cost = 0;
	pie[0] = 0;
	MST_PRIM();
	cout << " ::MST::\nRoot is : 1";
	for (int i = 1; i < N; i++) {
		cout << "( " << i + 1 << ", " << pie[i] + 1 << " ) : " << key[i] << "\n";
		cost += key[i];
	}
	cout << "Minimum Cost = " << cost;
	return 0;
}
