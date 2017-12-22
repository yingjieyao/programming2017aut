#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;

typedef long long LL;
const int MAXN=1e5+5;
const int MAXM=1e5+5;
const int INF=1e5+5;
const int mod=1e5+5;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

int n;
LL x[MAXN];

LL gcd(LL a,LL b){
    if (b==0) return a;
    return gcd(b,a%b);
}

LL lcm(LL a,LL b){
    return (a/gcd(a,b))*b;
}

int main(){
	int aa; scanf("%d",&aa);
	while(aa--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        LL ans=1000000000000000000;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){
                ans=min(ans,lcm(x[i],x[j]));
            }
        printf("%lld\n",ans);
	}
}
