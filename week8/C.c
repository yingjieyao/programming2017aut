// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  C.c
//
// Description:
//
// Version:  1.0
// Created:  2017年11月02日 21时13分07秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//


#include <stdio.h>
#include <stdlib.h>

// 在n个递增的数中查找是否存在一个数val，如果存在输出yes,否则输出no
int main() {
    int n, arr[111];
    scanf("%d", &n);
    int i, val;
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &val);
    int l = 0, r = n - 1, mid;
    while (l <= r) {
        // printf("%d %d\n", l, r);
        mid = (l + r) >> 1;
        if (arr[mid] == val) {
            break;
        } else if (arr[mid] > val) {
            r = mid - 1;
        } else l = mid + 1;
    }
    puts(arr[mid] == val ? "YES" : "NO");
    return 0;

}

