#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[520];
double b,key;
int c;
int findg(int a,int b)
{
    if(a>b)
    {
        c=a%b;
        if(c==0)return b;
        else findg(b,c);
    }
    else {c=b%a;
    if(c==0)return a;
    else findg(a,c);}
}
int main()
{
    int num;
    int n,i,j;
scanf("%d",&num);
    while(num--)
    {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        key= a[0]/findg(a[0],a[1]);
        key=(double)a[1]*key;
        for(i=0; i<n-1&&(double)a[i]<key+0.4; i++)
        {
            for(j=i+1; j<n&&(double)a[j]<key+0.4; j++)
            {
                b=a[i]/findg(a[i],a[j]);
                b=(double)a[j]*b;
                if(b<key)key=b;
            }
            }
        printf("%.0lf\n",key+0.4);
    }
    return 0;
}
