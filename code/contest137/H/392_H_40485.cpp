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
    Node(int pos_,int tim_,int wei_):pos(pos_),tim(tim_),wei(wei_){}
    int pos,tim,wei;
    bool operator < (const Node &a) const{
        return tim<a.tim;
    }
}x[MAXN];

int n,dp[100005][30];

int main(){
    while(scanf("%d",&n),n!=0){
        for(int i=1;i<=n;i++){
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            x[i]=Node(a,b,c);
        }
        sort(x+1,x+n+1);
        for(int i=0;i<=20;i++) dp[0][i]=-1000000000;
        dp[0][10]=0;
        int pos=0;
        for(int i=1;i<=n;i++){
            for(int j=pos+1;j<x[i].tim;j++){
                for(int k=0;k<=20;k++){
                    dp[j][k]=dp[j-1][k];
                    if (k>0) dp[j][k]=max(dp[j][k],dp[j-1][k-1]);
                    if (k<20) dp[j][k]=max(dp[j][k],dp[j-1][k+1]);
                }
            }
            if (pos==x[i].tim){
                dp[pos][x[i].pos]+=x[i].wei;
                continue;
            }
            pos=x[i].tim;
            int j=x[i].tim;
            for(int k=0;k<=20;k++){
                dp[j][k]=dp[j-1][k];
                if (k>0) dp[j][k]=max(dp[j][k],dp[j-1][k-1]);
                if (k<20) dp[j][k]=max(dp[j][k],dp[j-1][k+1]);
            }
            dp[pos][x[i].pos]+=x[i].wei;
        }
        int ans=0;
        for(int i=0;i<=20;i++)
            ans=max(ans,dp[pos][i]);
        printf("%d\n",ans);
    }
    return 0;
}
