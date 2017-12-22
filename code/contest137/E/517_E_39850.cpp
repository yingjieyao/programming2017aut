#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const int dx[] = {1,0,-1,0,1,1,-1,-1};
const int dy[] = {0,1,0,-1,-1,1,1,-1};

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') {if(a == '-') flag = 1; a = getchar();}
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,m;

bool isin(int x,int y) { return x >= 1 &&x <= n && y >= 1 && y <= m; }

int fa[SZ];
char maps[110][110];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int get(int x,int y) { return (x - 1) * m + y; }

int get_ans(int dr)
{
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            fa[get(i,j)] = get(i,j);
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(maps[i][j] == '@')
            {
                for(int k = 0;k < dr;k ++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(isin(x,y) && maps[x][y] == '@')
                        fa[find(get(x,y))] = find(get(i,j));
                }
            }
    int ans = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(maps[i][j] == '@' && find(get(i,j)) == get(i,j))
                ans ++;
    return ans;
}

int main()
{
    int T = read();
    while(T --)
    {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i ++)
            scanf("%s",maps[i] + 1);
        printf("%d %d\n",get_ans(4),get_ans(8));
    }
    return 0;
}


