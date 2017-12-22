#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long zzxc(long long x,long long y)
{
    if(y==0)
        return x;
    return zzxc(y,x%y);
}
int main()
{
    int T,N,i,p,q,k;
    long long gbs[500][500],ans,arr[500];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        memset(arr,0,sizeof(arr));
        memset(gbs,0,sizeof(gbs));
        ans=0;
        scanf("%d",&N);
        for(k=0;k<N;k++)
            scanf("%d",&arr[k]);
        for(p=0;p<N-1;p++)
        {
            for(q=p+1;q<N;q++)
                gbs[p][q]=arr[p]*arr[q]/zzxc(arr[p],arr[q]);
        }
        ans=gbs[0][1];
        for(p=0;p<N;p++)
        {
            for(q=p+1;q<N;q++)
            {
                if(ans>gbs[p][q])
                    ans=gbs[p][q];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
