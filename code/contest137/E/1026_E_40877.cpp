#include <string.h>
#include <stdio.h>
#define maxn 111

int vis[maxn][maxn];
char mat[maxn][maxn];
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int zx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int zy[8] = {-1, 1, 0, 1, -1, 0, 1, -1};
void dfs(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (vis[i][j] || mat[i][j] == '#') return;
    vis[i][j] = 1;
    int direct;
    for (direct = 0; direct < 4; ++direct)
    {
        dfs(i + dx[direct], j + dy[direct]);
    }
}
void zfs(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (vis[i][j] || mat[i][j] == '#') return;
    vis[i][j] = 1;
    int direct;
    for (direct = 0; direct < 8; ++direct)
    {
        zfs(i + zx[direct], j + zy[direct]);
    }
}


int main()
{
    int i, j, T, p;
    scanf("%d", &T);
    for(p=0; p<T; p++)
    {
        scanf("%d %d", &n, &m);
        for (i = 0; i < n; ++i)
        {
            scanf("%s", mat[i]);
        }
        memset(vis, 0, sizeof(vis));
        int cnt = 0, znt = 0;
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                if (mat[i][j] == '@' && vis[i][j] == 0)
                {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        memset(vis, 0 ,sizeof(vis));
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                if (mat[i][j] == '@' && vis[i][j] == 0)
                {
                    znt++;
                    zfs(i, j);
                }
            }
        }
        printf("%d %d\n", cnt, znt);
    }
    return 0;
}