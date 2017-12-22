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
queue<int> q;
/*
bool use[SZ];
int t[SZ];
bool spfa(int s)
{
    for(int i = 1;i <= n + 1;i ++) dist[i] = -1,t[i] = 0,use[i] = 0;
    while(q.size()) q.pop();
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
            if(dist[v] < dist[u] + l[i].d)
            {
                dist[v] = dist[u] + l[i].d;
                if(!use[v])
                {
                    use[v] = 1,q.push(v);
                    if(++ t[v] >= n) return false;
                }
            }
        }
    }
    return true;
}
*/

int rd[SZ];

bool toposort(int s)
{
    q.push(s);
    for(int i = 1;i <= n + 1;i ++) dist[i] = 0;
    dist[s] = 0;
    int t = 0;
    while(q.size())
    {
        int u = q.front(); q.pop();
        t ++;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = l[i].t;
            dist[v] = max(dist[v],dist[u] + l[i].d);
            if(-- rd[v] == 0) q.push(v);
        }
    }
    if(t != n + 1) return false;
    return true;
}


int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        tot = 1; for(int i = 1;i <= n + 1;i ++) rd[i] = head[i] = 0;

        for(int i = 1;i <= m;i ++)
        {
            int x = read(),y = read();
            LL z = read();
            build(x,y,z);
            rd[y] ++;
        }
        int s = n + 1;
        for(int i = 1;i <= n;i ++) build(s,i,0),rd[i] ++;
        if(!toposort(s)) puts("NO SOLUTION");
        else
        {
            for(int i = 1;i <= n;i ++)
                printf("%lld\n",dist[i]);
        }
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



