// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  D.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/16 12时16分01秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <string.h>
#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return a > b ? b : a;
}

int dp[111][111];
int num[111];
int main() {
    int n, i; scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &num[i]);
    }
    memset(dp, 0, sizeof(dp));
    int len, k;
    for (len = 2; len < n; ++len) {
        for (i = 2; i + len<= n + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + num[i-1] * num[k] * num[j]);
            }
        }
    }
    printf("%d\n", dp[2][n]);
    return 0;
}
