#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define nn 1005
#define inf 1000000000
using namespace std;
typedef long long ll;
int n,m,T,e,s,a,b,c;
struct nod{int end,next,s;
}g[nn*10*2];
int tot,x,w,fa[nn],dis[nn],D[nn];
queue<int>q;
bool v[nn];
 
void add(int a,int b,int c){
     g[++tot]=(nod){b,fa[a],c};fa[a]=tot;
     }
void spfa(int s){
     for (int i=1;i<=n;i++)dis[i]=inf,D[i]=inf;
     memset(v,false,sizeof(v));
     while (!q.empty())q.pop();
     
     q.push(s);
     v[s]=1;dis[s]=0;D[s]=0;
     while (!q.empty()){
           x=q.front();q.pop();
           for (int i=fa[x];i;i=g[i].next){
               int u=g[i].end;
               if ((dis[u]>dis[x]+1)||((dis[u]==dis[x]+1)&&(D[u]>D[x]+g[i].s))){
                  dis[u]=dis[x]+1;D[u]=D[x]+g[i].s;
                  if (!v[u]){
                     v[u]=1;q.push(u);
                     }
                  }
               }
           v[x]=0;
           }
     }
int main(){
    scanf("%d",&T);int id=0;
    while (T--){
    memset(fa,0,sizeof(fa));
    tot=0;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
    scanf("%d%d%d",&a,&b,&c);
    add(a,b,c);add(b,a,c);  
    }scanf("%d%d",&s,&e);
    spfa(s);
    if (dis[e]==inf)printf("Case #%d:\nWTF?\n",++id);
    else printf("Case #%d:\n%d %d\n",++id,dis[e],D[e]);
    }
    return 0;
}
