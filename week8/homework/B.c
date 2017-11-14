// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  B.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/14 16时37分51秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxn 100005
int arr[maxn];

int cmp(const void* a, const void* b) {
    return *(int*)a > *(int*)b;
}

int n;
int check(int mid) {
    int ans = 1, i;
    int st = 0;
    int pre = 0;
    for (i = 1; i < n; ++i) {
        if (arr[i] < arr[pre] + mid) continue;
        else {
            ans++; pre = i;
        }
    }
    return ans;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    int c;
    while (scanf("%d %d", &n, &c) != EOF) {
        int i;
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        qsort(arr, n, sizeof(int), cmp);
        int low = 0, high = arr[n - 1];
        int mid;

        int ans;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (check(mid) >= c) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
