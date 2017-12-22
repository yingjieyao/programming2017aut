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
const int oo = 0x3f3f3f3f;

de a[N], ans[N];

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int T, n;
	scanf("%d", &T);
	
	for (int ct(1); T -- ; ++ct) {
		memset( ans, 0, sizeof( ans ) );
		
		scanf("%d", &n);
		for (int i = 1;i <= n; ++i)
			scanf("%lf", &a[i]);
		de o(0);
		for (int all(0); all < n ;)
			for (int i = 1;i <= n; ++i)
				if (a[i] > 0) {
					if (a[i] <= 1.0) {
						ans[i] = o + a[i];
						o = o + a[i] + 1.0;
						a[i] -= 1.0, ++all;
					}
					else a[i] -= 1.0, o += 1.0;
				}
		printf("Case %d:", ct);
		for (int i = 1;i <= n; ++i)
			printf("%.2lf ", ans[i]);
		printf("\n");
	}

	return 0;
}
