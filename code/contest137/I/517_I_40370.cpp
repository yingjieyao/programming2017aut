#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const int dx[] = {1,0,-1,0,1,1,-1,-1};
const int dy[] = {0,1,0,-1,-1,1,1,-1};
const double eps = 1e-8;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') {if(a == '-') flag = 1; a = getchar();}
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,m;
double ans[SZ],a[SZ];

int main()
{
    int T = read(),cc = 0;
    while(T --)
    {
        n = read();
        for(int i = 1;i <= n;i ++)
            scanf("%lf",&a[i]),ans[i] = 0;
        double now = 0;
        int p = 1;
        while(233)
        {
            bool flag = 0;
            for(int i = 1;i <= n;i ++)
                if(a[i] > eps) { flag = 1; break; }
            if(!flag) break;
            if(p == n + 1) p = 1;
            while(a[p] <= eps) { p ++; if(p == n + 1) p = 1; }
            if(a[p] <= 1.0) now += a[p],ans[p] = now,a[p] = 0,now += 1;
            else now += 1,a[p] -= 1;
           // for(int i = 1;i <= n;i ++)
           //     printf("%.2f ",a[i]); puts("");
            p ++;
        }
        printf("Case %d:",++ cc);
        for(int i = 1;i <= n;i ++)
            printf("%.2f%c",ans[i],i == n ? '\n' : ' ');
    }
    return 0;
}





