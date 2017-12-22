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

int n, m;
char in[N];
int a[N][N], fa[N * N];

int Find ( int o ) {
	if (o == fa[o])
		return fa[o];
	return fa[o] = Find( fa[o] );
}

inline void Union ( int ii, int jj, int i, int j ) {
	int po1 = (ii - 1) * m + jj;
	int po2 = (i - 1) * m + j;
	int fa1 = Find( po1 );
	int fa2 = Find( po2 );
	fa[fa1] = fa2;
}

inline void four ( ) {
	for (int i = 1;i <= n; ++i)
		for (int j = 1;j <= m; ++j)
			fa[(i - 1) * m + j] = (i - 1) * m + j;
	for (int i = 1;i <= n; ++i)
		for (int j = 1;j <= m; ++j) 
			if (a[i][j]) {
			if (a[i - 1][j]) Union( i - 1, j, i, j );
			if (a[i + 1][j]) Union( i + 1, j, i, j );
			if (a[i][j - 1]) Union( i, j - 1, i, j );
			if (a[i][j + 1]) Union( i, j + 1, i, j );
		}
	int ans(0);
	for (int i = 1;i <= n; ++i)
		for (int j = 1;j <= m; ++j)
			if (a[i][j]) ans += (((i - 1) * m + j) == fa[(i - 1) * m + j]);
	printf("%d ", ans);
}

inline void eight ( ) {
	for (int i = 1;i <= n * m; ++i) fa[i] = i;
	for (int i = 1;i <= n; ++i)
		for (int j = 1;j <= m; ++j)
			if (a[i][j]) {
			if (a[i - 1][j]) Union( i - 1, j, i, j );
			if (a[i + 1][j]) Union( i + 1, j, i, j );
			if (a[i][j - 1]) Union( i, j - 1, i, j );
			if (a[i][j + 1]) Union( i, j + 1, i, j );
			if (a[i - 1][j - 1]) Union( i - 1, j - 1, i, j );
			if (a[i - 1][j + 1]) Union( i - 1, j + 1, i, j );
			if (a[i + 1][j - 1]) Union( i + 1, j - 1, i, j );
			if (a[i + 1][j + 1]) Union( i + 1, j + 1, i, j );
		}
	int ans(0);
	for (int i = 1;i <= n; ++i)
		for (int j = 1;j <= m; ++j)
			if (a[i][j]) ans += (((i - 1) * m + j) == fa[(i - 1) * m + j]);
	printf("%d", ans);
}

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	
	for (; T -- ;) {
		memset( a, 0, sizeof( a ) );
		
		scanf("%d%d", &n, &m);
		for (int i = 1;i <= n; ++i) {
			scanf("%s", in + 1);
			for (int j = 1;j <= m; ++j)
				a[i][j] = (in[j] == '@');
		}
		
		four( );
		eight( );
		printf("\n");
	}

	return 0;
}
