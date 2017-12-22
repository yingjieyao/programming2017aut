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
queue <int> q;
void spfa()
{
    while(!q.empty())
        q.pop();
    for(int i=1;i<=n;i++)
    {
        dis[i]=INF;
        zd[i]=INF;
    }
    q.push(S);
    vis[S]=1;
    dis[S]=0;
    zd[S]=0;
    while(!q.empty())
    {
        int now=q.front();
        for(int i=qdb[now];i;i=e[i].ne)
        {
            if(dis[e[i].y]>dis[now]+1)
            {
                dis[e[i].y]=dis[now]+1;
                zd[e[i].y]=zd[now]+e[i].v;
                if(vis[e[i].y]==0)
                {
                    vis[e[i].y]=1;
                    q.push(e[i].y);
                }
            }
            if(dis[e[i].y]==dis[now]+1)
            {
                zd[e[i].y]=min(zd[e[i].y],zd[now]+e[i].v);
            }
        }
        q.pop();
        vis[now]=0;
    }
}
void dfs(int x)
{
    for(int i=qdb[x];i;i=e[i].ne)
    {
        if(vis[e[i].y]==0)
        {
            vis[e[i].y]=1;
            dfs(e[i].y);
        }
    }
}
int main()
{
    int T=1;
    scanf("%d",&T);
    while(T--)
    {
        cnt=0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            qdb[i]=0;
            vis[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            insert(a,b,0);
            insert(b,a,0);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
