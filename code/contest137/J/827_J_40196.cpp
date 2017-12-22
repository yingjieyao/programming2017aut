#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long int LL;
typedef double de;
const int N = 110;
const int M = 100100;
const int oo = 0x3f3f3f3f;

char qus[N][N];
char ans[N][N];
char in[N];

inline bool cmp ( int j ) {
	int len1 = strlen( qus[j] );
	int len2 = strlen( in );
	if (len1 != len2) return false;
	for (int i = 1;i <= len1; ++i)
		if (qus[j][i] != in[i]) return false;
	return true;
}

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int n, m;
	scanf("%d%d\n", &m, &n);
	for (int i = 1;i <= m; ++i)
		gets( qus[i] ), gets( ans[i] );
	
	bool ok;
	for (int i = 1;i <= n; ++i) {
		gets( in ), ok = 0;
		for (int j = 1;j <= m; ++j)
			if (cmp( j ))
				{ printf("%s\n", ans[j]), ok = 1; break ; }
		if (!ok) printf("What are you saying?\n");
	}
	return 0;
}
