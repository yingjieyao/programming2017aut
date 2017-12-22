#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAX_N		1000

int costs_table[MAX_N][MAX_N];
int costs[MAX_N];
int times[MAX_N];

int main()
{
	int t;
	scanf("%d", &t);
	for(int count = 1; count <= t; count++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		memset(costs_table, 0, sizeof(costs_table));
		memset(costs, 0, sizeof(costs));
		memset(times, 0, sizeof(times));
		for(int i = 0; i < m; i++)
		{
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
			u--, v--;
			if(costs_table[u][v] == 0)
			{
				costs_table[u][v] = c;
				costs_table[v][u] = c;
			}
			else if(costs_table[u][v] > c)
			{
				costs_table[u][v] = c;
				costs_table[v][u] = c;
			}
		}
		int S, E;
		scanf("%d%d", &S, &E);
		S--, E--;
		printf("Case #%d:\n", count);
		queue<int> queue;
		queue.push(S);
		while(!queue.empty())
		{
			int tmp = queue.front();
			queue.pop();
			for(int i = 0; i < n; i++)
			{
				if(tmp == i) continue;
				if(costs_table[tmp][i] != 0)
				{
					if(times[i] == 0)
					{
						times[i] = times[tmp] + 1;
						costs[i] = costs[tmp] + costs_table[tmp][i];
						queue.push(i);
					}
					else if(times[i] == times[tmp] + 1 && costs[i] > costs[tmp] + costs_table[tmp][i]) costs[i] = costs[tmp] + costs_table[tmp][i];
					else if(times[i] > times[tmp] + 1)
					{
						times[i] = times[tmp] + 1;
						costs[i] = costs[tmp] + costs_table[tmp][i];
					}
				}
			}
		}
		if(costs[E] != 0) printf("%d %d\n", times[E], costs[E]); else printf("WTF?\n");
	}
	return 0;
}
