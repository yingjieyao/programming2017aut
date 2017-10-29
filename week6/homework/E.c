// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  E.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017/10/19 16时29分07秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <string.h>
#include <stdio.h>
#include <string.h>

int arr[100000 + 5];
int maxx[100000 + 5];
int ans[100000 + 5];
int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        memset(maxx, 0, sizeof(maxx));
        int cnt = 0;
        int mx = 0;
        int i;
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
            maxx[i] = mx;
            if (mx < arr[i]) mx = arr[i];
        }

        int minn = 0x3f3f3f3f;
        for (i = n - 1; i >= 0; --i) {
            if (arr[i] > maxx[i] && arr[i] < minn) {
                ans[cnt++] = arr[i];
            }
            if (arr[i] < minn) minn = arr[i];
        }
        printf("%d", cnt);
        for (i = cnt - 1; i >= 0; --i) {
            printf(" %d", ans[i]);
        }
        puts("");
    }
    return 0;
}
