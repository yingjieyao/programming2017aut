// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  E.c
//
// Description:
//
// Version:  1.0
// Created:  2017年10月12日 10时15分56秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//


#include <stdio.h>

int abs(int n) {
    return n > 0 ? n : -n;
}

void bubble_sort(int arr[], int n) {
    int i, j, tmp;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            if (abs(arr[j]) < abs(arr[j + 1])) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}


int main() {
    int n;
    int arr[1110];
    freopen("E.in", "r", stdin);
    freopen("E.out", "w", stdout);
    while (scanf("%d", &n) == 1 && n) {
        int i;
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        bubble_sort(arr, n);
        for (i = 0; i < n - 1; ++i) {
            printf("%d ", arr[i]);
        }
        printf("%d\n", arr[n-1]);
    }
    return 0;
}
