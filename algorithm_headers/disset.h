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

#ifndef DISSET_H_INCLUDED
#define DISSET_H_INCLUDED

#include<vector>

/*
We used Union-Find Tree data structure to implement Disjoint Set.
Each elements in this class indicates followings.
par[v] -> parent node of node v in Union-Find Tree
rnk[v] -> height of the Union-Find Tree whose root is v
sz[v] -> size of the Union-Find Tree whose root is v
*/
class DisjointSet{
protected:
    std::vector<int> par, rnk, sz;
    int opt, range;
    void Union_by_rank(int x, int y);
    void Union_by_size(int x, int y);
    void path_compression(int x, int y);
public:
    DisjointSet(int n, int olevel);
    void Union(int x, int y);
    int Find(int x);
    bool SameSet(int x, int y);
};

/*
Constructor needs two arguments
n = number of elements
olevel = how to optimize
If olevel=1, then use Union by rank method.
If olevel=2, then use Union by size method.
If olevel=3, then use Path compression method.
*/
DisjointSet::DisjointSet(int n, int olevel){
    if(olevel>=1 && olevel<=3){
        opt=olevel;
    }
    else opt=1;
    range=n;
    par.resize(n+5,-1);
    if(opt==1){
        rnk.resize(n+5,1);
    }
    else if(opt==2){
        sz.resize(n+5,1);
    }
}

/*
Note that range of both element should be from 1 to n.
This function is wrapper function of the union operation.
*/
void DisjointSet::Union(int x, int y){
    if(1<=x && x<=range && 1<=y && y<=range){
        if(opt==1) DisjointSet::Union_by_rank(x,y);
        else if(opt==2) DisjointSet::Union_by_size(x,y);
        else if(opt==3) DisjointSet::path_compression(x,y);
    }
}

/*
This function returns the root of the Union-Find Tree which contains node x.
If you choose olevel as 3, path compression occurs during finding its root.
*/
int DisjointSet::Find(int x){
    if(x<1 || x>range) return -1;
    if(par[x]==-1) return x;
    if(opt==3){
        return par[x]=DisjointSet::Find(par[x]);
    }
    else return DisjointSet::Find(par[x]);
}

/*
This function checks whether element x and y are both in the same set.
Note that if either x or y is out of range, then it always returns false.
*/
bool DisjointSet::SameSet(int x, int y){
    if(1<=x && x<=range && 1<=y && y<=range){
        x=DisjointSet::Find(x);
        y=DisjointSet::Find(y);
        return x==y;
    }
    return false;
}

/*
Union by rank method guarantees O(logN)
*/
void DisjointSet::Union_by_rank(int x, int y){
    x=DisjointSet::Find(x);
    y=DisjointSet::Find(y);
    if(x==y) return;
    if(rnk[x]<rnk[y]) par[x]=y;
    else if(rnk[x]>rnk[y]) par[y]=x;
    else if(rnk[x]==rnk[y]){
        par[x]=y;
        rnk[y]++;
    }
}

/*
Union by size method guarantees O(logN)
*/
void DisjointSet::Union_by_size(int x, int y){
    x=DisjointSet::Find(x);
    y=DisjointSet::Find(y);
    if(x==y) return;
    if(sz[x]<=sz[y]){
        par[x]=y;
        sz[y]+=sz[x];
    }
    else if(sz[x]>sz[y]){
        par[y]=x;
        sz[x]+=sz[y];
    }
}

/*
Path compression method takes amortized O(a(n))
where a(n) = inverse function of Ackerman function
*/
void DisjointSet::path_compression(int x, int y){
    x=DisjointSet::Find(x);
    y=DisjointSet::Find(y);
    if(x==y) return;
    par[x]=y;
}


#endif // DISSET_H_INCLUDED
