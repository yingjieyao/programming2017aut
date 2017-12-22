#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int Ni = 100010;
const int INF = 2000000000;
struct node{
    int x,d,w;
    node(){}
    node(int a,int b,int c){x=a;d=b;w=c;}
    bool operator < (const node & a) const
    {
        if(d==a.d) return x<a.x;
        else return d > a.d;
    }
};
vector<node> eg[Ni];
int dis[Ni],dis2[Ni],n,m,t;
void Dijkstra(int s)
{
    int i;
    for(i=0;i<=n;i++) dis[i]=dis2[i]=INF;
    dis[s]=0;
    dis2[s]=0;
    priority_queue<node> q;
    q.push(node(s,dis[s],dis2[s]));
    while(!q.empty())
    {
        node x=q.top();q.pop();
        for(i=0;i<eg[x.x].size();i++)
        {
            node y=eg[x.x][i];
            if(dis[y.x]>x.d+y.d)
            {
                dis[y.x]=x.d+y.d;
                dis2[y.x]=x.w+y.w;
                q.push(node(y.x,dis[y.x],dis2[y.x]));
            }
            else if (dis[y.x]==x.d+y.d)
            {
                if (dis2[y.x]>x.w+y.w)
                {
                    dis2[y.x]=x.w+y.w;
                    q.push(node(y.x,dis[y.x],dis2[y.x]));
                }
            }
        }
    }
}
int main()
{
    scanf("%d",&t);
    int tt=0;
    while(t--)
    {
        for(int i=0;i<=n;i++)
            eg[i].clear();
        tt++;
        printf("Case #%d:\n",tt);
        scanf("%d%d",&n,&m);
        while(m--)
        {
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            eg[a].push_back(node(b,1,d));
            eg[b].push_back(node(a,1,d));
        }
        int s,e;
        scanf("%d%d",&s,&e);
        Dijkstra(s);
        if (dis[e]!=INF)
            printf("%d %d\n",dis[e],dis2[e]);
        else
            puts("WTF?");
    }
    return 0;
}
