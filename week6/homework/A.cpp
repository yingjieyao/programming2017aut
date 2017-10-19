// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  A.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017/10/19 09时36分25秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>
#include <time.h>
#include <assert.h>

int k, ans;
void quick_sort(int arr[], int beg, int ed) {
//    assert(beg <= ed);
    if (beg == ed) {
        if (beg == k) ans = arr[beg];
        return;
    }
    int tmp = arr[beg];
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
//     printf("left %d, tmp %d\n", left, tmp);
//     for (int i = 0; i <= ed; ++i) {
//         printf("%d ", arr[i]);
//     }
//     puts("");
    if (left == k) {
        ans = tmp;
    } else if (left > k) {
        quick_sort(arr, beg, left - 1);
    } else {
        quick_sort(arr, left + 1, ed);
    }
}


int arr[1000001];
int main() {
    int n, i;
//    freopen("A.in", "r", stdin);
//    freopen("A.out", "w", stdout);
    while (scanf("%d %d", &n, &k) == 2) {
        ans = -1;
        k--;
        for (i = 0; i < n; ++i) scanf("%d", &arr[i]);
        quick_sort(arr, 0, n - 1);
        printf("%d\n", ans);
    }
//    printf("%lf\n", (finish - start) * 1.0 / CLOCKS_PER_SEC);
    return 0;
}
