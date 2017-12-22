#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int a[501];

int gcd(int x,int y)
{
    if(!y) return x;
    return gcd(y,x%y);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        long long ans=2147483649999999999;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
            {
                if(a[i]==a[j]) ans=a[i];
                else ans=min(ans,1LL*a[i]/gcd(a[j],a[i])*a[j]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
