#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long minx(long long a, long long b)
{
    if(a > b)
        return b;
    else
        return a;
}
long long mmp(long long x, long long y)
{
    if(y == 0)
    {
        return x;
    }
    return mmp(y, x%y);
}

int main()
{
    long long b[505][505],xa,xb,a[505];
    long long n,i,j,k,geshu;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        long long ans=0;
        scanf("%d",&geshu);
        for(j = 0; j<geshu; j++)
        {
            scanf("%d", &a[j]);
        }
        for(j = 0; j <geshu; j++)
        {
            for(k = j + 1; k < geshu; k++)
            {
                xa = a[j];
                xb = a[k];
                xa = mmp(xa, xb);
                b[j][k] = a[j] * a[k]/xa;
            }
        }
        ans = b[0][1];
        for(j = 0; j < geshu; j++)
        {
            for(k = j + 1; k < geshu; k++)
            {
                ans = minx(ans,b[j][k]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
