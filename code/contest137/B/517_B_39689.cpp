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
LL a,b,c,d;

LL f(LL x)
{
    return a * x * x * x + b * x;
}

LL Div(int l,int r)
{
    l --;
    while(r - l > 1)
    {
        LL mid = l + r >> 1;
        if(f(mid) > d - c) r = mid;
        else l = mid;
    }
    return r;
}


int main()
{
    while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&d))
    {
        LL ans = 0;
        if(d - c != 0)
        {
            ans = Div(-1010,1010);
        }
        else
        {
            ans = 1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
