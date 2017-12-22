#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int f[1001];
int find(int x)
{
    if(x == f[x]) return x;
    f[x] = find(f[x]);
    return f[x];
}
void union_set(int x,int y)
{
    int a = find(x);
    int b = find(y);
    if(a == b) return ;
    f[a] = b;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int i;
        for (i = 1;i <= n;i ++)
            f[i] = i;
        for (i = 1;i <= m;i ++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            int p = find(u);
            int q = find(v);
            if(p == q) continue;
            union_set(u,v);
        }
        int sum = 0;
        for (i = 1;i <= n;i ++)
        {
            if(f[i] == i) sum ++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
