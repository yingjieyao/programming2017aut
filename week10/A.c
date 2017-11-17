// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  A.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/16 11时07分01秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int dp[111][111];
int arr[111][111];
int main() {
    int n;
    scanf("%d", &n);
    int i, j;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= i; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    memset(dp, 0, sizeof(dp));
    for (i = n; i >= 1; --i) {
        for (j = 1; j <= i; ++j) {
            if (i == n) dp[i][j] = arr[i][j];
            else dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + arr[i][j];
        }
    }
    printf("%d\n", dp[1][1]);
    return 0;
}
