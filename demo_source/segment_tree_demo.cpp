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
