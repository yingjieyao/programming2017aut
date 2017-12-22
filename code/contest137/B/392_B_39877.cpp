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
LL a,b,c,d;

LL f(LL x){
    return a*x*x*x+b*x+c-d;
}

int main(){
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&d)!=EOF){
        LL r=1000,l=-1000,mid,ans;
        while(l<=r){
            mid=(l+r)/2;
            if (f(mid)>0){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
