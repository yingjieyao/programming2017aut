#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
long long mth(long long x, long long y)
{
    long long tm;
    tm = y - (y / x) * x;
    if(!tm) return x;
    mth(tm, x);
}
long long a[505];
int main()
{
    int n, i, j, t;
    scanf("%d", &t);
    while(t--)
    {
        long long tmp, ans = 1e9;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        //sort(a, a+n);
        for(i = 0; i < n; i++)
        {
            for(j = i + 1; j < n; j++)
            {
                long long m = mth(a[i], a[j]);
                tmp = a[i] * a[j] / m;
                //printf("%lld ", tmp);
                if(tmp < ans) ans = tmp;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
