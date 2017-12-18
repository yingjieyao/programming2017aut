// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  B.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/16 11时12分42秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <string.h>
#include <stdio.h>

int arr[111], dp[111], pre[111];
int main() {
    int n, i, j;
    scanf("%d" ,&n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        dp[i] = 1, pre[i] = -1;
    }
    int ans_index = 0;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j < i; ++j) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                pre[i] = j; // 记录LIS中i之前的位置应该是j
            }
        }
        if (dp[i] > dp[ans_index]) ans_index = i;
    }
    printf("%d\n", dp[ans_index]);

    // 输出最长上升子序列，逆序输出
    do {
        printf("%d ", arr[ans_index]);
        ans_index = pre[ans_index];
    }while (ans_index != -1);
    puts("");

    return 0;
}
