// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  bubblesort.c
//
// Description: 冒泡排序
//
// Version:  1.0
// Created:  2017/10/11 21时28分36秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//
//

#include <stdio.h>

// 冒泡排序函数
//
// arr: 待排序的数组
// n: 数组中的元素个数
void bubble_sort(int arr[], int n) {
    int i, j, tmp;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j+1]) { // 大的往上浮
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp; // 上面三行是用来交换两个数的代码
            }
        }
    }
}

int main() {
    int arr[111]; //数组定义
    int n, i;

    // 输入数组中元素的个数
    scanf("%d", &n);

    // 输入数组中的元素
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    // 调用冒泡排序函数
    bubble_sort(arr, n);

    // 输出排序后的数组
    for (i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    puts("");
    return 0;
}
