#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <limits>
#include <limits.h>
#define INF 0x3f3f3f3f
using namespace std;
long long gcd(long long a,long long b)
{
    long long m = a,n = b,r;
    do
    {
        r = m % n;
        m = n;
        n = r;
    }
    while (r);
    return m;
}
long long my_min(long long a,long long b)
{
    return a <= b ? a : b;
}
int main()
{
    int n,T;
    long a[501];
    scanf("%d",&T);
    while (T--)
    {
        long long minn = INT_MAX;
        scanf("%d",&n);
        for (int i = 1; i <= n; i++)
            scanf("%lld",&a[i]);
        for (int i = 1;i < n;i++)
            for (int j = i + 1;j <= n;j++)
                minn = my_min(minn,a[i] / gcd(a[i],a[j]) * a[j]);
        printf("%lld\n",minn);
    }
    return 0;
}
