#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') {if(a == '-') flag = 1; a = getchar();}
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

LL a[SZ];

LL gcd(LL a,LL b)
{
    return b == 0 ? a : gcd(b,a % b);
}

int main()
{
    int T = read();
    while(T --)
    {
        int n = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        LL ans = 1e18 + 10;
        for(int i = 1;i <= n;i ++)
            for(int j = i + 1;j <= n;j ++)
                ans = min(ans,a[i] / gcd(a[i],a[j]) * a[j]);
        printf("%lld\n",ans);
    }
    return 0;
}
