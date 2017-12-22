#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int m, n;
char ma[110][110];
bool vis[110][110];
int a[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
int b[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void sear(int x, int y, int co)
{
    if(((x < 0 || x >= n) || (y < 0 || y >= m))|| (vis[x][y] || ma[x][y] == '#')) return;
    else
    {
        vis[x][y] = true;
        if(co == 1)
        {
            int t1, t2;
            for(int i = 0; i < 8; i++)
            {
                t1 = x + a[i][0];
                t2 = y + a[i][1];
                sear(t1, t2, 1);
            }
        }
        else if(co == 2)
        {
            int t1, t2;
            for(int i = 0; i < 4; i++)
            {
                t1 = x + b[i][0];
                t2 = y + b[i][1];
                sear(t1, t2, 2);
            }
        }
    }
    return;
}

int main()
{
    /*#ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE*/
    int t;
    scanf("%d", &t);
    for(int t1 = 0 ; t1 < t; t1++)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%s", ma[i]);
                int m1 = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(ma[i][j] == '@' && !vis[i][j])
                {
                    m1++;
                    sear(i, j, 1);
                }
            }
        memset(vis, 0, sizeof(vis));
        int m2 = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(ma[i][j] == '@' && !vis[i][j])
                {
                    m2++;
                    sear(i, j, 2);
                }
            }
        printf("%d %d\n", m2, m1);
    }
    return 0;
}
