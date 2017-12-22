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
const int MAXM=1e6+5;
const int mod=1e5+5;
const int INF=1e9+7;
//const int dx[]={0,0,1,-1,1,1,-1,-1};
//const int dy[]={1,-1,0,0,1,-1,1,-1};
const int dx[]={1,0,-1,1};
const int dy[]={0,1,1,1};

int n,m,len,edge[MAXN+2*MAXM][3],in[MAXN],dp[MAXN],vis[MAXN];

void link(int a,int b,int c){
    len++; edge[len][0]=b; edge[len][1]=c; edge[len][2]=0;
    if (edge[a][0]==0) edge[a][2]=len;
    else edge[edge[a][0]][2]=len;
    edge[a][0]=len;
}

queue<int> q;
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        len=n;
        for(int i=1;i<=n;i++){
            edge[i][0]=edge[i][1]=edge[i][2]=in[i]=0;
            dp[i]=vis[i]=0;
        }
        for(int i=1;i<=m;i++){
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            link(a,b,c); in[b]++;
        }
        while(!q.empty()){
            q.pop();
        }
        for(int i=1;i<=n;i++){
            if (in[i]==0){
                q.push(i);
                vis[i]=1;
            }
        }
        int tag=1;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int i=edge[u][2];i!=0;i=edge[i][2]){
                int v=edge[i][0];
                if (vis[v]==1){
                    tag=0;
                    break;
                }
                in[v]--;
                if (in[v]==0){
                        q.push(v);
                        vis[v]=1;


                }
                dp[v]=max(dp[v],dp[u]+edge[i][1]);
            }
            if (tag==0) break;
        }
        if (tag==0){
                puts("NO SOLUTION");
            continue;
        }
        for(int i=1;i<=n;i++){
            if (vis[i]==0) tag=0;
        }
        if (tag==0){
                puts("NO SOLUTION");
            continue;
        }
        for(int i=1;i<=n;i++){
            printf("%d\n",dp[i]);
        }
    }
    return 0;
}
