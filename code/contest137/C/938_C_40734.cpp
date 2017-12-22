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

using namespace std;
int mat[1001][1001];
int con[1001];
queue <int> q;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m;
        scanf("%d%d",&n,&m);
        memset(mat, 0, sizeof(mat));
        for(int i = 1; i <= m; i++){
            int a, b;
            scanf("%d%d",&a,&b);
            mat[a][b] = mat[b][a] = 1;
        }
        memset(con, 0, sizeof(con));
        while(!q.empty()) q.pop();
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(!con[i]){
                q.push(i);
                while(!q.empty()){
                    int tmp = q.front();
                    q.pop();
                    con[tmp] = 1;
                    for(int j = i + 1; j <= n; j++)
                        if(!con[j]&&mat[tmp][j] == 1)
                            q.push(j);
                }
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
