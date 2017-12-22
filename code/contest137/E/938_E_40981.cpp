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
struct node{
    int x, y;
};
int m,n;
char mat[111][111];
int visit[111][111];
queue <node> q;
int dirx[8] = {0,0,1,-1,1,1,-1,-1}, diry[8] = {1,-1,0,0,1,-1,1,-1};
int bfs1(){
    memset(visit, 0, sizeof(visit));
    int ans = 0;
    while(!q.empty())
        q.pop();
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        if(visit[i][j]||mat[i][j] == '#')
            continue;
        node st;st.x = i,st.y = j;
        q.push(st);
        visit[i][j] = 1;
        ans++;
        while(!q.empty()){
            node tmp = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                node cur = tmp;
                cur.x += dirx[k];
                cur.y += diry[k];
                if(cur.x < 1||cur.x > n||cur.y < 1||cur.y > m||visit[cur.x][cur.y]||mat[cur.x][cur.y] == '#')
                    continue;
                visit[cur.x][cur.y] = 1;
                q.push(cur);
            }
        }
    }
    return ans;
}
int bfs2(){
    memset(visit, 0, sizeof(visit));
    int ans = 0;
    while(!q.empty())
        q.pop();
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        if(visit[i][j]||mat[i][j] == '#')
            continue;
        node st;st.x = i,st.y = j;
        q.push(st);
        visit[i][j] = 1;
        ans++;
        while(!q.empty()){
            node tmp = q.front();
            q.pop();
            for(int k = 0; k < 8; k++){
                node cur = tmp;
                cur.x += dirx[k];
                cur.y += diry[k];
                if(cur.x < 1||cur.x > n||cur.y < 1||cur.y > m||visit[cur.x][cur.y]||mat[cur.x][cur.y] == '#')
                    continue;
                visit[cur.x][cur.y] = 1;
                q.push(cur);
            }
        }
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf(" %c",&mat[i][j]);
        int ans1 = 0, ans2 = 0;
        ans1 = bfs1();
        ans2 = bfs2();
        printf("%d %d\n",ans1, ans2);
    }
    return 0;
}
