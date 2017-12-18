// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  DFS2.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/23 10时45分45秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <string.h>
#include <stdio.h>

#define maxn 111

int vis[maxn][maxn];
char mat[maxn][maxn];

int n, m;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (vis[i][j] || mat[i][j] == '0') return;
    vis[i][j] = 1;
    int direct;
    for (direct = 0; direct < 4; ++direct) {
        dfs(i + dx[direct], j + dy[direct]);
    }
}


int main() {
    int i, j;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; ++i) {
        scanf("%s", mat[i]);
    }
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            if (mat[i][j] == '1' && vis[i][j] == 0) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
