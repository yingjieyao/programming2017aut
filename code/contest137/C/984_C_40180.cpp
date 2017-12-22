#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

const int Maxn=100010;
vector <int> igraph[Maxn];
int dfn[Maxn],low[Maxn],Index,cnt;
bool isg[Maxn];
int n,m,t;

void iTarjan(int now)
{
    dfn[now]=low[now]=++Index;
    int limit=igraph[now].size()-1;
    int size=0;
    for (int i=0;i<=limit;i++)
    {
        int v=igraph[now][i];
        if (!dfn[v])
        {
            size++;
            iTarjan(v);
            low[now]=min(low[now],low[v]);
        }
        else
        {
            low[now]=min(low[now],dfn[v]);
        }
    }

    if (low[now]==dfn[now])
        ++cnt;
}

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        Index=0;
        cnt=0;
        for (int i=1;i<=n;i++)
            igraph[i].clear();
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            igraph[x].push_back(y);
            igraph[y].push_back(x);
        }
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                iTarjan(i);
        printf("%d\n",cnt);
    }
    return 0;
}
