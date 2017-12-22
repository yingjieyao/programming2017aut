#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int max_n = 1000;

int t, n, m;
int is_visited[max_n];
int is_connected[max_n][max_n];

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		while(scanf("%d%d", &n, &m) == 2)
		{
			memset(is_visited, 0, sizeof(is_visited));
			memset(is_connected, 0, sizeof(is_connected));
			for(int i = 0; i < m; i++)
			{
				int a, b;
				scanf("%d%d", &a, &b);
				a--, b--;
				is_connected[a][b] = 1;
				is_connected[b][a] = 1;
			}
			queue<int> queue;
			int count = 0;
			for(int i = 0; i < n; i++)
			{
				if(!is_visited[i])
				{
					queue.push(i);
					is_visited[i] = 1;
					count++;
				}
				while(!queue.empty())
				{
					int tmp = queue.front();
					queue.pop();
					for(int j = 0; j < n; j++)
					{
						if(tmp == j) continue;
						if(is_connected[tmp][j] && !is_visited[j])
						{
							queue.push(j);
							is_visited[j] = 1;
						}
					}
				}
			}
			printf("%d\n", count);
		}
	}
	return 0;
}
