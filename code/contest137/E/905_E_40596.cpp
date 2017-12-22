#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int n,m;
char arr[111][111];
int v[111][111];
int dx[]= {1,-1,0,0,1,-1,1,-1};
int dy[]= {0,0,1,-1,1,1,-1,-1};

void dfs1(int x,int y)
{
    v[x][y]=1;
    int i;
    for(i=0; i<4; i++)
    {
        int cx=x+dx[i];
        int cy=y+dy[i];
        if(cx>=0&&cx<n&&cy>=0&&cy<m&&arr[cx][cy]=='@'&&!v[cx][cy])
        {
            v[cx][cy]=1;
            dfs1(cx,cy);
        }
    }
}

void dfs2(int x,int y)
{
    v[x][y]=1;
    int i;
    for(i=0; i<8; i++)
    {
        int cx=x+dx[i];
        int cy=y+dy[i];
        if(cx>=0&&cx<n&&cy>=0&&cy<m&&arr[cx][cy]=='@'&&!v[cx][cy])
        {
            v[cx][cy]=1;
            dfs2(cx,cy);
        }
    }
}

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        memset(arr,0,sizeof(arr));
        memset(v,0,sizeof(v));
        scanf("%d%d",&n,&m);
        int i,j,ans1=0,ans2=0;
        for(i=0; i<n; i++)
        {
            scanf("%s",arr[i]);
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(v[i][j]==0&&arr[i][j]=='@')
                {
                    ans1++;
                    dfs1(i,j);
                }
            }
        }
        memset(v,0,sizeof(v));
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(v[i][j]==0&&arr[i][j]=='@')
                {
                    ans2++;
                    dfs2(i,j);
                }
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
