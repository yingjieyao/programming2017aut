#include <stdio.h>
#include <stdlib.h>

char a[105][105], b[105][105];
int que;
int n, m;
void bfs1 (int i, int j)
{
    if (i < 0 || j < 0)
        return;
    if (i >= n || j >= m)
        return;
    if (a[i][j] == '@')
    {
        que ++;
        a[i][j] = '#';
        bfs1(i+1,j);
        bfs1(i,j+1);
        bfs1(i-1,j);
        bfs1(i,j-1);
    }
    return;
}

void bfs2 (int i, int j)
{
    if (i < 0 || j < 0)
        return;
    if (i >= n || j >= m)
        return;
    if (b[i][j] == '@')
    {
        que ++;
        b[i][j] = '#';
        bfs2(i+1,j);
        bfs2(i,j+1);
        bfs2(i+1,j-1);
        bfs2(i+1,j+1);
        bfs2(i-1,j);
        bfs2(i,j-1);
        bfs2(i-1,j+1);
        bfs2(i-1,j-1);
    }
    return;
}


int main()
{
    int t;
    scanf("%d", &t);
    int i, j, k;
    for (i = 0; i < t; i++)
    {
        scanf ("%d %d", &n, &m);
        int num1 = 0, num2 = 0;
        for (j = 0; j < n; j++)
        {
            scanf("%s",a[j]);
            for (k = 0; k < m; k++)
            {
                b[j][k] = a[j][k];
            }
        }
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < m; k++)
            {
                que = 0;
                bfs1(j,k);
                if (que != 0)
                    num1 ++;
                que = 0;
                bfs2(j,k);
                if (que != 0)
                    num2 ++;
            }
        }
        printf ("%d %d\n", num1, num2 );

    }
    return 0;
}
