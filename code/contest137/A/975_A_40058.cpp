#include <stdio.h>
#include <stdlib.h>
long long arr[10000];
long long gbs(long long a,long long b)
{
    long long ans;
    long long c=a,d=b;
    while(a!=0&&b!=0)
    {
        if(a>b)
            a=a%b;
        else b=b%a;
    }
    if(a==0)
        return ans=c*d/b;
    else return ans=c*d/a;
}
int main()
{
    long long n,m,i,j,p;
    long long a,ans;
    scanf("%lld",&m);
    for(p=0;p<m;p++)
    {
         ans=0;
         scanf("%lld",&n);
         for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
         for(i=0;i<n;i++)
         {
             for(j=i+1;j<n;j++)
             {
                 a=gbs(arr[i],arr[j]);
                 if(ans==0) ans=a;
                 if(a<ans)
                    ans=a;
             }
         }
         printf("%lld\n",ans);
    }
    return 0;
}
