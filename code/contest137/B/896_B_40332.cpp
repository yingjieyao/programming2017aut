#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long a,b,c,d,x,right,left,mid,ans,tp;
    while((scanf("%lld %lld %lld %lld",&a,&b,&c,&d))!=EOF)
    {
        right=1000;
        left=-1000;
        while(right>left&&right>left+1)
        {
            mid=(right+left)/2;
            if(a*mid*mid*mid+b*mid+c>d)
                right=mid;
            else
                left=mid;
        }
            tp=mid;
        if(a*tp*tp*tp+b*tp+c>d)
            ans=tp;
        else
            ans=tp+1;
        printf("%lld\n",ans);
    }
    return 0;
}
