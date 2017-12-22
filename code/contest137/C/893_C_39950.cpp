#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define next ne
const int N=1010;
const int M=200010;
bool f[N];
struct S{int st,en;}aa[M];
int n,m,point[N],next[M],tot,T;
inline void add(int x,int y){
	next[++tot]=point[x];point[x]=tot;
	aa[tot].st=x;aa[tot].en=y;
	next[++tot]=point[y];point[y]=tot;
	aa[tot].st=y;aa[tot].en=x;
}
inline void dfs(int x){
	int i;
	f[x]=false;
	for(i=point[x];i;i=next[i])
		if(f[aa[i].en]) dfs(aa[i].en);
}
int main(){
	scanf("%d",&T);
	while(T--){
		int i,j,x,y;
		memset(point,0,sizeof(point));
		memset(next,0,sizeof(next));
		scanf("%d%d",&n,&m);
		for(tot=0,i=1;i<=m;++i){
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		int ans=0;
		memset(f,1,sizeof(f));
		for(i=1;i<=n;++i)
			if(f[i])
				dfs(i),++ans;
		printf("%d\n",ans);
	}
}