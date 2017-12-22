#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
long long a[550];
long long mi[250000];
long long  be(long long a, long long  b)
{
    long long  c;
    if(a < b)
    {
        c = a;
        a = b;
        b = c;
    }
    c = a % b;
    while(a%b != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

long long  bei(long long  a, long long  b, long long x)
{
    return a * b / x;
}

int main()
{
    int t3;
    scanf("%d", &t3);
    for(int t1 = 0; t1 < t3; t1++)
    {
        memset(mi, 0 ,sizeof(mi));
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
        int t = 0;
        for(int i = 0; i < n - 1; i++)
            for(int j = i + 1; j < n; j++)
        {
            long long m = be(a[i], a[j]);
            mi[t++] = bei(a[i], a[j], m);
        }
        sort(mi, mi + t);
        printf("%lld\n", mi[0]);
    }
    return 0;
}
