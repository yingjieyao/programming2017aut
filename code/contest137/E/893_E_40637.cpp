#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200;
bool f[N][N];
char map[N][N];
int T,n,m,xi[8]={-1,0,0,1,-1,-1,1,1},yi[8]={0,-1,1,0,-1,1,-1,1},ans;
inline void dfs(int x,int y,int kind){
	int i;
	f[x][y]=false;
	for(i=0;i<kind;++i){
		int xx=x+xi[i],yy=y+yi[i];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&f[xx][yy]&&map[xx][yy]=='@')
			dfs(xx,yy,kind);
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		int i,j;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j){
				char ch=getchar();
				while(ch!='@'&&ch!='#') ch=getchar();
				map[i][j]=ch;
			}
		memset(f,1,sizeof(f));
		for(ans=0,i=1;i<=n;++i)
			for(j=1;j<=m;++j)
				if(map[i][j]=='@'&&f[i][j])
					dfs(i,j,4),++ans;
		printf("%d ",ans);
		memset(f,1,sizeof(f));
		for(ans=0,i=1;i<=n;++i)
			for(j=1;j<=m;++j)
				if(map[i][j]=='@'&&f[i][j])
					dfs(i,j,8),++ans;
		printf("%d\n",ans);
	}
}