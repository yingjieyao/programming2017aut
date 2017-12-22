#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int vis[105][105];
char Map[105][105];
int n,m;
void dfs(int x,int y,int f){
    if (vis[x][y]==1) return ;
    vis[x][y]=1;
    if (y+1<=m && Map[x][y+1]=='@') dfs(x,y+1,f);
    if (x+1<=n && Map[x+1][y]=='@') dfs(x+1,y,f);
    if (x-1>=1 && Map[x-1][y]=='@') dfs(x-1,y,f);
    if (y-1>=1 && Map[x][y-1]=='@') dfs(x,y-1,f);
    if (f==2){
        if (x+1<=n && y+1<=m && Map[x+1][y+1]=='@') dfs(x+1,y+1,f);
        if (x+1<=n && y-1>=1 && Map[x+1][y-1]=='@') dfs(x+1,y-1,f);
        if (x-1>=1 && y+1<=m && Map[x-1][y+1]=='@') dfs(x-1,y+1,f);
        if (x-1>=1 && y-1>=1 && Map[x-1][y-1]=='@') dfs(x-1,y-1,f);
    }
    return ;
}
int main()
{
    //freopen ("E.in","r",stdin);
    //freopen ("E.out","w",stdout);
    int i,j,ans,t;
    scanf ("%d",&t);
    while(t>0){
        scanf ("%d %d",&n,&m);
        for (i=1;i<=n;i++) scanf ("%s",Map[i]+1);
        memset(vis,0,sizeof(vis));
        ans=0;
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                if (vis[i][j]==0 && Map[i][j]=='@'){ans++; dfs(i,j,1);}
        printf ("%d ",ans);
        memset(vis,0,sizeof(vis));
        ans=0;
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
                if (vis[i][j]==0 && Map[i][j]=='@'){ans++; dfs(i,j,2);}
        printf ("%d\n",ans);
        t--;
    }
    return 0;
}
