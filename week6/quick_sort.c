// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  quick_sort.c
//
// Description:
//
// Version:  1.0
// Created:  2017/10/18 22时13分30秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>

// 快速排序函数，对数组arr的[beg, ed]之间的元素排序
void quick_sort(int arr[], int beg, int ed) {
    if (beg >= ed) return;

    int left = beg, right = ed;
    int tmp = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= tmp) right--;
        if (left < right) {
            arr[left] = arr[right]; left++;
        }

        while (left < right && arr[left] <= tmp) left++;
        if (left < right) {
            arr[right] = arr[left]; right--;
        }
    }
    arr[left] = tmp;
    // 递归得处理左半部分与右半部分
    quick_sort(arr, beg, left - 1);
    quick_sort(arr, left + 1, ed);
}

int main() {
    int n, arr[111];
    while (scanf("%d", &n) == 1) {
        int i;
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }

        quick_sort(arr, 0, n - 1);

        for (i = 0; i < n; ++i) {
            printf("%d ", arr[i]);
        }
        puts("");
    }
    return 0;
}
