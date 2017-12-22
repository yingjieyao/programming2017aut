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
int xx[8] = {1,1,1,-1,-1,-1,0,0};
int yy[8] = {1,-1,0,-1,1,0,-1,1};
int xx1[4] = {1,-1,0,0};
int yy1[4] = {0,0,1,-1};

bool vis[Maxn][Maxn];
bool vis1[Maxn][Maxn];
char  Map[Maxn][Maxn];
int n,m;

bool check(int a,int b) {
    if(a >= 1 && a <= n && b >= 1 && b <= m && vis[a][b] ==0 &&Map[a][b] == '@') {
        return true;
    }
    return false;
}
bool check1(int a,int b) {
    if(a >= 1 && a <= n && b >= 1 && b <= m && vis1[a][b] ==0 &&Map[a][b] == '@') {
        return true;
    }
    return false;
}
void dfs(int a,int b) {
    vis[a][b] = 1;
    for(int i = 0; i < 4; i++)  {
        int X = a + xx1[i];
        int Y = b + yy1[i];
        if(check(X,Y)) {
            dfs(X,Y);
        }
    }

}
void dfs1(int a,int b) {
    vis1[a][b] = 1;
    for(int i = 0; i < 8; i++)  {
        int X = a + xx[i];
        int Y = b + yy[i];
        if(check1(X,Y)) {
            dfs1(X,Y);
        }
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int cnt1,cnt2;
        cnt1 = cnt2 = 0;
        scanf("%d%d",&n,&m);
        memset(vis,0,sizeof(vis));
        memset(vis1,0,sizeof(vis1));
        for(int i = 1; i <= n; i++)
            scanf("%s",Map[i] + 1);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(Map[i][j] == '@' && vis[i][j] == 0)    {
                    dfs(i,j);
                    cnt1++;
                }
                if(Map[i][j] == '@' && vis1[i][j] == 0) {
                    dfs1(i,j);
                    cnt2++;
                }
            }
        }
        printf("%d %d\n",cnt1,cnt2);
    }
}