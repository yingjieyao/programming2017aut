#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<queue>
#include<cctype>
using namespace std;

const int Maxn=110;
int igraph[Maxn][Maxn],icolor[Maxn][Maxn];
int n,m,sizen,t,ans;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,1,-1,-1,1,1,-1};
struct T
{
    int x,y;
};

bool judge(int x,int y)
{
    if (x<1 || x>sizen || y<1 || y>m)
        return false;
    else
        return true;
}

int bfs(int sx,int sy,bool flag)
{
    queue <T> q;
    T temp;
    temp.x=sx;
    temp.y=sy;
    q.push(temp);
    icolor[sx][sy]=ans;
    while (!q.empty())
    {
        T x=q.front();
        q.pop();
        if (flag)
        {
            for (int i=0;i<4;i++)
            {
                int nowx=x.x+dx[i];
                int nowy=x.y+dy[i];
                if (judge(nowx,nowy) && igraph[nowx][nowy]!=0 && icolor[nowx][nowy]==0)
                {
                    icolor[nowx][nowy]=ans;
                    temp.x=nowx;
                    temp.y=nowy;
                    q.push(temp);
                }
            }
        }
        else
        {
            for (int i=0;i<8;i++)
            {
                int nowx=x.x+dx[i];
                int nowy=x.y+dy[i];
                if (judge(nowx,nowy) && igraph[nowx][nowy]!=0 && icolor[nowx][nowy]==0)
                {
                    icolor[nowx][nowy]=ans;
                    temp.x=nowx;
                    temp.y=nowy;
                    q.push(temp);
                }
            }
        }
    }
}

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&sizen,&m);
        memset(icolor,0,sizeof(icolor));
        ans=0;
        char c;
        for (int i=1;i<=sizen;i++)
            for (int j=1;j<=m;j++)
            {
                c=getchar();
                while (isspace(c))
                    c=getchar();
                if (c=='@')
                {
                    n++;
                    igraph[i][j]=n;
                }
                else
                    igraph[i][j]=0;
            }
        for (int i=1;i<=sizen;i++)
            for (int j=1;j<=m;j++)
                if (igraph[i][j]!=0 && icolor[i][j]==0)
                {
                    ++ans;
                    bfs(i,j,true);
                }
        printf("%d ",ans);
        memset(icolor,0,sizeof(icolor));
        ans=0;
        for (int i=1;i<=sizen;i++)
            for (int j=1;j<=m;j++)
                if (igraph[i][j]!=0 && icolor[i][j]==0)
                {
                    ++ans;
                    bfs(i,j,false);
                }
        printf("%d\n",ans);
    }
    return 0;
}
