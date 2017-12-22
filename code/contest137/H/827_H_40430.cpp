#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long int LL;
typedef double de;
const int N = 50;
const int M = 100100;
const int oo = 0x3f3f3f3f;

int a[N][M];
int d[N][M];

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int n, x, t, v, mx;
	
	for (; scanf("%d", &n) && n ;) {
		mx = 0, memset( a, 0, sizeof( a ) );
		memset( d, - oo, sizeof( d ) );
		
		for (int i = 1;i <= n; ++i) {
			scanf("%d%d%d", &x, &t, &v);
			a[x][t] += v, mx = max( mx, t );
		}
		
		d[10][0] = a[10][0];
		for (int i = 1;i <= mx; ++i)
			for (int j = 0;j <= 20; ++j) {
				d[j][i] = d[j][i - 1] + a[j][i];
				if (j > 0) d[j][i] = max( d[j][i], d[j - 1][i - 1] + a[j][i] );
				if (j < 20) d[j][i] = max( d[j][i], d[j + 1][i - 1] + a[j][i] );
			}
		int ans(0);
		for (int i = 0;i <= 20; ++i)
			ans = max( ans, d[i][mx] );
		printf("%d\n", ans);
	}

	return 0;
}
