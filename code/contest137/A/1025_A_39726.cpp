#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>


using namespace std;

const int Maxn = 1e3 + 100;
const int Inf = 1 << 30;

bool vis[Maxn];
int dis[Maxn];
int Map[Maxn][Maxn];
int n,m;
int prim() {
    int sum = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++) {
        dis[i] = Map[1][i];
    }
    vis[1] = 1;
    for(int i = 1; i < n; i++) {
        int Max = Inf;
        int to = -1;
        for(int j = 1; j <= n; j++) {
            if(!vis[j]&&dis[j]<Max) {
                Max = dis[j];
                to = j;
            }
        }
        if(to == -1)
            return -1;
        sum += dis[to];
        for(int j = 1; j <= n; j++) {
            if(!vis[j]&&Map[to][j]<dis[j]) {
                dis[j] = Map[to][j];
            }
        }
    }
    return sum;
}


int main() {
    int t;
    long long a[600];
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        long long  ans = 1 << 30;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i!=j) {
                    ans = min(ans,a[i]*a[j]/__gcd(a[i],a[j]));
                }
            }
        }
        printf("%lld\n",ans);
    }
}
//int main()
//{
//    while(~scanf("%d%d",&n,&m)&&n&&m){
//        for(int i = 1; i <= n; i++)
//        {
//            for(int j = 1; j <= n; j++)
//            {
//                Map[i][j] = Inf;
//            }
//        }
//        for(int i = 1;i <= m;i++)
//        {
//             int a,b,c;
//             scanf("%d%d%d",&a,&b,&c);
//             if(c < Map[a][b])
//             {
//                  Map[a][b] = c;
//             }
//             if(c < Map[b][a])
//             Map[b][a] = c;
//        }
//        printf("%d\n",prim());
//
//    }
//
//  return 0;
//}
