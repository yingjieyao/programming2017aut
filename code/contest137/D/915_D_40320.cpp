#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int min(int x,int y)
{
    return x < y ? x : y ;
}
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
typedef struct
{
    int u,v,w;
}Node;
Node arr[100001];
int cnt = 0;
int cmp(const void *x,const void *y)
{
    return (*(Node *)x).w > (*(Node *)y).w;
}
int mat[1001][1001];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    while (scanf("%d%d",&n,&m) != EOF && m+ n)
    {
        cnt = 0;
        int i;
        for (i = 1;i <= n;i ++)
        {
            f[i] = i;
        }
        int j;
        for (i = 1;i <= n;i ++)
            for (j = 1;j <= n;j++)
            {
                mat[i][j] = 100000000;
                if(i == j) mat[i][j] = 0;
            }
        for (i = 1;i <= m;i ++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            w = min(w,mat[u][v]);
            mat[u][v] = mat[v][u] = w;
        }
        for (i = 1;i <= n;i ++)
        {
            for (j = i + 1;j <= n;j ++)
            {
                arr[++cnt].u = i;
                arr[cnt].v = j;
                arr[cnt].w = mat[i][j];
            }
        }
        qsort(arr + 1,cnt,sizeof(arr[0]),cmp);
        for (i = 1;i <= cnt;i ++)
        {
            if(find(arr[i].u) == find(arr[i].v)) arr[i].w = 0;
            else union_set(arr[i].u,arr[i].v);
        }
        int sum = 0;
        for (i = 1;i <= cnt;i ++)
        {
            sum += arr[i].w;
        }
        printf("%d\n",sum);
    }
    return 0;
}
