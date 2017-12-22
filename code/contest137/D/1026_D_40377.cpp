#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define maxn 111111
#define maxm 111111

struct Edge
{
    int u, v, w;
} E[maxm];


int mmp(const void*a, const void*b)
{
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}


int count;
void add(int u, int v, int w)
{
    E[count].u = u;
    E[count].v = v;
    E[count].w = w;
    count++;
}

int rr[maxn];

void make_set(int n)
{
    int i;
    for (i = 1; i <= n; ++i)
        rr[i] = i;
}

int find_root(int x)
{
    if (rr[x] == x)
        return x;
    rr[x] = find_root(rr[x]);
    return rr[x];
}

void union_set(int x, int y)
{
    int tx = find_root(x);
    int ty = find_root(y);
    if (tx == ty)
        return;
    rr[tx] = ty;
}


int main()
{
    int m, n, a, b, w;
    int sum, i, edge_cnt;
    while(~scanf("%d%d",&n,&m)&&n)
    {
        make_set(n);
        count = 0;
        while(m--)
        {
            scanf("%d %d %d", &a, &b, &w);
            add(a,b,w);
        }
        qsort(E, count, sizeof(E[0]), mmp);
        sum = 0;
        edge_cnt = 0;
        for (i = 0; i < count; ++i)
        {
            int tx = find_root(E[i].u);
            int ty = find_root(E[i].v);
            if (tx == ty)
                continue;
            union_set(tx,ty);
            sum+= E[i].w;
            edge_cnt++;
        }
        if (edge_cnt == n-1)
            printf("%d\n", sum);
    }
    return 0;
}
