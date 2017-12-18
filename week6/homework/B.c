// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  B.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017/10/19 15时29分42秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>
#include <stdlib.h>

#define ll long long
void quick_sort(int arr[], int beg, int ed) {
    if (beg >= ed) return;
    ll tmp = arr[beg];
    int left = beg, right = ed, t;
    while (left < right) {
        while (left < right && arr[right] >= tmp) right--;
        if (left < right) {
            arr[left] = arr[right];
            left++;
        }

        while (left < right && arr[left] <= tmp) left++;
        if (left < right) {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = tmp;
    quick_sort(arr, beg, left - 1);
    quick_sort(arr, left + 1, ed);
}

int arr[1000 * 1000 / 2];
int pre[3333];
int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        int i, j;
        for (i = 0; i < n; ++i) {
            scanf("%d", pre + i);
        }
        int cnt = 0;
        quick_sort(pre, 0, n - 1);
        int test = m < n ? m : n;
        for (i = n - 1; i >= n - test; --i) {
            for (j = i - 1; j >= n - test; --j) {
                arr[cnt++] = pre[i] + pre[j];
            }
        }
        quick_sort(arr, 0, cnt - 1);
        for (i = cnt- 1; i >= cnt - m; --i) {
            printf("%d ", arr[i]);
        }
        puts("");
    }
    return 0;
}
