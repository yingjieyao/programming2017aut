// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  selectsort.c
//
// Description: 选择排序
//
// Version:  1.0
// Created:  2017/10/11 22时28分36秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>

// 选择排序函数
//
// arr: 待排序的数组
// n: 数组中元素的个数
void select_sort(int arr[], int n) {
    int min_index = 0;
    int i, j, tmp;
    for (i = 0; i < n; ++i) {
        min_index = i; // 假设最小的元素下标是min_index
        for (j = i + 1; j < n; ++j) { // 在剩下的元素中寻找最小的元素
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }
        if (min_index != i) { // 如果发现i这个位置对应的元素不是最小的，那么需要交换
            tmp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = tmp;
        }
    }
}

// 主函数部分代码的注释见bubblesort.c
int main() {
    int n, i;
    int arr[111];
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    select_sort(arr, n);
    for (i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    puts("");
    return 0;
}
