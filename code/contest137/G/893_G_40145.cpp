#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define next ne
#define Mod 1008
#define inf 1e9
const int N=1010;
const int M=20010;
bool f[N];
struct S{int st,en,va,co;}aa[M],e[M];
int T,n,m,tot,point[N],next[M],dis[N],l[N],ans[N],num;
inline void add(int x,int y,int z){
	next[++tot]=point[x];point[x]=tot;
	aa[tot].st=x;aa[tot].en=y;aa[tot].va=1;aa[tot].co=z;
	next[++tot]=point[y];point[y]=tot;
	aa[tot].st=y;aa[tot].en=x;aa[tot].va=1;aa[tot].co=z;
}
inline void SPFA(int x){
	int h,t,i,u;
	for(i=1;i<=n;++i) dis[i]=inf;
	memset(ans,0,sizeof(ans));
	memset(f,1,sizeof(f));
	dis[x]=0;h=0;t=1;l[t]=x;ans[x]=0;
	while(h!=t){
		h=h%Mod+1;u=l[h];f[u]=true;
		for(i=point[u];i;i=next[i])
			if(dis[aa[i].en]>dis[u]+aa[i].va){
				dis[aa[i].en]=dis[u]+aa[i].va;
				ans[aa[i].en]=ans[u]+aa[i].co;
				if(f[aa[i].en]){
					t=t%Mod+1;
					l[t]=aa[i].en;
					f[aa[i].en]=false;
				}
			}
			else if(dis[aa[i].en]==dis[u]+aa[i].va&&ans[aa[i].en]>ans[u]+aa[i].co){
				ans[aa[i].en]=ans[u]+aa[i].co;
				if(f[aa[i].en]){
					t=t%Mod+1;
					l[t]=aa[i].en;
					f[aa[i].en]=false;
				}
			}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		printf("Case #%d:\n",++num);
		int i,j,x,y,z;
		scanf("%d%d",&n,&m);
		memset(point,0,sizeof(point));
		memset(next,0,sizeof(next));
		for(tot=0,i=1;i<=m;++i){
			scanf("%d%d%d",&x,&y,&z);
			e[i].st=x;e[i].en=y;
			add(x,y,z);
		}
		scanf("%d%d",&x,&y);
		SPFA(x);
		if(dis[y]==inf) puts("WTF?");
		else printf("%d %d\n",dis[y],ans[y]);
	}
}