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

#include<stdio.h>
#include "rquery.h"

typedef long long ll;

int n, qn1, qn2;
ll arr[1000005];

ll sum(ll v1, ll v2)
{
    return v1+v2;
}

int main()
{
    // size of array, # of query type1 and 2
    scanf("%d %d %d",&n,&qn1,&qn2);
    SegTree<ll> T(n,0,sum);
    for(int i=1 ; i<=n ; i++){
        scanf("%lld",&arr[i]);
        T.update(i,arr[i]);
    }
    //qn = number of total queries
    int qn=qn1+qn2;
    for(int i=1 ; i<=qn ; i++){
        int t;
        scanf("%d",&t);
        // change the element of arr[idx] into val;
        if(t==1){
            int idx;
            ll val;
            scanf("%d %lld",&idx,&val);
            T.update(idx,val);
        }
        else if(t==2){
            // get sum of arr from st to fn
            int st, fn;
            scanf("%d %d",&st,&fn);
            printf("%lld\n",T.get_value(st,fn));
        }
    }
    return 0;
}
