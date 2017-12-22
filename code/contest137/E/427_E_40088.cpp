#include <bits/stdc++.h>
using namespace std;
#define N 205
int dirx[10]={0,1,0,-1,1,1,-1,-1};
int diry[10]={1,0,-1,0,-1,1,-1,1};
int ans1,ans2,n,m,T;
bool vis[N][N];
char mp[N][N];
bool judge(int x, int y){
	return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] == '@' && vis[x][y] == 0;
}
void dfs1(int x, int y){
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = dirx[i] + x;
		int ny = diry[i] + y;
		if(judge(nx,ny))
			dfs1(nx,ny);
	}
}
void dfs2(int x, int y){
	vis[x][y] = 1;
	for(int i = 0; i < 8; i++){
		int nx = dirx[i] + x;
		int ny = diry[i] + y;
		if(judge(nx,ny))
			dfs2(nx,ny);
	}
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			scanf("%s", mp[i] + 1);
		ans1 = 0; ans2 = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(mp[i][j] == '@' && vis[i][j] == 0){
					dfs1(i,j);
					ans1++;
				}
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(mp[i][j] == '@' && vis[i][j] == 0){
					dfs2(i,j);
					ans2++;
				}
		printf("%d %d\n", ans1, ans2);
	}
}
