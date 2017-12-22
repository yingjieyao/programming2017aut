#include <stdio.h>
#include <stdlib.h>
long long din(long long a,long long b)
{
    long long tmp,t,c,d;
    c=a;
    d=b;
    if(a<=b)
    {
        tmp=b;
        b=a;
        a=tmp;
    }
    while(a%b!=0)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return c*d/b;
}
long long arr[1001];
int main()
{
    int t,n,i,j;
    long long min;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        min=1e9;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(din(arr[i],arr[j])<min)
                {
                    min=din(arr[i],arr[j]);
                }
            }
        }

        printf("%lld\n",min);
    }
}
