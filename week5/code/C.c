// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  C.c
//
// Description:
//
// Version:  1.0
// Created:  2017年10月12日 09时39分06秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>

int arr[1000];
int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int i, j;
        for (i = 0; i < n; ++i) scanf("%d", &arr[i]);
        int ans = 0;
        for (i = 0; i < n; ++i) {
            int flag = 0;
            ans++;
            for (j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    flag = 1;
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
            if (!flag) break;
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}
