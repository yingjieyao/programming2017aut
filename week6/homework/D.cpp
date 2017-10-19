// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  D.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017/10/19 16时06分18秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <cstdio>
#include <cstdlib>
#include <ctime>

int arr[5111];
int main() {
    int n;
    // freopen("D.in", "r", stdin);
    // freopen("D.out", "w", stdout);
    // clock_t start = clock(), finish;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] > arr[i]) {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
//    finish = clock();
    return 0;
}
