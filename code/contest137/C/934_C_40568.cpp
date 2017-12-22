#include <stdio.h>
#include <stdlib.h>

int map[2000][2000],vis[2000],queue[2000],ans;
int m,n;
int check()
{
    int i;
    for(i=1;i<=m;i++)
        if(vis[i]==0) return 1;
    return 0;
}

void bfs()
{
    while(check())
    {
        int i,j;
        ans++;
        for(i=1;i<=m;i++)
        {
            if(vis[i]==0) break;
        }
        int head=0,tail=1;
        queue[0]=i;
        vis[i]=1;
        while(head!=tail)
        {
            int cur=queue[head];
            head++;
            for(j=1;j<=m;j++)
            {
                if(map[cur][j]==1&&vis[j]==0)
                    {
                        queue[tail++]=j;
                        vis[j]=1;
                    }
            }
        }
    }
}
int main()
{
    int t;
    int i,j,a,b;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        for(i=0;i<1100;i++)
        {
            vis[i]=0;
        }
        for(i=0;i<1100;i++)
            for(j=0;j<1100;j++)
               map[i][j]=0;
        scanf("%d%d",&m,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            map[a][b]=map[b][a]=1;
        }
        bfs();
        printf("%d\n",ans);
    }
    return 0;
}
