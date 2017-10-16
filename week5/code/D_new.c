// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  E_new.c
//
// Description:
//
// Version:  1.0
// Created:  2017年10月16日 16时02分55秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>

int arr[1001];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, i;
        scanf("%d", &n);
        for (i = 0; i < n; ++i) scanf("%d", &arr[i]);
        int tmp = arr[n - 1];
        int first = 0, second = 0;
        if (arr[0] < arr[n - 2]) {
            for (i = 0; i < n - 1; ++i) {
                if (arr[i] < tmp) first = i + 1;
                if (arr[i] <= tmp) second = i + 1;
            }
        } else {
            for (i = 0; i < n - 1; ++i) {
                if (arr[i] > tmp) first = i + 1;
                if (arr[i] >= tmp) second = i + 1;
            }
        }
        printf("%d %d\n", first, second);
    }
    return 0;
}


