#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define LL long long
const int N=600;
int T,n,a[N];
inline LL gcd(int x,int y){
	if(x<y) swap(x,y);
	if(x%y==0) return y;
	else return gcd(y,x%y);
}
int main(){
	scanf("%d",&T);
	while(T--){
		LL ans=0LL;
		int i,j;
		scanf("%d",&n);
		for(i=1;i<=n;++i) scanf("%d",&a[i]);
		for(i=1;i<=n;++i){
			for(j=i+1;j<=n;++j){
				LL now=(LL)a[i]*(LL)a[j];
				LL o=now/gcd(a[i],a[j]);
				if(ans==0LL) ans=o;
				else ans=min(ans,o);
			}
		}
		cout<<ans<<endl;
	}
}