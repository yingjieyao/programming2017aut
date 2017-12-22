#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define mid (l+r)/2
#define LL long long
LL a,b,c,d;
inline bool check(LL x){return a*x*x*x+b*x+c>0LL;}
int main(){
	while(scanf("%lld%lld%lld%lld",&a,&b,&c,&d)==4){
		c-=d;
		LL l=-1000,r=1000,ans=1000;
		while(l<=r){
			if(check(mid)) ans=min(ans,mid),r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
}