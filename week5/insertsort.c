// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  insertsort.c
//
// Description: 插入排序, 给定n个数，前n-1个数是有序的，将第n个数放到合适的位置
//
// Version:  1.0
// Created:  2017/10/11 22时36分05秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>

int main() {
    int n, i, j;
    // 定义并初始化数组
    int arr[13] = {1, 3, 4, 6, 7, 9, 11, 14, 17, 18, 33, 45, 12};

    // 数组中元素个数为13
    n = 13;

    for (i = 0; i < n - 1; ++i) {
        if (arr[i] <= arr[n - 1]) continue; // 寻找第一个比arr[n-1]大的数的位置
                                            // 小于arr[n-1]的部分可以直接跳过
        else  {
            int tmp = arr[n - 1]; // 先保存好arr[n-1]这个数
            for (j = n - 1; j > i; --j) { // 将位置i以及之后的数依次往后挪一位
                arr[j] = arr[j - 1];
            }
            arr[i] = tmp; // 第i位空出，将原来的arr[n-1]放入
            break;
        }
    }

    for (i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    puts("");
    return 0;
}
