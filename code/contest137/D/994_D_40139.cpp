#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define INF 11111
int mat[1001][1001];
int main()
{
    int n,m,i,j,vis[1001],dist[1001],a,b,w,sum;
    int minn,min_index;
    while(scanf("%d %d",&n,&m)==2)
    {
        if(!n && !m) break;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=i;++j) mat[i][j]=mat[j][i]=INF;
        }
        for(i=0;i<m;++i)
        {
            scanf("%d %d %d",&a,&b,&w);
            if(w<mat[a][b]) mat[a][b]=mat[b][a]=w;
        }
        memset(vis,1,sizeof(vis));//0左1右
        for(i=1;i<=n;++i) dist[i]=mat[1][i];
        dist[1]=INF;
        vis[1]=0;
        sum=0;
        for(i=1;i<n;++i)
        {   minn=INF;
            for(j=1;j<=n;++j)
            {
                if(vis[j] && dist[j]<minn)
                {
                    minn=dist[j];
                    min_index=j;
                }
            }
            sum+=minn;
            vis[min_index]=0;
            for(j=1;j<=n;++j)
            {
                if(vis[j] && mat[min_index][j]<dist[j])
                {
                    dist[j]=mat[min_index][j];
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
