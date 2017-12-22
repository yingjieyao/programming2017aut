#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
int a[101][101];
int vis[101][101];
int xc[9]={0,1,0,0,-1,1,1,-1,-1};
int yc[9]={0,0,-1,1,0,-1,1,1,-1};
int n,m;
void dfs1(int x,int y)
{   int i;
    for(i=1;i<=8;i++)
    {   int x1=x+xc[i],y1=y+yc[i];
        if(a[x1][y1]&&!vis[x1][y1])
        {
            vis[x1][y1]=1;dfs1(x1,y1);
        }
    }
}
void dfs2(int x,int y)
{   int i;
    for(i=1;i<=4;i++)
    {   int x1=x+xc[i],y1=y+yc[i];
        if(a[x1][y1]&&!vis[x1][y1])
        {
            vis[x1][y1]=1;dfs2(x1,y1);
        }
    }
}
int main()
{   int i,j,T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
         cin>>n>>m;
     for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
     { char x;
        cin>>x;
        if(x=='@') a[i][j]=1;
     }
     int ans=0;
     for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i][j]&&!vis[i][j])
            {
                vis[i][j]=1;
                dfs2(i,j);
                ans++;
            }
        }

    int ans1=0;
     memset(vis,0,sizeof(vis));
     for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i][j]&&!vis[i][j])
            {
                vis[i][j]=1;
                dfs1(i,j);
                ans1++;
            }
        }

   cout<<ans<<" "<<ans1<<endl;





    }

    return 0;
}
