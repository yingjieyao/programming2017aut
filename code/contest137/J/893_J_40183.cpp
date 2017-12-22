#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=110;
int n,m;
char ch[N],b[N][N];
struct S{char q[N],a[N];int x,y;}s[N];
inline bool check(int x,int y){
	int xx,yy;
	xx=strlen(b[x]);yy=s[y].x;
	if(xx!=yy) return false;
	int i;
	for(i=1;i<=xx;++i)
		if(b[x][i]!=s[y].q[i]) return false;
	return true;
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);gets(ch);
	for(i=1;i<=n;++i){
		gets(s[i].q);
		gets(s[i].a);
		s[i].x=strlen(s[i].q);
		s[i].y=strlen(s[i].a);
	}
	for(i=1;i<=m;++i){
		gets(b[i]);
		bool f=false;
		for(j=1;j<=n;++j)
			if(check(i,j)){
				f=true;
				printf("%s\n",s[j].a);
				break;
			}
		if(!f) puts("What are you saying?");
	}
}