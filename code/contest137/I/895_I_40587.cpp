#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
double a[105],ans[105];
int main()
{
    int t,T,i,n,num;
    double time;
    scanf ("%d",&T);
    t=0;
    while (T>t){
        scanf ("%d",&n);
        for (i=1;i<=n;i++) scanf ("%lf",&a[i]);
        num=n;
        time=0;
        memset(ans,0,sizeof(ans));
        while (1){
            for (i=1;i<=n;i++){
                if (a[i]==0) continue;
                if (a[i]<=1.0){
                    time+=a[i];
                    ans[i]=time;
                    a[i]=0;
                    time++;
                    num--;
                }
                else{a[i]--; time++;}
            }
            if (num==0) break;
        }
        printf ("Case %d:",++t);
        for (i=1;i<=n;i++)
            if (i==n) printf ("%.2lf\n",ans[i]);
            else printf ("%.2lf ",ans[i]);
    }
    return 0;
}
