#include <stdio.h>
#include <stdlib.h>

long long fuc(int a,int b)
{
    long long c=a,d=b;
    while(a!=0&&b!=0)
    {
        if(a>b) a-=b;
        else    b-=a;
    }
    if(a!=0) c=c*d/a;
    else     c=c*d/b;
    return c;
}
int cmp(const void *a,const void *b)
{
    return *((int*)a)-*((int*)b);
}

int main()
{
   int i,j,n,T;
   long long ans;
   int num[600];
   scanf("%d",&T);
   while(T--)
   {
       scanf("%d",&n);
       for(i=0;i<n;i++)
           scanf("%d",&num[i]);
           qsort(num,n,sizeof(num[0]),cmp);
           ans=fuc(num[0],num[1]);
       for(i=0;i<n;i++)
           for(j=i+1;j<n;j++)
               if(num[i]<=ans&&num[j]<=ans)
                   if(fuc(num[i],num[j])<ans)
                        ans=fuc(num[i],num[j]);
               printf("%lld\n",ans);
   }
    return 0;
}
