#include <bits/stdc++.h>
#define inf 0x7fffffff
#define N 10005
using namespace std;
struct E{
	int to,nxt,w;
}edge[N];
bool fl,vis[N];
int tot,idx[N],t[N],dis[N],ans[N],in[N],n,m;
queue<int>q;
void addedge(int from, int to, int w){
	edge[++tot].to = to;
	edge[tot].w = w;
	edge[tot].nxt = idx[from];
	idx[from] = tot;
}
void spfa(int s){
	q.push(s);
	fl = 0;
	memset(t, 0, sizeof(t));
	memset(dis, 0, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	while(!q.empty()){
		int x = q.front();
		q.pop();
		t[x]++;
		vis[x] = 0;
		for(int t = idx[x]; t; t = edge[t].nxt){
			E e = edge[t];
			if(dis[e.to] < dis[x] + e.w){
				dis[e.to] = dis[x] + e.w;
				if(!vis[e.to]){
					vis[e.to] = 1;
					q.push(e.to);
				}
			}
		}
		if(t[x] > n){
			fl = 1;
			break;
		}
	}

	//for(int i = 1; i <= n; i++) printf("%d ",dis[i]);
	if(fl)
		while(!q.empty()) q.pop();
	if(!fl)
		for(int i = 1; i <= n; i++)
			ans[i] = max(ans[i], dis[i]);
}
int main(){
	while(scanf("%d%d", &n, &m) == 2){
		memset(ans, 0, sizeof(ans));
		memset(idx, 0, sizeof(idx));
		memset(in, 0, sizeof(in));
		tot = 0;
		for(int i = 1,u,v,w; i <= m; i++){
			scanf("%d%d%d", &u, &v, &w);
			//printf("%d %d %d\n",u,v,w);
			addedge(u,v,w);
			in[v]++;
			//if(m == 6) {for(int j = 1; j <= n; j++) printf("%d ",in[j]);puts("");}
		}

		for(int i = 1; i <= n; i++){
			spfa(i);
			if(fl){
				puts("NO SOLUTION");
				break;
			}
		}
		if(!fl)
			for(int i = 1; i <= n; i++)
				printf("%d\n",ans[i]);
	}
	return 0;
}
