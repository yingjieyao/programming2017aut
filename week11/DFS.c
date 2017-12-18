// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  DFS.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/23 10时30分27秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <string.h>
#include <stdio.h>

#define maxn 111

int vis[maxn][maxn]; // 用于标记一个位置是否被访问过
char mat[maxn][maxn]; // 保存迷宫

int tx, ty; // 终点T的横纵坐标
int sx, sy; // 起点S的横纵坐标

int arrival; // 标记是否可达T的标记变量
int n, m; // 迷宫的行数和列数

int dx[4] = {0, 0, 1, -1}; // 在每个位置可以走的四个方向
int dy[4] = {1, -1, 0, 0};

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return; //如果当前位置超出了边界
    if (vis[i][j] || mat[i][j] == '#') return; // 或者当前位置已经来过，或者当前位置不可走，直接结束在当前位置的查找
    vis[i][j] = 1; // 将当前位置标记为访问过
    if (tx == i && ty == j) { // 如果当前位置与终点的坐标相同，表示从S可以到达这个位置
        arrival = 1; return; // arrival 标记为1
    }
    int direct;
    // 枚举在当前位置可以走的四个方向
    for (direct = 0; direct < 4 && !arrival; ++direct) {
        dfs(i + dx[direct], j + dy[direct]); // 递归得去四个方向接着寻找
    }
}

int main() {
    int i, j;
    scanf("%d %d", &n, &m);
    memset(vis, 0, sizeof(vis)); // 标记所有位置为未访问过
    sx = sy = tx = ty = 0;
    for (i = 0; i < n; ++i) {
        scanf("%s", mat[i]);
        for (j = 0; j < m; ++j) {
            if (mat[i][j] == 'T') {
                tx = i, ty = j; // 保存终点坐标
            } else if (mat[i][j] == 'S') {
                sx = i, sy = j; // 保存起点坐标
            }
        }
    }
    arrival = 0; // 标记变量初始化
    dfs(sx, sy); // 从起点开始找
    puts(arrival ? "Yes" : "No");
    return 0;
}
