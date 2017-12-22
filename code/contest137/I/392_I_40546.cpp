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
    int l,r;
    double tim,ans;
}x[200];

int n,vis[200];

int main(){
    int aa,cas=0; scanf("%d",&aa);
    while(aa--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            double a; scanf("%lf",&a);
            x[i].l=i-1;
            x[i].r=i+1;
            x[i].tim=a;
            vis[i]=0;
        }
        int head=1,num=n;
        double now=0;
        while(num>0){
            for(int i=1;i<=n;i++){
                if (vis[i]==1) continue;
                if (x[i].tim>1.0){
                    now+=1.0;
                    x[i].tim-=1.0;
                }
                else{
                    now+=x[i].tim;
                    x[i].ans=now;
                    now+=1;
                    vis[i]=1;
                    num--;
                }
            }
        }
        printf("Case %d:",++cas);
        for(int i=1;i<n;i++){
            printf("%.2f ",x[i].ans);
        }
        printf("%.2f\n",x[n].ans);
    }
    return 0;
}
