#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
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

int head[SZ],nxt[SZ],tot = 1;

struct edge
{
    int t;
    LL d;
}l[SZ];

void build(int f,int t,LL d)
{
    l[++ tot] = (edge){t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

LL dist[SZ];
bool use[SZ];
queue<int> q;

LL spfa(int s,int e)
{
    for(int i = 1;i <= n;i ++) dist[i] = INF;
    dist[s] = 0;
    q.push(s);
    use[s] = 1;
    while(q.size())
    {
        int u = q.front(); q.pop();
        use[u] = 0;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = l[i].t;
            if(dist[v] > dist[u] + l[i].d)
            {
                dist[v] = dist[u] + l[i].d;
                if(!use[v])
                    use[v] = 1,q.push(v);
            }
        }
    }
    return dist[e];
}

int main()
{
    int T = read(),cc = 0;
    while(T --)
    {
        tot = 1; for(int i = 1;i <= n;i ++) head[i] = 0;
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= m;i ++)
        {
            int x = read(),y = read();
            LL z = read();
            build(x,y,z + 1000000); build(y,x,z + 1000000);
        }
        int s = read(),e = read();
        LL ans = spfa(s,e);
        printf("Case #%d:\n",++ cc);
        if(ans == INF) puts("WTF?");
        else printf("%lld %lld\n",ans / 1000000,ans % 1000000);
    }
    return 0;
}



