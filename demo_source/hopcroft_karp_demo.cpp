#include<stdio.h>
#include "network_flow.h"

int n, m;

int main()
{
    scanf("%d %d",&n,&m);
    BipartiteMatching bp(n,m);
    for(int i=1 ; i<=n ; i++){
        int a, b;
        scanf("%d",&a);
        for(int j=1 ; j<=a ; j++){
            scanf("%d",&b);
            bp.add_edge(i,b);
        }
    }
    printf("%d",bp.Hopcroft_Karp());
    return 0;
}
