#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
ll a,b,c,d,L,R,q,p;
ll ck(ll w){   
     if(1ll*a*w*w*w+1ll*b*w+c>d)return 1;
     return 0;
     }
ll work(ll l,ll r){
      while (l+1<r){
             ll mid=(l+r)/2;
             if (ck(mid))r=mid;
             else l=mid;
             }
       return r;
    }
int main(){
    q=-1000;p=1000;
    while (scanf("%lld%lld%lld%lld",&a,&b,&c,&d)!=EOF){
        printf("%lld\n",work(q,p));
    }
    //for(;;);
    return 0;
}
