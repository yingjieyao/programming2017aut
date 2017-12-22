#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const int dx[] = {1,0,-1,0,1,1,-1,-1};
const int dy[] = {0,1,0,-1,-1,1,1,-1};

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

struct pie
{
    int pos,t,w;
}l[SZ];

bool cmp(pie a,pie b) { if(a.t != b.t) return a.t < b.t; return a.pos < b.pos; }

int f[100010][25];

int main()
{
    while(~scanf("%d",&n) && n)
    {
        for(int i = 0;i <= 100000;i ++)
            for(int j = 0;j <= 22;j ++)
                f[i][j] = 0;
        for(int i = 1;i <= n;i ++)
        {
            l[i].pos = read() + 1,l[i].t = read(),l[i].w = read();
            f[l[i].t][l[i].pos] += l[i].w;
        }
        for(int j = 0;j <= 22;j ++) f[0][j] = -INF;
        for(int i = 0;i <= 100000;i ++) f[i][0] = f[i][22] = -INF;
        f[0][11] = 0;
        for(int i = 1;i <= 100000;i ++)
            for(int j = 1;j <= 21;j ++)
            {
                f[i][j] += max(max(f[i - 1][j - 1],f[i - 1][j + 1]),f[i - 1][j]);
            }
        int ans = 0;
      /*  for(int i = 1;i <= m;i ++,puts(""))
            for(int j = 1;j <= 21;j ++)
                printf("%3d",f[i][j] <= 0 ? -1 : f[i][j]);*/
        for(int i = 1;i <= 21;i ++) ans = max(ans,f[100000][i]);
        printf("%d\n",ans);
    }
    return 0;
}
/*

5 6
1 2 0
1 5 1
2 5 1
3 1 5
4 1 4
4 3 1
5 5
1 2 3
1 5 1
2 5 1
5 1 5
4 1 4

*/




