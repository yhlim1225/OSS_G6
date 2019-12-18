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

#ifndef NETWORK_FLOW_H_INCLUDED
#define NETWORK_FLOW_H_INCLUDED

#include "general.h"
#include<vector>
#include<queue>

struct Edge{
    int nxt, rev, cap, flw;
    Edge() {}
    Edge(int a, int b, int c) : nxt(a), rev(b), cap(c), flw(0) {}
};

class MaximumFlow{
protected:
    std::vector< std::vector<Edge> > lst;
    std::vector<int> work, level;
    int SRC, SNK, res;
    const int INF=1e9;

    bool bfs()
    {
        std::queue<int> Q;
        for(int i=0 ; i<level.size() ; i++) level[i]=-1;
        level[SRC]=0;
        Q.push(SRC);
        while(!Q.empty()){
            int v=Q.front();
            Q.pop();
            for(int i=0 ; i<lst[v].size() ; i++){
                int nxt=lst[v][i].nxt;
                if(level[nxt]==-1 && lst[v][i].cap-lst[v][i].flw>0){
                    Q.push(nxt);
                    level[nxt]=level[v]+1;
                }
            }
        }
        return level[SNK]!=-1;
    }

    int dfs(int v, int fn, int flow)
    {
        if(v==fn) return flow;
        for(int &i=work[v] ; i<lst[v].size() ; i++){
            int nxt=lst[v][i].nxt;
            if(level[nxt]==level[v]+1 && lst[v][i].cap-lst[v][i].flw>0){
                int df=dfs(nxt,fn,min(flow,lst[v][i].cap-lst[v][i].flw));
                if(df>0){
                    lst[v][i].flw+=df;
                    lst[nxt][lst[v][i].rev].flw-=df;
                    return df;
                }
            }
        }
        return 0;
    }

public:
    MaximumFlow(int n){
        lst.resize(n+5);
        work.resize(n+5);
        level.resize(n+5);
        res=0;
        SRC=SNK=-1;
    }
//add edge from v1 to v2 with capacity f
    void add_edge(int v1, int v2, int f)
    {
        lst[v1].emplace_back(v2,lst[v2].size(),f);
        lst[v2].emplace_back(v1,lst[v1].size()-1,0);
    }
//set and get function of protected variable
    void set_SRC(int x){ SRC=x; }
    void set_SNK(int x){ SNK=x; }
    int get_res(){ return res; }
    int get_SRC(){ return SRC; }
    int get_SNK(){ return SNK; }
//get maximum flow using Dinic's algorithm (Time Complexity : O(V^2E)
    int dinic()
    {
        if(SRC!=-1 && SNK!=-1){
            res=0;
            while(bfs()){
                for(int i=0 ; i<work.size() ; i++) work[i]=0;
                while(1){
                    int flow=dfs(SRC,SNK,INF);
                    if(flow==0) break;
                    res+=flow;
                }
            }
            return res;
        }
        return 0;
    }
};


#endif // NETWORK_FLOW_H_INCLUDED
