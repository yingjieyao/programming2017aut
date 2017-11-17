// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  C.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/16 12时09分52秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <string.h>
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int dp[111][111];
char A[111], B[111];
int main() {
    scanf("%s %s", A + 1, B + 1);
    int n = strlen(A + 1), m = strlen(B + 1);
    memset(dp, 0, sizeof(dp));
    int i, j;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
            if (A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%d\n", dp[n][m]);
    return 0;

}
