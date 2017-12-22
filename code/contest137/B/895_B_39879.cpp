#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long a,b,c,d,e;
long long erfen(long long l,long long r){
    long long mid,tmp;
    while (r-l>1){
        mid=(l+r)/2;
        tmp=a*mid*mid*mid+b*mid;
        if (tmp<=e) l=mid;
        else r=mid;
    }
    return r;
}
int main()
{
    long long ans;
    while (scanf ("%lld %lld %lld %lld",&a,&b,&c,&d)!=EOF){
        e=d-c;
        if (e>0){
            ans=erfen(0,1000);
        }
        else if (e==0) ans=1;
        else if (e<0){
            ans=erfen(-1000,0);
        }
        printf ("%lld\n",ans);
    }
    return 0;
}
