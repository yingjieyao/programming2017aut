#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<queue>
using namespace std;

const int Maxn=510;
int arr[Maxn];
int t,n;
long long ans=-1;

int gcd(int x,int y)
{
    if (y==0)
        return x;
    else
        return gcd(y,x%y);
}

long long calc(int x,int y)
{
    return ((long long)x)*y/gcd(x,y);
}

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        ans=-1;
        for (int i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        for (int i=1;i<=n;i++)
            for (int j=1;j<i;j++)
            {
                    long long temp=calc(arr[i],arr[j]);
                    if (ans==-1 || ans>temp)
                        ans=temp;
            }
        printf("%lld\n",ans);
    }
}
