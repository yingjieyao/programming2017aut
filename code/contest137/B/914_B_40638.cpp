#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int f(int a,int b,int c,int d,double x)
{
    return a * x * x * x + b * x + c > d;
}
int main()
{
    int a,b,c,d;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF)
    {
        int mina,maxa;
        mina=a<b?a:b;
        mina=mina<c?mina:c;
        maxa=a>b?a:b;
        maxa=maxa>c?maxa:c;
        if(d<=maxa)
        {
            if(c>d)
            {
                if(!f(a,b,c,d,-1))
                {
                    printf("0\n");
                    continue;
                }
                else
                {
                    int tmp = -2;
                    while(f(a,b,c,d,tmp))
                    {
                        tmp--;
                    }
                    printf("%d\n",tmp+1);
                    continue;
                }
            }
            else
            {
                printf("1\n");
                continue;
            }
        }
        else
        {
            double le=0.0;
            double ri=2.0*d;
            double mid,ans;
            for(int i=0; i<50; i++)
            {
                mid = (le+ri)/2;
                if(!f(a,b,c,d,mid))
                {
                    le=mid;
                }
                if(f(a,b,c,d,mid))
                {
                    ans=mid;
                    ri=mid;
                }
            }

            int ansa;
        if(ans-floor(ans)!=0) ansa=floor(ans)+1;
        else ansa=floor(ans);
        printf("%d\n",ansa);

        }
    }

    return 0;
}
