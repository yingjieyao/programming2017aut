#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int N,T;
long long int a[510];
long long int minn(long long int a,long long int b)
{
    return a<b?a:b;
}
long long int gbs(int x,int y)
{
    long long int sum,temp_1,temp_2=x,temp_3=y;
   if(y%x==0) return y;
   else
   {
       while(y%x!=0)
       {
           temp_1=(y%x);
           y=x;
           x=temp_1;
       }
       return temp_2*temp_3/x;
   }
}
int main()
{
    int i,j;
    long long int temp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(i=1;i<=N;i++)
            scanf("%lld",&a[i]);
        sort(a+1,a+N+1);
        temp=gbs(a[1],a[2]);
        for(i=1;i<=N;i++)
            {for(j=i+1;j<=N;j++)
        {
            temp=minn(temp,gbs(a[i],a[j]));
        }
        }
        printf("%lld\n",temp);
    }
    return 0;
}