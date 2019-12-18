#include<stdio.h>
#include "rquery.h"

typedef long long ll;

ll sum(ll x, ll y) {return x+y;}

int n, qn;
ll m[100005];

int main()
{
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++){
        scanf("%lld",&m[i]);
    }
    scanf("%d",&qn);
    PST<ll> pst(n,n+qn,qn,0LL,sum);
    int k=1;
    for(int i=1 ; i<=n ; i++) pst.update_Kth_tree(k,i,m[i]);
    for(int i=1 ; i<=qn ; i++){
        int t;
        scanf("%d",&t);
        //change m[idx]=v
        if(t==1){
            int idx; ll v;
            scanf("%d %lld",&idx,&v);
            k++;
            pst.update_Kth_tree(k,idx,v);
        }
        else if(t==2){
            int x, st, fn;
            scanf("%d %d %d",&x,&st,&fn);
            //get sum of range from st to fn when 1st to xth query1 is done
            printf("%lld\n",pst.get_value_at_Kth_tree(x+1,st,fn));
        }
    }
    return 0;
}
