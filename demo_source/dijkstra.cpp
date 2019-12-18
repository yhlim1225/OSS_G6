//The MIT License (MIT)

//Copyright (c) 2019 OSS_G6. All rights reserved.

//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:

//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.

//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.

#include "dijkstra.h"
#include <stdio.h>

#define MAX_VERTICES 7
int main(){
	int **cost = new int*[MAX_VERTICES];
	for(int i = 0 ; i < MAX_VERTICES; ++i){
		cost[i] = new int[MAX_VERTICES];
	}
	int tmp[][MAX_VERTICES] = {{0, 10, 7, INF, 15, INF, INF},{10, 0, INF, 5, 8, INF, INF}, {7, INF, 0, INF, 6, INF, INF}, {INF, 5, INF, 0, 12, 6, INF}, {15, 8, 6, 12, 0, 25, 3}, {INF, INF, INF, 6, 25, 0, 1}, {1000, 1000, 1000, 1000, 3, 1, 0}};
	int distance[MAX_VERTICES];
	int found[MAX_VERTICES];
	int n = MAX_VERTICES;
	int v = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++)
			cost[i][j] = tmp[i][j];
	}
	shortestPath(v, cost, distance, n, found);
	for(int i = 0 ; i < n ; i++)
		printf("%d ", distance[i]);
	printf("\n");
	return 0;
}
