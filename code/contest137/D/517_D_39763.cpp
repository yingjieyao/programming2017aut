#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

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

struct edge
{
    int f,t;
    LL d;
}l[SZ];

bool cmp(edge a,edge b) { return a.d < b.d; }

int fa[SZ],n,m;

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main()
{
    while(~scanf("%d%d",&n,&m) && n + m)
    {
        for(int i = 1;i <= n;i ++) fa[i] = i;
        for(int i = 1;i <= m;i ++)
        {
            l[i].f = read(),l[i].t = read(),l[i].d = read();
        }
        sort(l + 1,l + 1 + m,cmp);
        LL ans = 0;
        for(int i = 1;i <= m;i ++)
        {
            int x = find(l[i].f),y = find(l[i].t);
            if(x != y) fa[x] = y,ans += l[i].d;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


