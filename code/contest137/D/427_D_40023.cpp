#include <bits/stdc++.h>
using namespace std;
#define M 100005
#define N 10005
struct E{
	int u,v,w;
}e[M];
int n,m;
int fa[N];
int ans;
int f(int x){
	return fa[x] == x ? x : f(fa[x]);
}
bool operator < (const E &l, const E &r){
	return l.w <r.w;
}
int main(){
	while(scanf("%d%d", &n, &m)  && n + m){
		for(int i = 1; i <= n; i++)
			fa[i] = i;
		ans = 0;
		for(int i = 1; i <= m; i++)
			scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		sort(e + 1, e + 1 + m);
		for(int i = 1; i <= m; i++){
			int x = e[i].u, y = e[i].v;
			int fx = f(x),fy = f(y);
			if(fx != fy){
				fa[fx] = fy;
				ans += e[i].w;
			}
		}
		printf("%d\n", ans);
	}
}
