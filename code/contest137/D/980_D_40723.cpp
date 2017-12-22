#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n, m, fa[1005];
struct node
{
    int st,ed,t;
}a[100005];
bool cmp(node x, node y)
{
    return x.t < y.t;
}
int findroot(int x)
{
    if(fa[x] == x) return x;
    fa[x] = findroot(fa[x]);
    return fa[x];
}
int main()
{
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &a[i].st, &a[i].ed, &a[i].t);
        }
        sort(a + 1, a + 1 + m, cmp);
        for(int i = 1; i <= n; i++) fa[i] = i;
        int sum = 0;
        for(int i = 1; i <= m; i++)
        {
            int tx = findroot(a[i].st);
            int ty = findroot(a[i].ed);
            if(tx == ty) continue;
            fa[tx] = ty;
            //printf("fa[%d] = %d", tx, ty);
            sum += a[i].t;
        }
        printf("%d\n", sum);
    }
    return 0;
}
