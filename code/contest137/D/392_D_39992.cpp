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

struct Node{
    Node(){}
    Node(int l_,int r_,int dis_):l(l_),r(r_),dis(dis_){}
    int l,r,dis;
    bool operator < (const Node &a) const{
        return dis<a.dis;
    }
}x[MAXN];

int n,m,fa[MAXN];

int get(int u){
    if (fa[u]==u) return u;
    fa[u]=get(fa[u]);
    return fa[u];
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if (n==0 && m==0) break;
        for(int i=1;i<=m;i++){
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            x[i]=Node(a,b,c);
        }
        sort(x+1,x+m+1);
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            int a=get(x[i].l),b=get(x[i].r);
            if (a==b) continue;
            fa[a]=b; ans+=x[i].dis;
        }
        printf("%d\n",ans);
    }
    return 0;
}
