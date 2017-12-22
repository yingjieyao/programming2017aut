#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long int LL;
const int N = 1100;

LL a[N]; int c;
LL b[N * N];

int gcd ( int ra, int rb ) {
	if (!rb) return ra;
	return gcd( rb, ra % rb );
}

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int T, n;
	scanf("%d", &T);
	
	for (; T -- ;) {
		c = 0;
		
		scanf("%d", &n);
		for (int i = 1;i <= n; ++i)
			scanf(LLD, &a[i]);
		for (int i = 1;i < n; ++i)
			for (int j = i + 1;j <= n; ++j)
				b[++c] = a[i] * a[j] / gcd( a[i], a[j] );
		sort( b + 1, b + c + 1 );
		printf(LLD"\n", b[1]);
	}

	return 0;
}
