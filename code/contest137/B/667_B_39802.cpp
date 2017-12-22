#include<cstdio>
    long long a,b,c,d;
    long long x;

int check(long long k)
{
    long long tmp=(k*k*k*a+b*k+c);
    if (tmp>d) return 1; return 0;
}

int main()
{

    while (scanf("%lld %lld %lld %lld",&a,&b,&c,&d)>-1)
    {
        long long l=-1100;
        long long r=1100;
        long long mid=0;

        while (l<r-1)
        {
            mid=(l+r)/2;
            if (check(mid)) r=mid; else l=mid;
        }
        if (check(mid)) printf("%lld\n",mid); else printf("%lld\n",r);
    }
    return 0;
}
