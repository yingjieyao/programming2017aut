#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
int vis[1005],Map[1005][1005];
void dfs(int x){
    int i;
    if (vis[x]==1) return ;
    vis[x]=1;
    for (i=1;i<=n;i++)
        if (Map[x][i]==1) dfs(i);
    return ;
}
int main()
{
    int T,ans,i,a,b,m;
    scanf ("%d",&T);
    while (T>0){
        ans=0;
        memset(Map,0,sizeof(Map));
        memset(vis,0,sizeof(vis));
        scanf ("%d %d",&n,&m);
        for (i=1;i<=m;i++){
            scanf ("%d %d",&a,&b);
            Map[a][b]=1;
            Map[b][a]=1;
        }
        for (i=1;i<=n;i++){
            if (vis[i]==0){
                dfs(i);
                ans++;
            }
        }
        printf ("%d\n",ans);
        T--;
    }
    return 0;
}
