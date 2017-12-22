#include <stdio.h>
#include <stdlib.h>

long long f(long long m,long long n)
{
    long long x,y;
    x=m;
    y=n;
    while(x!=y)
    {
        if(x>y)
        {
            x=x-y;
        }
        else
        {
            y=y-x;
        }
    }
    x=m*n/x;
    return x;
}
int main()
{
    int t,i,n,j,k;
    long long b,c;
    long long a[500];
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d",&n);
        for(j=0; j<n; j++)
        {
            scanf("%lld",&a[j]);
        }
        b=a[0]*a[1];
        for(j=0; j<n-1; j++)
        {
            for(k=j+1; k<n; k++)
            {
                c=f(a[j],a[k]);
                if(b>c)
                {
                    b=c;
                }
            }
        }
        printf("%lld\n",b);
    }
    return 0;
}