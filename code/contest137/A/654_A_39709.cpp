#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;
int n;
int a[505];
typedef long long ll;
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int T=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        ll ans=10000000000LL;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ll ta,tb;
                ta=ll(a[i]),tb=ll(a[j]);
                ll zx=gcd(ta,tb);
                ll zd=ta*tb/zx;
                //cout<<zx<<' '<<zd<<endl;
                ans=min(ans,zd);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
