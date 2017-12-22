#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn = 105;
const int mas = 8;
char map[maxn][maxn];
int vis[maxn][maxn];
int n, m;
struct Node{
    int x, y;
    int step;
};
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
stack<Node> way;
void DFS1(int x, int y);
void DFS2(int x, int y)
{
    while(!way.empty())    way.pop();
	
	Node beg;
    beg.x = x, beg.y = y, beg.step = 0;
    way.push(beg);
//    vis[beg.x][beg.y] = 1;
    map[beg.x][beg.y] = '#';
    while(!way.empty())
    { 
        Node cur = way.top();
        way.pop();
        for(int i = 0; i < 8; i++)
        {
            Node next;
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];

            if(next.x < 0 || next.x >= n || next.y < 0 || next.y >= m)    continue;
            if(map[next.x][next.y] == '#')    continue;

            next.step = cur.step + 1;
//            vis[next.x][next.y] = 1;
            way.push(next);
            map[next.x][next.y] = '#';
        }
    }
    return;
}
int main()
{
	int kase;
	scanf("%d", &kase);
	while(kase--)
	{
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++)
		{
			scanf("%s", map[i]);
		}
		int ans1 = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(map[i][j] == '@' && vis[i][j] == 0)
				{
					DFS1(i, j);
					ans1++;
				}
			}
		}
//		printf("\n");
//		for(int i = 0; i < n; i++)
//			printf("%s\n", map[i]);
//		printf("\n");
		int ans2 = 0;
		memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {   
                if(map[i][j] == '@')
                {
                    DFS2(i, j);
                    ans2++;
                }
            }
        }
//		for(int i = 0; i < n; i++)
//			printf("%s\n", map[i]);
//		printf("\n");
        printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
void DFS1(int x, int y)
{
    while(!way.empty())    way.pop();

    Node beg;
    beg.x = x, beg.y = y, beg.step = 0;
    way.push(beg);
    vis[beg.x][beg.y] = 1;
    while(!way.empty())
    { 
        Node cur = way.top();
        way.pop();
        for(int i = 0; i < 4; i++)
        {
            Node next;
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];

            if(next.x < 0 || next.x >= n || next.y < 0 || next.y >= m)    continue;
            if(vis[next.x][next.y] || map[next.x][next.y] == '#')    continue;

            next.step = cur.step + 1;
            vis[next.x][next.y] = 1;
            way.push(next);
        }
    }
    return;
}