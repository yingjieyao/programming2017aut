#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
   if (!b)return a;
   else return gcd(b,a%b);
   }
int n,a[505];
ll r;
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
    scanf("%d",&n);r=1000000000ll;r=r*r;
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    for (int i=1;i<n;i++)
    for (int j=i+1;j<=n;j++)r=min(r,1ll*a[i]*a[j]/gcd(1ll*a[i],1ll*a[j]));
    printf("%lld\n",r);
    }
    //for(;;);
    return 0;
}
