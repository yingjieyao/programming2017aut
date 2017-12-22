#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dis[1111][1111],v[1111];
int n,m;
int min(int q,int w)
{
    return q<w?q:w;
}
int fun()
{
    int d[1111],minn,tmp,i,k,sum=0;
    for(i=1;i<=n;++i)
    {
        d[i]=dis[1][i];
    }
    v[1]=1;
    k=1;
    while(k<=n-1)
    {
        minn=99999;
        for(i=2;i<=n;++i)
        {
            if(v[i]==0&&minn>d[i])
            {
                minn=d[i];
                tmp=i;
            }
        }
        k++;
        v[tmp]=1;
        sum+=minn;
        for(i=2;i<=n;++i)
        {
            if(v[i]==0&&d[i]>dis[tmp][i])
            {
                d[i]=dis[tmp][i];
            }
        }
    }
    return sum;
}
int main()
{
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0&&m==0)
        {
            break;
        }
        int i,j,a,b,c;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                dis[i][j]=99999;
            }
            dis[i][i]=0;
            v[i]=0;
        }
        for(i=1;i<=m;++i)
        {
            scanf("%d %d %d",&a,&b,&c);
            dis[a][b]=min(dis[a][b],c);
            dis[b][a]=dis[a][b];
        }
        printf("%d\n",fun());
    }
    return 0;
}
