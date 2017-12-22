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
const int kx[150]={0,0,1,-1,0,-1,-1,1,1};
const int ky[150]={0,1,0,0,-1,1,-1,1,-1};
char g[550][550];
int n,m;
int vis[550][550];
int check(int x,int y)
{
    if(g[x][y]=='@'&&vis[x][y]==0&&x>=1&&x<=n&&y>=1&&y<=m)
        return 1;
    return 0;
}
void debug()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<g[i][j];
        }
        cout<<endl;
    }
}
void bfs(int sx,int sy)
{
    queue <int> qx,qy;
    qx.push(sx);
    qy.push(sy);
    while(!qx.empty())
    {
        int x=qx.front(),y=qy.front();
        for(int i=1;i<=4;i++)
        {
            int tx=x+kx[i];
            int ty=y+ky[i];
            if(check(tx,ty)==1)
            {
                vis[tx][ty]=1;
                qx.push(tx);
                qy.push(ty);
            }
        }
        qx.pop(),qy.pop();
    }
}
void bfs2(int sx,int sy)
{
    queue <int> qx,qy;
    qx.push(sx);
    qy.push(sy);
    while(!qx.empty())
    {
        int x=qx.front(),y=qy.front();
        for(int i=1;i<=8;i++)
        {
            int tx=x+kx[i];
            int ty=y+ky[i];
            if(check(tx,ty)==1)
            {
                vis[tx][ty]=1;
                qx.push(tx);
                qy.push(ty);
            }
        }
        qx.pop(),qy.pop();
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=m+1;j++)
            {
                g[i][j]='#';
            }
        }
        char te[105];
        for(int i=1;i<=n;i++)
        {
            scanf("%s",te);
            for(int j=0;j<m;j++)
            {
                g[i][j+1]=te[j];
            }
        }
        //debug();
        memset(vis,0,sizeof(vis));
        int ans=0,ans1=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(check(i,j)==1)
                {
                    ans++;
                    vis[i][j]=1;
                    bfs(i,j);
                }
            }
        }
        ans1=ans;
        memset(vis,0,sizeof(vis));
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(check(i,j)==1)
                {
                    ans++;
                    vis[i][j]=1;
                    bfs2(i,j);
                }
            }
        }
        printf("%d %d\n",ans1,ans);
    }
    return 0;
}
