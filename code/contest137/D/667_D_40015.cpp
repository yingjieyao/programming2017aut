#include<cstdio>
#include<algorithm>
using namespace std;
int f[1100];
int n,m;

struct edges
{
    int a,b,c;
}   edg[110000];

int cmp(edges a,edges b)
{
    if (a.c<b.c) return 1;return 0;
}

int findfa(int k)
{
    if (f[k]==k) return k;
    int tmp=findfa(f[k]);
    f[k]=tmp;
    return tmp;
}
int linkit(int a,int b)
{
    f[findfa(a)]=f[findfa(b)];
    return 0;
}

int main()
{

    while(scanf("%d%d",&n,&m)>-1&&m+n>0)
    {
        for (int i=1;i<=n;i++)
            f[i]=i;
        for (int i=1;i<=m;i++)
            scanf("%d%d%d",&edg[i].a,&edg[i].b,&edg[i].c);
        sort(edg+1,edg+m+1,cmp);

        int ans=0;
        for (int i=1;i<=m;i++)
        {
            int a=edg[i].a;
            int b=edg[i].b;
            if (findfa(a)!=findfa(b))
            {
                ans+=edg[i].c;
                linkit(a,b);
            }
        }
        printf("%d\n",ans);
    }
}
