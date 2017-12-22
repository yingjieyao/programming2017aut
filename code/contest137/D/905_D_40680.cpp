#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 0x3f3f3f

using namespace std;

int mat[1111][1111],dist[1111],v[1111];
int n,m;
int main()
{
    while(scanf("%d%d",&n,&m)&&(n||m))
    {
        int i,a,b,c,j;
        memset(v,0,sizeof(v));
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                mat[i][j]=mat[j][i]=inf;
            }
        }
        for(i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(mat[a][b]>c)
            {
                mat[a][b]=mat[b][a]=c;
            }
        }
        for(i=1; i<=n; i++)
        {
            dist[i]=inf;
        }
        dist[1]=0;
        int sum=0;
        for(i=1; i<=n; i++)
        {
            int minn=inf;
            int min_i;
            for(j=1; j<=n; j++)
            {
                if(!v[j]&&minn>dist[j])
                {
                    minn=dist[j];
                    min_i=j;
                }
            }
            if(minn==inf) break;
            sum+=minn;
            v[min_i]=1;
            for(j=1; j<=n; j++)
            {
                if(!v[j]&&dist[j]>mat[min_i][j])
                {
                    dist[j]=mat[min_i][j];
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
