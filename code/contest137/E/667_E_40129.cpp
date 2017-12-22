#include<cstdio>
#include<algorithm>
using namespace std;
int f[12100];
int n,m;
int dx[8]={0,0,-1,1,1,-1,-1,1};
int dy[8]={-1,1,0,0,-1,1,-1,1};
char mp[110][110];
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
int gn(int i,int j)
{
    return (i-1)*m+j;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=0;i<=n+1;i++)
            for (int j=0;j<=m+1;j++)    
                mp[i][j]='#';
        for (int i=1;i<=n;i++)
            scanf("%s",&mp[i][1]);
        for (int i=0;i<=n*m+1;i++)
            f[i]=i;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (mp[i][j]=='@')
                    for (int k=0;k<4;k++)
                        if(mp[i+dx[k]][j+dy[k]]=='@') linkit(gn(i,j),gn(i+dx[k],j+dy[k]));
        int ans1=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (f[gn(i,j)]==gn(i,j)&&mp[i][j]=='@') ans1++;

        for (int i=0;i<=n*m+1;i++)
            f[i]=i;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (mp[i][j]=='@')
                    for (int k=0;k<8;k++)
                        if(mp[i+dx[k]][j+dy[k]]=='@') linkit(gn(i,j),gn(i+dx[k],j+dy[k]));
        int ans2=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (f[gn(i,j)]==gn(i,j)&&mp[i][j]=='@') ans2++;
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
