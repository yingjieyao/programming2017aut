#include <stdio.h>
#include <stdlib.h>
float arr[200],brr[200];
int main()
{
    int t,p,i,j,n,s;
    float m;
    scanf("%d",&t);
    for(p=0;p<t;p++)
    {
        s=0;
        m=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%f",&arr[i]);
        i=0;
        while(s!=n)
        {
            if(i==n) i=0;
            if(arr[i]==0) 1;
            else if(arr[i]<=1)
            {
                s=s+1;
                brr[i]=m+arr[i];
                m=m+1+arr[i];
                arr[i]=0;
            }
            else
            {
                arr[i]=arr[i]-1;
                m=m+1;
            }
            i++;
        }
        printf("Case %d:",p+1);
        for(i=0;i<n-1;i++)
            printf("%.2f ",brr[i]);
        printf("%.2f\n",brr[n-1]);
    }
    return 0;
}
