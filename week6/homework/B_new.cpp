// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  B_new.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017/10/19 15时51分51秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>
#include <time.h>
#include <string.h>

int num[10005];
int pre[3333];
int main() {
    int n, m;
    // freopen("B.in", "r", stdin);
    // freopen("B.out", "w", stdout);
    // clock_t start = clock(), finish;
    while (scanf("%d %d", &n, &m) == 2) {
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                num[pre[i] + pre[j]] ++;
        for (int i = 10000; i >= 0; --i) {
            while (m && num[i]) {
                num[i]--, m--;
                printf("%d%c", i, m ? ' ' : '\n');
            }
            if (!m) break;
        }
    }
    // finish = clock();
    return 0;
}
