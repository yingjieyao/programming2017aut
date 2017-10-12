// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  D.c
//
// Description:
//
// Version:  1.0
// Created:  2017年10月12日 09时50分56秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>

int arr[1111];

int main() {
    int n, i, j, tmp;
    int nc;
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    scanf("%d", &nc);
    while (nc--) {
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        if (n == 1) {
            printf("0 1\n");
            continue;
        }
        int fl = 0;
        for (i = 0; i < n - 2; ++i) {
            if (arr[i] > arr[i+1]) {
                fl = 1;
                break;
            }
        }

        if (fl) {
            for (i = 0, j = n -2; i < j; ++i, --j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        int first = n - 1, second = 0;
        for (i = 0; i < n - 1; ++i) {
            if (arr[i] >= arr[n-1]) {
                first = i;
                break;
            }
        }
        for (i = n - 2; i >= 0; --i) {
            if (arr[i] <= arr[n-1]) {
                second = i + 1;
                break;
            }
        }
        if (fl) {
            first = n - first - 1;
            second = n -second - 1;
        }
        if (first > second) {
            tmp = first;
            first = second;
            second = tmp;
        }
        printf("%d %d\n", first, second);
    }
    return 0;
}
