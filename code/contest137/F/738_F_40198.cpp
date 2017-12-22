#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define nn 1050
using namespace std;
struct nod{int end,next,s;
}g[nn*2];
int x,n,a,b,tem,c,m,ans[nn],in[nn],tot,fa[nn];
queue<int>q;
void add(int a,int b,int c){
     g[++tot]=(nod){b,fa[a],c};fa[a]=tot;
     }
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
    tot=0;
    memset(ans,0,sizeof(ans));
    memset(fa,0,sizeof(fa));
    memset(in,0,sizeof(in));
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
          add(a,b,c);in[b]++;
          }
    tem=0;
    for (int i=1;i<=n;i++)if (!in[i])q.push(i);
    while  (!q.empty()){
           tem++;
           x=q.front();q.pop();
           for (int i=fa[x];i;i=g[i].next){
           int u=g[i].end;
           ans[u]=max(ans[x]+g[i].s,ans[u]);
           in[u]--;if (in[u]==0)q.push(u);
           }
           }
    if (tem==n)
    for (int i=1;i<=n;i++)printf("%d\n",ans[i]);
    else puts("NO SOLUTION");
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
