#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;
int n,f[N][25],m;
struct S{int d,t,w;}a[N];
inline bool cmp(S x,S y){return x.t<y.t;}
int main(){
	while(scanf("%d",&m)){
		if(!m) break;
		int i,j,ans=0;
		for(i=1;i<=m;++i)
			scanf("%d%d%d",&a[i].d,&a[i].t,&a[i].w);
		sort(a+1,a+m+1,cmp);
		int now=1;
		for(i=0;i<=20;++i) f[0][i]=-1;
		f[0][10]=0;
		for(i=1;now<=m;++i){
			for(j=0;j<=20;++j){
				int o=0,oo=0;
				f[i][j]=-1;
				if(j!=0){
					if(f[i-1][j-1]!=-1) o=max(o,f[i-1][j-1]),oo=1;
				}
				if(f[i-1][j]!=-1) o=max(o,f[i-1][j]),oo=1;
				if(j!=20){
					if(f[i-1][j+1]!=-1) o=max(o,f[i-1][j+1]),oo=1;
				}
				if(oo) f[i][j]=o;
			}
			for(j=now;a[j].t==i;++j)
				if(f[i][a[j].d]!=-1)
					f[i][a[j].d]+=a[j].w;
			now=j;
		}
		for(i=0;i<=20;++i)
			ans=max(ans,f[a[m].t][i]);
		printf("%d\n",ans);
	}
}