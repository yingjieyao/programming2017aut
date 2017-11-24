// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  BFS.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017/11/23 10时51分33秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <queue>
#include <stdio.h>

using namespace std;

#define maxn 111

int vis[maxn][maxn];
char mat[maxn][maxn];

int tx, ty;
int sx, sy;
struct Node {
    int x, y; // 用于保存每个状态的坐标
    int step; // 从起点到当前位置所需要的步数
};

int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

queue<Node> Q; // 声明一个保存Node元素的队列

int bfs() {
    int direct;

    while (!Q.empty()) Q.pop(); // 队列初始化，（清空队列
    memset(vis, 0, sizeof(vis)); // 将所有的位置标记为未访问过
    Node st;
    st.x = sx, st.y = sy, st.step = 0; // 起始点的坐标，以及需要的步数
    Q.push(st); // 将起点信息入队
    vis[sx][sy] = 1; // 将起点标记为已经访问过
    while (!Q.empty()) {
        Node cur = Q.front(); // 取队首元素
        Q.pop();
        if (cur.x == tx && cur.y == ty) return cur.step; // 如果队首元素与终点坐标相同，直接返回步数

        for (direct = 0; direct < 4; ++direct) { // 枚举四个可以走的方向
            Node nxt; // 保存下一个位置的坐标以及步数
            nxt.x = cur.x + dx[direct];
            nxt.y = cur.y + dy[direct];
            nxt.step = cur.step + 1; // 从当前位置走到下一个位置，步数加一
            if (nxt.x < 0 || nxt.x >= n || nxt.y < 0 || nxt.y >= m) continue; // 如果越界，不考虑
            if (vis[nxt.x][nxt.y] || mat[nxt.x][nxt.y] == '#') continue; // 如果不可走或者已经走过，不考虑
            vis[nxt.x][nxt.y] = 1; // 将下一个点标记为已经访问过
            Q.push(nxt); // 将下一个点入队
        }
    }

    return -1;
}

int main() {
    int i, j;
    scanf("%d %d", &n, &m);
    sx = sy = tx = ty = 0;
    for (i = 0; i < n; ++i) {
        scanf("%s", mat[i]);
        for (j = 0; j < m; ++j) {
            if (mat[i][j] == 'T') tx = i, ty = j;
            else if (mat[i][j] == 'S') sx = i, sy = j;
        }
    }

    printf("%d\n", bfs());
    return 0;
}
