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

#include <cstring>
#include <cstdio>
#include <ctime>

using namespace std;

int arr[100000 + 5];
int maxx[100000 + 5];
int ans[100000 + 5];
int main() {
    int n;
    freopen("E.in", "r", stdin);
    freopen("E.out", "w", stdout);
    // clock_t start = clock(), finish;
    while (scanf("%d", &n) == 1) {
        memset(maxx, 0, sizeof(maxx));
        int cnt = 0;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
            maxx[i] = mx;
            if (mx < arr[i]) mx = arr[i];
        }

        int minn = 0x3f3f3f3f;
        for (int i = n - 1; i >= 0; --i) {
            if (arr[i] > maxx[i] && arr[i] < minn) {
                ans[cnt++] = arr[i];
            }
            if (arr[i] < minn) minn = arr[i];
        }
        printf("%d", cnt);
        for (int i = cnt - 1; i >= 0; --i) {
            printf(" %d", ans[i]);
        }
        puts("");
    }
//    finish = clock();
    return 0;
}
