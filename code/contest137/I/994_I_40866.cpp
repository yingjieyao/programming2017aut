#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
int main()
{
    int x,q,i,n,count;
    double arr[101],brr[101],time;
    scanf("%d",&q);
    for(x=1;x<=q;++x)
    {
        scanf("%d",&n);
        for(i=0;i<n;++i) scanf("%lf",&arr[i]);
        count=0;
        time=0;
        while(count<n)
        {
            for(i=0;i<n;++i)
            {
                if(arr[i]>0)
                {
                    if(arr[i]>1)
                    {
                        arr[i]-=1;
                        time+=1;
                    }
                    else
                    {
                        count++;
                        brr[i]=time+arr[i];
                        time=1+brr[i];
                        arr[i]=0;
                        if(count==n) time-=1;
                    }
                }
            }
        }
        printf("Case %d:",x);
        for(i=0;i<n;++i) printf("%.2lf ",brr[i]);
        printf("\n");
    }
    return 0;
}
