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

int n,m,fa[MAXN],vis[MAXN];
char x[105][105];

int f(int a,int b){
    return (a-1)*m+b;
}

int get(int u){
    if (fa[u]==u) return u;
    fa[u]=get(fa[u]);
    return fa[u];
}

int work(int lim){
    for(int i=1;i<=n*m;i++) fa[i]=i,vis[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (x[i][j]=='#') continue;
            int c=f(i,j),d;
            for(int k=0;k<lim;k++){
                int aa=i+dx[k],bb=j+dy[k];
                if (aa<1 || aa>n || bb<1 || bb>m) continue;
                if (x[aa][bb]=='#') continue;
                d=f(aa,bb);
                if (get(c)==get(d)) continue;
                fa[get(c)]=get(d);
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        fa[i]=get(i);
    }
    int num=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if (x[i][j]=='#') continue;
            if (vis[fa[f(i,j)]]==1) continue;
            num++; vis[fa[f(i,j)]]=1;
        }
    return num;
}

int main(){
    int aa;  scanf("%d",&aa);
    while(aa--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf(" %s",x[i]+1);
        }
        int ans1=work(2);
        int ans2=work(4);
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
