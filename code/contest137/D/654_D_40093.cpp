#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 500000;
//声明变量
struct edge
{
    int x;
    int y;
    int v;
    int ne;
};
edge e[maxn];
int cnt=0;
int qdb[maxn];
int f[maxn];
int vis[maxn],dis[maxn],zd[maxn];
int n,m,S,E;
void insert(int x,int y,int v)
{
    e[++cnt].x=x;
    e[cnt].y=y;
    e[cnt].v=v;
    e[cnt].ne=qdb[x];
    qdb[x]=cnt;
}
bool mycmp(edge a,edge b)
{
    return a.v<b.v;
}
int find(int x)
{
    if(f[x]==-1)
        return x;
    else
        return f[x]=find(f[x]);
}
void krus()
{
    for(int i=1;i<=n;i++)
        f[i]=-1;
    int zs=0,ans=0;
    for(int i=1;i<=cnt;i++)
    {
        int a=e[i].x,b=e[i].y,v=e[i].v;
        int t1=find(a),t2=find(b);
        if(t1!=t2)
        {
            ans+=v;
            f[t1]=t2;
            zs++;
        }
        if(zs==n-1)
            break;
    }
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d %d",&n,&m))
    {
        if(n==0&&m==0)
            break;
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            qdb[i]=0;
            vis[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            insert(a,b,c);
            insert(b,a,c);
        }
        sort(e+1,e+cnt+1,mycmp);
        krus();
    }
    return 0;
}
