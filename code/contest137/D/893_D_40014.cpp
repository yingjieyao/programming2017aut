#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1010;
const int M=100010;
struct S{int x,y,z;}e[M];
int n,m,fa[N];
inline bool cmp(S x,S y){return x.z<y.z;}
inline int find(int x){
	if(x!=fa[x]) x=find(fa[x]);
	return fa[x];
}
int main(){
	while(scanf("%d%d",&n,&m)){
		if(!n&&!m) break;
		int i,ans=0,x,y;
		for(i=1;i<=m;++i)
			scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
		sort(e+1,e+m+1,cmp);
		for(i=1;i<=n;++i) fa[i]=i;
		for(i=1;i<=m;++i){
			x=find(e[i].x);
			y=find(e[i].y);
			if(x!=y){
				fa[x]=y;
				ans+=e[i].z;
			}
		}
		printf("%d\n",ans);
	}
}