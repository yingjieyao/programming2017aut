#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
int root[1001], rk[1001];
int n, m, cnt;
struct node{
    int u, v, w, next;
}e[1000001];
void init(void){
    cnt = 1;
    for(int i = 1; i <= n; i++)
        root[i] = i, rk[i] = 1;
}
void read(int u, int v, int w){
    e[cnt].u = u;
    e[cnt].v = v;
    e[cnt++].w = w;
}
int find_root(int x){
    while(x != root[x])
        x = root[x];
    return x;
}
void union_set(int x, int y){
    if(rk[x] < rk[y])
        root[x] = y;
    else{
        root[y] = x;
        if(rk[x] == rk[y])
            rk[x]++;
    }
}
bool cmp(node a, node b){
    return a.w < b.w;
}
int main(){
    while(scanf("%d%d",&n, &m)&&m + n){
        init();
        int u, v, w;
        for(int i = 1; i <= m; i++){
            scanf("%d%d%d",&u,&v,&w);
            read(u, v, w);
        }
        int c = 0, ans = 0;
        sort(e + 1, e + 1 + m, cmp);
        for(int i = 1; i <= m; i++){
            int x = find_root(e[i].u);
            int y = find_root(e[i].v);
            if(x == y) continue;
            union_set(x, y);
            c++;
            ans += e[i].w;
            if(c == n - 1) break;
        }
        if(c == n - 1)printf("%d\n",ans);
    }
    return 0;
}
