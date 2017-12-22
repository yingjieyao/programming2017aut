#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int n,tot;
int dis[1005],vis[1005],first[1005],nxt[20005],step[1005];
struct Node{
    int l,r,val;
}w[20005];
void work(int x,int y,int z){
    tot++;
    w[tot].l=x;
    w[tot].r=y;
    w[tot].val=z;
    nxt[tot]=first[x];
    first[x]=tot;
}
void spfa(int x){
    int i,q;
    queue<int> Q;
    for (i=1;i<=n;i++) dis[i]=2000000009;
    for (i=1;i<=n;i++) step[i]=2000000009;
    memset(vis,0,sizeof(vis));
    step[x]=0;
    dis[x]=0;
    Q.push(x);
    vis[x]=1;
    while (!Q.empty()){
        q=Q.front();
        Q.pop();
        vis[q]=0;
        for (i=first[q];i;i=nxt[i]){
            if (dis[w[i].r]>dis[w[i].l]+1){
                dis[w[i].r]=dis[w[i].l]+1;
                step[w[i].r]=step[w[i].l]+w[i].val;
                if (vis[w[i].r]==0){Q.push(w[i].r); vis[w[i].r]=1;}
            }
            else if(dis[w[i].r]==dis[w[i].l]+1){
                if (step[w[i].r]>step[w[i].l]+w[i].val){
                    step[w[i].r]=step[w[i].l]+w[i].val;
                    if (vis[w[i].r]==0){Q.push(w[i].r); vis[w[i].r]=1;}
                }
            }
        }
    }
}
int main()
{
    int i,x,y,z,s,e,m,T,t;
    scanf ("%d",&T);
    t=0;
    while (T>t){
        memset(nxt,0,sizeof(nxt));
        memset(first,0,sizeof(first));
        tot=0;
        scanf ("%d %d",&n,&m);
        for (i=1;i<=m;i++){
            scanf ("%d %d %d",&x,&y,&z);
            work(x,y,z);
            work(y,x,z);
        }
        scanf ("%d %d",&s,&e);
        spfa(s);
        printf ("Case #%d:\n",++t);
        if (dis[e]==2000000009) printf ("WTF?\n");
        else printf ("%d %d\n",dis[e],step[e]);
    }
    return 0;
}
