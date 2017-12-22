#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<queue>
using namespace std;

long long a,b,c,d;

bool check(long long x)
{
    long long temp=a*x*x*x+b*x+c;
    if (temp>d)
        return true;
    else
        return false;
}

int main()
{
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&d)!=EOF)
    {
        if (check(0))
        {
            long long r=0,l=-(sqrt((c-d)/a)+5);
            while (l+1<r)
            {
                long long mid=(l+r)/2;
                if (check(mid))
                    r=mid;
                else
                    l=mid+1;
                //printf("%d %d %d\n",l,r,mid);
            }
            if (check(l))
                printf("%d\n",l);
            else
                printf("%d\n",r);
        }
        else
        {
            long long r=(sqrt(d/a)+5),l=0;
            while (l<r)
            {
                long long mid=(l+r)/2;
                if (check(mid))
                    r=mid;
                else
                    l=mid+1;
                //printf("%d %d %d\n",l,r,mid);
            }
            if (check(l))
                printf("%d\n",l);
            else
                printf("%d\n",r);
        }
    }
    return 0;
}
