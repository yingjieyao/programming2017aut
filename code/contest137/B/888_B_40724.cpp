#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
ll a,b,c,d;
int check(ll mid)
{
    /*if(mid==0)
    {
        if(c>d)
            return 1;
        else
            return 0;
    }
    if(2000000000000000000LL/mid/mid/mid<a)
    {
        return 1;
    }*/
    if(a*mid*mid*mid+b*mid+c>d)
        return 1;
    else
        return 0;
}
void erfen()
{
    ll left,right;
    left=-1000LL,right=1000LL;
    while(left+1<right)
    {
        ll mid=((left+right)>>1);
        if(check(mid)==1)
        {
            right=mid;
        }
        else if(check(mid)==0)
        {
            left=mid;
        }
    }
    if(check(left)==1)
        printf("%lld\n",left);
    else
        printf("%lld\n",right);
}
int main()
{
    while(scanf("%lld %lld %lld %lld",&a,&b,&c,&d)==4)
    {
        erfen();
    }
    return 0;
}
