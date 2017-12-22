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

int fa[SZ];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main()
{
    int T = read();
    while(T --)
    {
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++) fa[i] = i;
        for(int i = 1;i <= m;i ++)
        {
            int x = read(),y = read();
            x = find(x),y = find(y);
            fa[x] = y;
        }
        int ans = 0;
        for(int i = 1;i <= n;i ++) if(find(i) == i) ans ++;
        printf("%d\n",ans);
    }
    return 0;
}

