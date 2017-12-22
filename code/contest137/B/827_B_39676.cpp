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

LL a, b, c, d;

inline LL f ( int x ) {
	return a * x * x * x + b * x + c;
}

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	for (; scanf(LLD LLD LLD LLD, &a, &b, &c, &d) == 4 ;) {
		LL l(-1001), r(1001), mid;
		for (; l < r ;) {
			mid = (l + r) >> 1;
			if (f( mid ) <= d) l = mid + 1;
			else r = mid;
		}
		printf(LLD"\n", l);
	}

	return 0;
}
