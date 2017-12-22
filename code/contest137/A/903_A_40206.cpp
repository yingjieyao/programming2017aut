#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long min( long long a, long long b)
{
    return a > b ? b : a;
}

int main()
{
    long long i, j, k, t, n, a[501], tmp, ans, r, x, y;
    scanf("%lld",&t);
    for ( i = 0; i < t; i++)
    {
        scanf("%lld",&n);
        memset(a,0,sizeof(a));
        for ( j = 0; j < n; j++) scanf("%lld",&a[j]);
        ans = 2000000000;
        for ( j = 0; j < n; j++)
        {
            for ( k = j + 1; k < n; k++)
            {
                x = a[j];
                y = a[k];
                while (x % y != 0)
                {
                    r = x % y;
                    x = y;
                    y = r;
                }
                tmp = a[j] * a[k] / y;
                ans = min(tmp,ans);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
