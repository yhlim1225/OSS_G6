#include<stdio.h>
#include "network_flow.h"

int n, m;

int main()
{
    scanf("%d %d",&n,&m);
    MaximumFlow mf(n+m+2);
    mf.set_SNK(0), mf.set_SRC(n+m+1);
    for(int i=1 ; i<=n ; i++) mf.add_edge(mf.get_SRC(),i,1);
    for(int i=1 ; i<=m ; i++) mf.add_edge(n+i,mf.get_SNK(),1);
    for(int i=1 ; i<=n ; i++){
        int a, b;
        scanf("%d",&a);
        for(int j=1 ; j<=a ; j++){
            scanf("%d",&b);
            mf.add_edge(i,n+b,1);
        }
    }
    printf("%d",mf.dinic());
    return 0;
}
