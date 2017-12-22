#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int d[1111][1111],vis[1111];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int a,b,i,j,k,tmp,index=0,count=0;
        memset(d,0,sizeof(d));
        memset(vis,0,sizeof(vis));
        for(i=1; i<=n; ++i)
        {
            for(j=1; j<=n; ++j)
            {
                d[i][j]=0;
            }
            vis[i]=0;
        }
        for(i=0; i<m; ++i)
        {
            scanf("%d %d",&a,&b);
            if(a!=b)
            {
                d[a][b]=1;
                d[b][a]=1;
            }
        }
        if(n==0)
        {
            printf("0\n");
        }
        else
        {
            vis[1]=1;
            tmp=1;
            k=1;
            while(tmp!=index)
            {
                index=tmp;
                for(i=1; i<=n; ++i)
                {
                    if(vis[i]==0&&d[tmp][i]==1)
                    {
                        tmp=i;
                    }
                }
                vis[tmp]=1;
                for(i=1; i<=n; ++i)
                {
                    if(d[index][i]==1)
                        d[tmp][i]=1;
                }
                if(tmp==index)
                {
                    count++;
                    for(i=1; i<=n; ++i)
                    {
                        if(vis[i]==0)
                        {
                            tmp=i;
                            vis[tmp]=1;
                            break;
                        }
                    }
                }
            }
            printf("%d\n",count);
        }
    }
    return 0;
}
