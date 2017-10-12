// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  A.c
//
// Description:
//
// Version:  1.0
// Created:  2017年10月12日 09时19分05秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//


#include <stdio.h>


// #define LOCAL
int arr[1001];

int main() {
    int n;
#ifdef LOCAL
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    while (scanf("%d", &n) == 1 && n) {
        int i;
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        int minn_index = 0, maxx_index = 0;
        for (i = 1; i < n; ++i) {
            if (arr[i] > arr[maxx_index]) maxx_index = i;
            if (arr[i] <= arr[minn_index]) minn_index = i;
        }
        printf("%d %d\n", minn_index, maxx_index);
    }
    return 0;
}

