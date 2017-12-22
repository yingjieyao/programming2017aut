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
const int INF=1000000000;
//const int dx[]={0,0,1,-1,1,1,-1,-1};
//const int dy[]={1,-1,0,0,1,-1,1,-1};
const int dx[]={1,0,-1,1};
const int dy[]={0,1,1,1};

struct Node{
    Node(){}
    LL pos;
    int sta;
    bool operator < (const Node& a) const{
        return pos<a.pos;
    }
}x[MAXN];

int n;

int main(){
    int aa,cas=0; scanf("%d",&aa);
    while(aa--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i].pos);
        }
        int tag=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i].sta);
            tag+=x[i].sta;
        }
        if (tag==0){
            printf("Case #%d: -1\n",++cas);
            continue;
        }
        sort(x+1,x+n+1);
        int ls=0,lp=0,rp=0;
        LL ans=0;
        for(int i=1;i<=n;i++){
            if (x[i].sta==1){
                lp=i;
                ans+=x[i].pos-x[1].pos;
                break;
            }
        }
        for(int i=n;i>=1;i--){
            if (x[i].sta==1){
                rp=i;
                ans+=x[n].pos-x[i].pos;
                break;
            }
        }
        ls=lp;
        for(int i=lp+1;i<=rp;i++){
            if (x[i].sta==0) continue;
            ans+=x[i].pos-x[ls].pos;
            LL tmp=0;
            for(int j=ls+1;j<=i;j++){
                tmp=max(tmp,x[j].pos-x[j-1].pos);
            }
            ans-=tmp;
            ls=i;
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}
