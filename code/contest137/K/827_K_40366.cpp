#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long int LL;
typedef double de;
const int N = 100100;
const int M = 100100;
const LL oo = (1ll << 60);

struct point {
	int cn; LL d;
} a[N];

bool cmp ( point cmp_a, point cmp_b ) {
	return cmp_a.d < cmp_b.d;
}

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int T, n; bool ok;
	scanf("%d", &T);
	
	for (int ct(1); T -- ; ++ct) {
		ok = 0;
		
		scanf("%d", &n);
		for (int i = 1;i <= n; ++i) scanf(LLD, &a[i].d);
		for (int i = 1;i <= n; ++i) scanf("%d", &a[i].cn), ok |= a[i].cn;
		
		if (!ok) { printf("Case #%d: -1\n", ct); continue ; }
		
		sort( a + 1, a + n + 1, cmp );
		
		LL ans(0); int l(0), r(1);
		for (; !a[r].cn ; ++r);
		ans += (a[r].d - a[1].d);
		l = r; for (r = r + 1; !a[r].cn && r <= n ; ++r);
		for (; r <= n ;) {
			LL mx(0);
			for (int i = l;i < r; ++i)
				mx = max( mx, a[i + 1].d - a[i].d );
			ans += (a[r].d - a[l].d - mx);
			l = r; for (r = r + 1; !a[r].cn && r <= n ; ++r);
		}
		ans += (a[n].d - a[l].d);
		printf("Case #%d: "LLD"\n", ct, ans);
	}
	
	return 0;
}
