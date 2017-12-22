#include <bits/stdc++.h>
#define M 200005
#define N 2005
using namespace std;
struct E {
	int to,nxt;
}edge[M];
int tot,idx[N];
queue <int> q;
bool vis[N];
int n,m,ans,T;
void addedge(int from, int to){
	edge[++tot].to = to;
	edge[tot].nxt = idx[from];
	idx[from] = tot;
}
void bfs(int x){
	q.push(x);
	vis[x] = 1;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int t = idx[now]; t; t = edge[t].nxt){
			E e = edge[t];
			if(!vis[e.to]){
				q.push(e.to);
				vis[e.to] = 1;
			}
		}
	}
}
int main(){
    scanf("%d", &T);
    while(T--){
		scanf("%d%d", &n, &m);
		tot = 0;
		memset(idx, 0, sizeof(idx));
		for(int i = 1,x,y; i <= m; i++){
			scanf("%d%d", &x, &y);
			addedge(x, y);
			addedge(y, x);
		}
		memset(vis, 0, sizeof(vis));
		ans = 0;
		for(int i = 1; i <= n; i++)
			if(!vis[i]){
				bfs(i);
				ans++;
			}
		printf("%d\n", ans);
    }
}
