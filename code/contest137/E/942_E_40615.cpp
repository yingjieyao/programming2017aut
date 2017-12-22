#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
struct Node
{
    int x,y;
};
queue<Node>q;
char a[111][111];
int vis[111][111];
int n,m;
int dx[5] = {4,1,-1,0,0};
int dy[5] = {4,0,0,1,-1};
int fx[9] = {8,1,1,1,0,0,-1,-1,-1};
int fy[9] = {8,1,0,-1,1,-1,1,0,-1};
void bfs(int x[],int y[],int sx,int sy)
{
    while (!q.empty()) q.pop();
    Node st;
    st.x = sx;
    st.y = sy;
    vis[sx][sy] = 1;
    q.push(st);
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        for (int direct = 1; direct <= x[0]; direct++)
        {
            Node nx;
            nx.x = cur.x + x[direct];
            nx.y = cur.y + y[direct];
            if (nx.x < 0 || nx.y < 0 || nx.x >= n || nx.y >= m) continue;
            else if (vis[nx.x][nx.y] || a[nx.x][nx.y] == '#') continue;
            else
            {
                q.push(nx);
                vis[nx.x][nx.y] = 1;
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d\n",&n,&m);
        for (int i = 0; i < n; i++)
            gets(a[i]);
        int cou1 = 0,cou2 = 0;
        memset(vis,0,sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((!vis[i][j]) && (a[i][j] == '@'))
                {
                    bfs(dx,dy,i,j);
                    cou1++;
                }
            }
        }
        memset(vis,0,sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((!vis[i][j]) && (a[i][j] == '@'))
                {
                    bfs(fx,fy,i,j);
                    cou2++;
                }
            }
        }
        printf("%d %d\n",cou1,cou2);
    }
    return 0;
}
