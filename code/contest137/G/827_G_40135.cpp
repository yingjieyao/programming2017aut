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

int d[N], dis[N], vis[N];
int q[M];

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

	int T, po1, po2, inv, S, E, n, m;
	scanf("%d", &T);
	
	for (int ct(1); T -- ; ++ct) {
		cat = 0, memset( head, 0, sizeof( head ) );
		memset( d, oo, sizeof( d ) );
		memset( dis, oo, sizeof( dis ) );
		memset( vis, 0, sizeof( vis ) );
		
		scanf("%d%d", &n, &m);
		for (int i = 1;i <= m; ++i) {
			scanf("%d%d%d", &po1, &po2, &inv);
			Ins( po1, po2, inv ), Ins( po2, po1, inv );
		}
		scanf("%d%d", &S, &E);
		
		int l(1), r(0), o;
		d[q[++r] = S] = 0, dis[S] = 0, vis[S] = 1;
		for (; l <= r ;) {
			o = q[l ++];
			for (int i = head[o]; i ; i = lk[i].nt)
				if (d[lk[i].p] > d[o] + 1) {
					d[lk[i].p] = d[o] + 1;
					dis[lk[i].p] = dis[o] + lk[i].v;
					if (!vis[lk[i].p]) q[++r] = lk[i].p, vis[lk[i].p] = 1;
				}
				else if (d[lk[i].p] == d[o] + 1 && dis[lk[i].p] > dis[o] + lk[i].v) {
					dis[lk[i].p] = dis[o] + lk[i].v;
					if (!vis[lk[i].p]) q[++r] = lk[i].p, vis[lk[i].p] = 1;
				}
			vis[o] = 0;
		}
		
		printf("Case #%d:\n", ct);
		if (dis[E] == oo) printf("WTF?\n");
		else printf("%d %d\n", d[E], dis[E]);
	}

	return 0;
}
