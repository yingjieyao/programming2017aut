#include <stdio.h>
#include <stdlib.h>

long long sma(long long  p, long long q)
{
    long long u , v;
    long long m;
    if (p > q)
    {
        v = p;
        p = q;
        q = v;
    }
    v = q;
    u = p;
    while (u != 0)
    {
        m = u;
        u = v % u;
        v = m;
    }
    m = p * q / m;
    return m;
}

long long  min (long long p, long long q)
{
    return p < q ? p : q;
}


int main()
{
    int t;
    while ( scanf ("%d", &t) != EOF)
    {
        int i;
        for (i = 0; i < t; i++)
        {
            int n;
            long long  a[510];
            scanf ("%d", &n);
            int j, k;
            for (j = 0; j < n; j++)
            {
                scanf ("%lld", &a[j]);
            }
            long long  b = 1e15;
            for (j = 0; j < n; j ++)
            {
                for (k = j+1; k < n; k++)
                {
                    b = min (b, sma(a[j], a[k]));
                }
            }
            printf ("%lld\n", b);

        }

    }


    return 0;
}
