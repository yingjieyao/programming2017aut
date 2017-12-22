#include <bits/stdc++.h>
using namespace std;
#define N 20005
#define inf 0x7fffffff
struct P{
	int x,w1,w2;
	bool operator < (const P &p) const{
		return (p.w1 < w1) || (p.w1 == w1 && p.w2 < w2);
	}
};
struct E{
	int to,nxt,w1,w2;
}edge[N];
priority_queue <P> q;
int T,n,m,s,en;
int tot,idx[N];
int dis1[N],dis2[N];
bool vis[N];
void addedge(int from, int to, int w1, int w2){
	edge[++tot].to = to;
	edge[tot].w1 = w1;
	edge[tot].w2 = w2;
	edge[tot].nxt = idx[from];
	idx[from] = tot;
}
void dijkstra(){
	memset(vis, 0, sizeof(vis));
	fill(dis1, dis1 + 1 + n, inf);
	fill(dis2, dis2 + 1 + n, inf);
	dis1[s] = 0;
	dis2[s] = 0;
	q.push((P){s,0,0});
	while(!q.empty()){
		P p= q.top();
		//printf("!!!%d %d %d\n", p.x, p.w1, p.w2);
		q.pop();
		if(vis[p.x]) continue;
		vis[p.x] = 1;
		for(int t = idx[p.x]; t; t = edge[t].nxt){
			E e = edge[t];
			if(dis1[e.to] >= dis1[p.x] + e.w1){
				//if(p.x == 5 && e.to == 6) printf(" ");
				if(dis1[e.to] == dis1[p.x] + e.w1)
					dis2[e.to] = min(dis2[e.to], dis2[p.x] + e.w2);
				else dis2[e.to] = dis2[p.x] + e.w2;
				dis1[e.to] = dis1[p.x] + e.w1;
				q.push((P){e.to, dis1[e.to], dis2[e.to]});
			}
		}
	}
}
int main(){
	scanf("%d", &T);
	for(int k = 1; k <= T; k++){
		tot = 0;
		memset(idx, 0, sizeof(idx));
		scanf("%d%d", &n, &m);
		for(int i = 1,u,v,w; i <= m; i++){
			scanf("%d%d%d", &u, &v, &w);
			addedge(u, v, 1, w);
			addedge(v, u, 1, w);
		}
		scanf("%d%d", &s, &en);
		dijkstra();
		if(dis1[en] == inf) printf("Case #%d:\nWTF?\n", k);
		else printf("Case #%d:\n%d %d\n", k, dis1[en], dis2[en]);
	}
}
