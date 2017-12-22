#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long a[1000];
long long s[300000];
int cmp(const void *a,const void *b)
{
    return *(long long *)a - *(long long *)b;
}
long long max(long long a,long long b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    int t,l;
    scanf("%d",&t);
    for(l=0;l<t;++l)
    {
        memset(s,0,sizeof(s));
        int i,j,k;
        int n;
        long long min=10000000000,tmp;
        long long st=0;
        scanf("%d",&n);
        for(i=0; i<n; ++i)
            scanf("%lld",&a[i]);
        for(i=0; i<n; ++i)
        {
            for(j=i+1; j<n; ++j)
            {
                long long a1=max(a[i],a[j]),a2=a[i]+a[j]-a1,yu;
                while(1)
                {
                    yu=a1%a2;
                    if(yu==0)
                    {
                        tmp=a[i]*(a[j]/a2);
                        break;
                    }
                    a1=a2;
                    a2=yu;
                }
                if(tmp<min) min=tmp;
            }
        }
        printf("%lld\n",min);
    }
    return 0;
}
