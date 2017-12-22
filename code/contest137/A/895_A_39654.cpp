#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long a[505];
long long gcd(long long x,long long y){
    if (x%y==0) return y;
    else return gcd(y,x%y);
}
int main()
{
    int T,i,j,n,flag,pos;
    long long tmp,minn;
    scanf ("%d",&T);
    while (T>0){
        flag=0;
        minn=1000000000000000001;
        scanf ("%d",&n);
        for (i=1;i<=n;i++){
            scanf ("%lld",&a[i]);
            if (a[i]==1){flag=1; pos=i;}
        }
        if (flag==1){
            for (i=1;i<=n;i++){
                if (i==pos) continue;
                if (a[i]<minn) minn=a[i];
            }
            printf ("%lld\n",minn);
        }
        else{
            for (i=1;i<=n;i++){
                for (j=i+1;j<=n;j++){
                    tmp=gcd(a[i],a[j]);
                    tmp=a[i]/tmp*a[j];
                    if (tmp<minn) minn=tmp;
                }
            }
            printf ("%lld\n",minn);
        }
        T--;
    }
    return 0;
}
