#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge
{
    int u, v, w;
} e[100005];

int cmp(const void*a, const void*b)
{
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

int count;
void add(int u, int v, int w)
{
    e[count].u = u;
    e[count].v = v;
    e[count].w = w;
    count++;
}

int rr[100005];
void make_set(int n)
{
    int i;
    for (i = 1; i <= n; ++i)
    {
        rr[i] = i;
    }
}

int find_root(int x)
{
    if (rr[x] == x)
    {
        return x;
    }
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
        qsort(e, count, sizeof(e[0]), cmp);
        sum = 0;
        edge_cnt = 0;
        for (i = 0; i<count; i++)
        {
            int tx = find_root(e[i].u);
            int ty = find_root(e[i].v);
            if (tx == ty)
                continue;
            union_set(tx,ty);
            sum += e[i].w;
            edge_cnt++;
        }
        if (edge_cnt==n-1)
            printf("%d\n", sum);
    }
    return 0;
}
