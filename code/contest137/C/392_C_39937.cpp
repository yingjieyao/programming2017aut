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
const int INF=1e5+5;
const int mod=1e5+5;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

int n,m,fa[MAXN],vis[MAXN];

int get(int u){
    if (fa[u]==u) return u;
    fa[u]=get(fa[u]);
    return fa[u];
}

int main(){
    int aa; scanf("%d",&aa);
    while(aa--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1;i<=m;i++){
            int a,b; scanf("%d%d",&a,&b);
            fa[get(a)]=get(b);
        }
        for(int i=1;i<=n;i++) get(i);
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=1;i<=n;i++){
            if (vis[fa[i]]==0){
                vis[fa[i]]=1;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
