#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define next ne
const int N=1010;
struct S{int st,en,va;}aa[N];
int n,m,tot,point[N],next[N],ru[N],maxn[N],l[N],h,t;
inline void add(int x,int y,int z){
	next[++tot]=point[x];point[x]=tot;++ru[y];
	aa[tot].st=x;aa[tot].en=y;aa[tot].va=z;
}
int main(){
	while(scanf("%d%d",&n,&m)==2){
		int i,j,x,y,z,u;
		memset(point,0,sizeof(point));
		memset(next,0,sizeof(next));
		memset(ru,0,sizeof(ru));
		for(tot=0,i=1;i<=m;++i){
			scanf("%d%d%d",&x,&y,&z);
			add(x,y,z);
		}
		memset(maxn,0,sizeof(maxn));
		h=1;t=0;
		for(i=1;i<=n;++i)
			if(!ru[i]) l[++t]=i;
		while(h<=t){
			u=l[h];
			for(i=point[u];i;i=next[i]){
				maxn[aa[i].en]=max(maxn[aa[i].en],maxn[u]+aa[i].va);
				--ru[aa[i].en];
				if(!ru[aa[i].en]) l[++t]=aa[i].en;
			}
			++h;
		}
		if(t!=n) puts("NO SOLUTION");
		else{
			for(i=1;i<=n;++i)
				printf("%d\n",maxn[i]);
		}
	}
}