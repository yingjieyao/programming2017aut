#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[111][111];
int vis1[111][111];
int vis2[111][111];
int m,n;
int dx1[4]= {0,0,1,-1};
int dy1[4]= {1,-1,0,0};
int dx2[8]= {0,0,1,1,1,-1,-1,-1};
int dy2[8]= {-1,1,-1,0,1,-1,0,1};

void sfs1(int x,int y)
{
    int tx,ty,i;
    vis1[x][y]=1;
    for (i=0; i<4; i++)
    {
        tx=x+dx1[i];
        ty=y+dy1[i];
        if (tx<0||tx>=n||ty<0||ty>=m)
        {
            continue;
        }
        if (a[tx][ty]=='#'||vis1[tx][ty]==1)
        {
            continue;
        }
        vis1[tx][ty]=1;
        sfs1(tx,ty);
    }
}

void sfs2(int x,int y)
{
    int tx,ty,i;
    vis2[x][y]=1;
    for (i=0; i<8; i++)
    {
        tx=x+dx2[i];
        ty=y+dy2[i];
        if (tx<0||tx>=n||ty<0||ty>=m)
        {
            continue;
        }
        if (a[tx][ty]=='#'||vis2[tx][ty]==1)
        {
            continue;
        }
        vis2[tx][ty]=1;
        sfs2(tx,ty);
    }
}

int main()
{
    int T,sum1,sum2,i,j;
    scanf ("%d",&T);
    while (T--)
    {
        memset (vis1,0,sizeof(vis1));
        memset (vis2,0,sizeof(vis2));
        scanf ("%d %d",&n,&m);
        for (i=0; i<n; i++)
        {
            scanf ("%s",a[i]);
        }
        sum1=0;
        sum2=0;
        for (i=0; i<n; i++)
        {
            for (j=0; j<m; j++)
            {
                if (vis1[i][j]==0&&a[i][j]=='@')
                {
                    sfs1(i,j);
                    sum1++;
                }
            }
        }
        for (i=0; i<n; i++)
        {
            for (j=0; j<m; j++)
            {
                if (vis2[i][j]==0&&a[i][j]=='@')
                {
                    sfs2(i,j);
                    sum2++;
                }
            }
        }
        printf ("%d %d\n",sum1,sum2);
    }
    return 0;
}