#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int m,n,i,j;
long long a,b,c,d,x;

int main()
{
    //freopen("testin.txt","r",stdin);
    //freopen("myout.txt","w",stdout);
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&d)!=EOF)
    {
        x=-100;
        while((a*x*x*x+b*x+c)<=d)x++;
        printf("%lld\n",x);
    }


    return 0;
}
