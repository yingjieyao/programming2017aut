#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int m,n,i,j,ii,t;
long long a[5000];
long long as,gs;

long long gys(long long k1,long long k2)
{
    if(k1>k2)swap(k1,k2);
    while(k1!=0)
    {
        k2=k2%k1;
        swap(k1,k2);
    }
    return k2;
}


int main()
{
    //freopen("testin.txt","r",stdin);
    //freopen("myout.txt","w",stdout);
    scanf("%d",&t);
    for(ii=0;ii<t;ii++)
    {
        scanf("%d",&n);
        as=9999999999;
        for(i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(i=2;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                gs=gys(a[i],a[j]);
                as=min(as,a[i]*a[j]/gs);
            }
        }
        printf("%lld\n",as);
    }


    return 0;
}
