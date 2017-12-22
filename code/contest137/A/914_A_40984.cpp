#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

long long f(long long a,long long b)
{
    long long tmp;
    long long ans=a*b;
    while(b%a!=0)
    {
        tmp=b;
        b=a;
        a=tmp%a;
    }
    return ans/a;
}


int main()
{
    long long a[505];
    long long b[125005];
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        int cnt=0;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
                b[cnt++]=f(a[i],a[j]);
        }

        long long mina=b[0];
        for(int i=0; i<cnt; i++)
            mina=mina<b[i]?mina:b[i];

        printf("%lld\n",mina);
    }

    return 0;
}
