#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
int get_max(int a,int b)
{
    return a>b?a:b;
}
int arr[501];
void quick_sort(int m,int n,int arr[])
{
    if(m>=n) return;
    int lef=m,rig=n,key=arr[m];
    while(lef<rig)
    {
        while(lef<rig && arr[rig]>key) rig--;
        if(lef<rig)
        {
            arr[lef]=arr[rig];
            lef++;
        }
        while(lef<rig && arr[lef]<key) lef++;
        if(lef<rig)
        {
            arr[rig]=arr[lef];
            rig--;
        }
    }
    arr[lef]=key;
    quick_sort(m,lef-1,arr);
    quick_sort(lef+1,n,arr);
    return;
}
long long a,b,c,d;
long long func(long long x)
{
    long long ans=a*x*x*x+b*x+c-d;
    return ans;
}
int main()
{
    long long val,lef,mid,rig,ans;
    while(scanf("%lld %lld %lld %lld",&a,&b,&c,&d)==4)
    {
        lef=-1e3,rig=1e3;
        while(lef<=rig)
        {
            mid=(lef+rig)/2;
            val=func(mid);
            if(val>0)
            {
                ans=mid;
                rig=mid-1;
            }
            else lef=mid+1;
            //printf("%I64d %I64d\n",lef,rig);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
