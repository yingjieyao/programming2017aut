#include<cstdio>
int f[1100];
int n,m;

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
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            f[i]=i;
        for (int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            linkit(a,b);
        }
        int ans=0;
        for (int i=1;i<=n;i++)
            if (f[i]==i) ans++;
        printf("%d\n",ans);

    }
}
