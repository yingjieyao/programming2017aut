#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
double ta[110];
double t[110];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE 
    int T;
    scanf("%d", &T);
    for(int t1 = 1; t1 <= T; t1++)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%lf", &ta[i]);
        double cpu = 0.0;
        memset(t, 0, sizeof(t));
        while(1)
        {
        for(int i = 0; i < n; i++)
        {
            if(ta[i] > 1e-9)
            {
                if(ta[i] - 1 < 1e-9)
                {
                    cpu += ta[i] + 1.0;
                    ta[i] = 0.0;
                    t[i]= cpu - 1.0;
                }
                else
                {
                    ta[i] -= 1.0;
                    cpu += 1.0;
                }
            }
        }
        int k = 0;
        for(int i = 0; i < n; i++)
        {
            if(ta[i] > 1e-9) k = 1;
        }
        if(k == 0) break;
        }
        printf("Case %d:", t1);
        for(int i = 0; i < n; i++) printf("%.2lf ", t[i]);
        printf("\n");
    }
    return 0;
}
