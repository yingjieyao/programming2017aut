// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  bubble_sort.c
//
// Description:
//
// Version:  1.0
// Created:  2017/10/18 22时23分40秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j, tmp, k = n - 1;
    for (i = 0; i < n; ++i) {
        int flag = 0, pos = 0;
        for (j = 0; j < k; ++j) {
            if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                flag = 1;
                pos = j;
            }
        }
        if (!flag) break;
        k = pos;
    }
}

int main() {
    int n, arr[111];
    while (scanf("%d", &n) == 1) {
        int i;
        for (i = 0; i < n; ++i) scanf("%d", &arr[i]);
        bubble_sort(arr, n);
        for (i = 0; i < n; ++i) printf("%d ", arr[i]);
        puts("");
    }
    return 0;
}
