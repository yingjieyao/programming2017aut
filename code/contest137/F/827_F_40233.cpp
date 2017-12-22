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

int q[M], dis[N], ind[N];

int cat, head[N] = {0};

struct Edge {
	int p, nt, v;
	Edge ( ) : p(0), nt(0), v(0) { }
	Edge ( int _p, int _nt, int _v )
	{ p = _p, nt = _nt, v = _v; }
} lk[M];

inline void Ins ( int In_po1, int In_po2, int In_v ) {
	lk[++cat] = Edge( In_po2, head[In_po1], In_v );
	head[In_po1] = cat;
}

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int n, m, po1, po2, inv; bool ok;
	
	for (; scanf("%d%d", &n, &m) == 2 ;) {
		memset( ind, 0, sizeof( ind ) );
		ok = 0, cat = 0, memset( head, 0, sizeof( head ) );
		memset( dis, 0, sizeof( dis ) );
		
		for (int i = 1;i <= m; ++i) {
			scanf("%d%d%d", &po1, &po2, &inv);
			ind[po2] ++, Ins( po1, po2, inv );
		}
		
		int l(1), r(0), o;
		for (int i = 1;i <= n; ++i)
			if (!ind[i]) q[++r] = i, dis[i] = 0;
		for (; l <= r ;) {
			o = q[l ++];
			for (int i = head[o]; i ; i = lk[i].nt) {
				ind[lk[i].p] --, dis[lk[i].p] = max( dis[lk[i].p], dis[o] + lk[i].v );
				if (!ind[lk[i].p]) q[++r] = lk[i].p;
			}
		}
		
		for (int i = 1;i <= n; ++i)
			if (ind[i]) ok = 1;
		if (ok) printf("NO SOLUTION\n");
		else {
			for (int i = 1;i <= n; ++i)
				printf("%d\n", dis[i]);
		}
	}

	return 0;
}
