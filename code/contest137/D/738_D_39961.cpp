#include<cstdio>
#include<cstring>
#define nn 1050
#define inf 1000000000
using namespace std;
struct nod{int end,next,s;
}g[400005];
int T,minn,m,ans,a,b,c,fa[nn],tot,n,p,j,dis[nn];
bool vis[nn];
void add(int a,int b,int c){
     g[++tot]=(nod){b,fa[a],c};fa[a]=tot;
     }
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
    if ((!n)&&(!m))break;
    tot=0;
    memset(fa,0,sizeof(fa));
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);add(b,a,c);
        }
    memset(dis,60,sizeof(dis));
    memset(vis,false,sizeof(vis));
	dis[1]=0;ans=0;
	for(int tt=1; tt<=n; tt++){
		minn=inf; p=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&dis[i]<minn){minn=dis[i];p=i;}
		}
		vis[p]=true; ans+=dis[p];
		for(j=fa[p];j;j=g[j].next){
		if(dis[g[j].end]>g[j].s)dis[g[j].end]=g[j].s;
		}
    }
    printf("%d\n",ans);
    }
 return 0;
}
