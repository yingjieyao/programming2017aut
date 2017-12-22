#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int m,n,i,j,t,ii,z;
double a[1000],b[1000];
double tm;

int main()
{
    //freopen("testin.txt","r",stdin);
    //freopen("myout.txt","w",stdout);
    scanf("%d",&t);
    for(ii=0;ii<t;ii++)
    {
        scanf("%d",&n);memset(a,0,sizeof(a));memset(b,0,sizeof(b));
        for(i=1;i<=n;i++)scanf("%lf",&a[i]);
        z=n;tm=0.0;
        while(z)
        {
            for(i=1;i<=n;i++)
            {
                if(a[i]==0)continue;
                if(a[i]>1){a[i]=a[i]-1.0;tm=tm+1.0;}
                else {z--;tm=tm+1.0+a[i];a[i]=0;b[i]=tm-1.0;}
            }
        }
        printf("Case %d:",ii+1);
        for(i=1;i<=n;i++)printf("%.2lf ",b[i]);
        printf("\n");
    }


    return 0;
}
