// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  B.c
//
// Description:
//
// Version:  1.0
// Created:  2017年10月12日 09时30分45秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//


#include <stdio.h>

int arr[10000];
int main() {
    int n;
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    while (scanf("%d", &n) == 1) {
        int i, j;
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        int ans = 0;
        for (i = 0; i < n; ++i) {
            for (j = i + 1; j < n; ++j) {
                if (arr[i] > arr[j]) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
