#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T,cas = 1;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        double t[101],ans[101];
        scanf("%d",&n);
        int cou = n;
        memset(t,0,sizeof(t));
        memset(ans,0,sizeof(ans));
        for (int i = 1;i <= n;i++)
            scanf("%lf",&t[i]);
        if (n == 1)
        {
            printf("Case %d:%.2f\n",cas,t[1]);
        }
        else
        {
            double tmp = 0;
            while (cou)
            {
                for (int i = 1;i <= n;i++)
                {
                    if (t[i] > 1)
                    {
                        tmp += 1;
                        t[i] -= 1;
                        ans[i] = tmp;
                    }
                    else if (t[i] <= 1 && t[i])
                    {
                        tmp += t[i];
                        t[i] = 0;
                        ans[i] = tmp;
                        tmp += 1;
                        cou--;
                    }
                }
            }
            printf("Case %d:",cas);
            for (int i = 1;i < n;i++)
                printf("%.2f ",ans[i]);
            printf("%.2f\n",ans[n]);
        }
        cas++;
    }
    return 0;
}
