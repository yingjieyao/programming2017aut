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

	int T, n, m, po1, po2, ans;
	scanf("%d", &T);
	
	for (; T -- ;) {
		ans = 0;
		
		scanf("%d%d", &n, &m);
		for (int i = 1;i <= n; ++i) fa[i] = i;
		for (int i = 1;i <= m; ++i) {
			scanf("%d%d", &po1, &po2);
			Union( po1, po2 );
		}
		for (int i = 1;i <= n; ++i)
			ans += (i == fa[i]);
		printf("%d\n", ans);
	}

	return 0;
}
