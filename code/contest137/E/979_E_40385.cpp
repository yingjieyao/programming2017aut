#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

int a[105][105];
int b[105][105];
int cnt1,cnt2;

void bfs1(int x,int y)
{
    a[x][y]=cnt1;
    if(a[x+1][y]==0)
    {
        bfs1(x+1,y);
    }
    if(a[x-1][y]==0)
    {
        bfs1(x-1,y);
    }
    if(a[x][y+1]==0)
    {
        bfs1(x,y+1);
    }
    if(a[x][y-1]==0)
    {
        bfs1(x,y-1);
    }
}
void bfs2(int x,int y)
{
    b[x][y]=cnt2;
    if(b[x+1][y]==0)
    {
        bfs2(x+1,y);
    }
    if(b[x-1][y]==0)
    {
        bfs2(x-1,y);
    }
    if(b[x][y+1]==0)
    {
        bfs2(x,y+1);
    }
    if(b[x][y-1]==0)
    {
        bfs2(x,y-1);
    }
    if(b[x+1][y-1]==0)
    {
        bfs2(x+1,y-1);
    }
    if(b[x-1][y-1]==0)
    {
        bfs2(x-1,y-1);
    }
    if(b[x+1][y+1]==0)
    {
        bfs2(x+1,y+1);
    }
    if(b[x-1][y+1]==0)
    {
        bfs2(x-1,y+1);
    }
}



int main()
{
    int i,j,k,l,m,n;
    int t;
    int N;
    int ans;
    char cur;
    int chang,kuan;

    cin>>N;
    while(N--)
    {
        cnt1=1;
        cnt2=1;
        t=0;
        ans=0;
        cin>>chang>>kuan;
        memset(a,0,sizeof(a));

        for(i=0; i<=chang+1; i++)
        {
            a[i][0]=-1;
            a[i][kuan+1]=-1;
        }

        for(j=0; j<=kuan+1; j++)
        {
            a[0][j]=-1;
            a[chang+1][j]=-1;
        }

        for(i=1; i<=chang; i++)
        {
            for(j=1; j<=kuan; j++)
            {
                cin>>cur;
                if(cur=='#')
                    a[i][j]=(-1);
                if(cur=='@')
                    a[i][j]=0;
            }
        }

        for(i=0; i<=chang+1; i++)
            for(j=0; j<=kuan+1; j++)
                b[i][j]=a[i][j];

        /*for(i=0; i<=chang+1; i++)
        {
            for(j=0; j<=kuan+1; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }*/

        for(i=1; i<=chang; i++)
        {
            for(j=1; j<=kuan; j++)
            {
                if(a[i][j]==0)
                {
                    bfs1(i,j);
                    cnt1++;
                }
            }
        }
        /*for(i=0; i<=chang+1; i++)
        {
            for(j=0; j<=kuan+1; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }*/
        for(i=1; i<=chang; i++)
        {
            for(j=1; j<=kuan; j++)
            {
                if(b[i][j]==0)
                {
                    bfs2(i,j);
                    cnt2++;
                }
            }
        }
        printf("%d %d\n",cnt1-1,cnt2-1);
    }
}
