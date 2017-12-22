#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=110;
bool f[N];
int T,n,num=0,sum=0;
double a[N],ans[N];
int main(){
	scanf("%d",&T);
	while(T--){
		printf("Case %d:",++sum);
		int i,j,o=1;
		double now=0;
		scanf("%d",&n);
		for(i=1;i<=n;++i) scanf("%lf",&a[i]);
		memset(f,1,sizeof(f));
		num=0;
		while(1){
			if(a[o]>1.0){
				a[o]-=1.0;
				now+=1.0;
			}
			else{
				ans[o]=now+a[o];
				f[o]=false;
				now+=a[o]+1.0;
				++num;
				if(num==n) break;
			}
			while(1){
				++o;
				if(o==n+1) o=1;
				if(f[o]) break;
			}
		}
		for(i=1;i<=n;++i)
			printf("%.2f ",ans[i]);
		printf("\n");
	}
}