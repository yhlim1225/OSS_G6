#include<stdio.h>
#include "disset.h"

int n;

int main()
{
    int q, a, b, c;
    // n = number of elements
    // q = number of queries
    // query type0 = Union the two set
    // query type1 = Check whether they are in the same set
    scanf("%d %d",&n,&q);
    DisjointSet ds(n,1);
    for(int i=0 ; i<q ; i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a==0) ds.Union(b,c);
        if(a==1) printf("%s\n",ds.SameSet(b,c) ? "YES" : "NO");
    }
    return 0;
}
