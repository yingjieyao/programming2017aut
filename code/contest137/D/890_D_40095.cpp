#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int maxn = 1005;
const int maxm = 100005;
typedef long long LL;
int m;
int fa[maxn];
struct road
{
	int a, b, cost;
} roads[maxm];
void init(int n)
{
	for(int i = 0; i <= n; i++)
	{
		fa[i] = i;
	}
}

int cmp(road x, road y)
{
	return x.cost < y.cost;
}

int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

LL kruskal(int n)
{
	int rec = 0;
	sort(roads, roads+m, cmp);
	LL ans = 0;
	for (int i = 0; i < m; i++)
	{
		if (rec == n - 1)	break;
		int x = find(roads[i].a);
		int y = find(roads[i].b);
		if (x != y)
		{
			fa[x] = y;
			ans += roads[i].cost;
			rec++;
		}
	}
	return ans;
}
int main()
{
	int n;
	while(scanf("%d %d", &n, &m) != EOF && (n || m))
	{
		init(n);
		for(int i = 0; i < m; i++)
		{
			int u, v, t;
			scanf("%d %d %d", &u, &v, &t);
			roads[i].a = u;
			roads[i].b = v;
			roads[i].cost = t;
		}
		printf("%lld\n", kruskal(n));
	}
	return 0;
}