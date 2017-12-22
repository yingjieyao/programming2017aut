#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long int LL;
typedef double de;
const int N = 1100;
const int M = 100100;

struct Edge {
	int po1, po2, v;
	Edge ( ) : po1(0), po2(0), v(0) { }
} lk[M << 1];

bool cmp ( Edge cmp_a, Edge cmp_b ) {
	return cmp_a.v < cmp_b.v;
}

int fa[N];

int Find ( int o ) {
	if (o == fa[o])
		return fa[o];
	return fa[o] = Find( fa[o] );
}

inline void Union ( int po1, int po2 ) {
	int fa1 = Find( po1 );
	int fa2 = Find( po2 );
	fa[fa1] = fa2;
}

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int n, m;
	
	for (; scanf("%d%d", &n, &m) && n + m ;) {
		for (int i = 1;i <= m; ++i)
			scanf("%d%d%d", &lk[i].po1, &lk[i].po2, &lk[i].v);
		sort( lk + 1, lk + m + 1, cmp );
		
		int tot(0);
		for (int i = 1;i <= n; ++i) fa[i] = i;
		for (int i = 1;i <= m; ++i)
			if (Find( lk[i].po1 ) != Find( lk[i].po2 ))
				Union( lk[i].po1, lk[i].po2 ), tot += lk[i].v;
		printf("%d\n", tot);
	}
	
	return 0;
}
