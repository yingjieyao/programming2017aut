#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;

typedef long long LL;
const int MAXN=1e5+5;
const int MAXM=1e5+5;
const int mod=1e5+5;
const int INF=1000000000;
//const int dx[]={0,0,1,-1,1,1,-1,-1};
//const int dy[]={1,-1,0,0,1,-1,1,-1};
const int dx[]={1,0,-1,1};
const int dy[]={0,1,1,1};

struct Node{
    Node(){}
    Node(int l_,int r_,int dis_):l(l_),r(r_),dis(dis_){}
    int l,r,dis;
    bool operator < (const Node &a) const{
        return dis<a.dis;
    }
};

int n,m,len;
int edge[MAXN+2*MAXM][3];

void link(int a,int b,int c){
    len++; edge[len][0]=b; edge[len][1]=c;
    if (edge[a][0]==0) edge[a][2]=len;
    else edge[edge[a][0]][2]=len;
    edge[a][0]=len;
}

queue<int>q;
int dis[MAXN][2],vis[MAXN];
void SPFA(int s){
    for(int i=1;i<=n;i++){
        dis[i][0]=dis[i][1]=INF;
        vis[i]=0;
    }
    dis[s][0]=dis[s][1]=0; q.push(s);
    while(!q.empty()){
        int u=q.front(); q.pop(); vis[u]=0;
        for(int i=edge[u][2];i!=0;i=edge[i][2]){
            int v=edge[i][0];
            if ((dis[v][0]>dis[u][0]+1) || (dis[v][0]==dis[u][0]+1 && dis[v][1]>dis[u][1]+edge[i][1])){
                if (dis[v][0]>dis[u][0]+1){
                    dis[v][0]=dis[u][0]+1;
                }
                dis[v][1]=dis[u][1]+edge[i][1];
                if (vis[v]==0){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}

int main(){
    int aa,cas=0;  scanf("%d",&aa);
    while(aa--){
        scanf("%d%d",&n,&m); len=n;
        memset(edge,0,sizeof(edge));
        for(int i=1;i<=m;i++){
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            link(a,b,c); link(b,a,c);
        }
        int s,t; scanf("%d%d",&s,&t);
        SPFA(s);
        printf("Case #%d:\n",++cas);
        if (dis[t][0]==INF) puts("WTF?");
        else printf("%d %d\n",dis[t][0],dis[t][1]);
    }
    return 0;
}
