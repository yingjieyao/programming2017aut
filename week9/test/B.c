// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  B.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/15 09时30分52秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxn 10005
#define M 1000

int n, k;
int len[maxn];
int cal(int x) {
    int i, ret = 0;
    for (i = 0; i < n; ++i) {
        ret += (int)(len[i] / x);
    }
    return ret >= k;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    while (scanf("%d %d", &n, &k) == 2) {
        int max = 0; double r;
        int i;
        for (i = 0; i < n; ++i) {
            scanf("%lf", &r);
            len[i] = (r + 0.001) * M;
            if (len[i] > max) max = len[i];
        }
        int low = 0, high = max;
        while (high - low > 1) {
            int mid = (low + high) >> 1;
            if (cal(mid)) low = mid;
            else high = mid;
        }
        if (high % 10 >= 5) high -= 5;
        printf("%.2lf\n", (double)high / M);
    }
    return 0;
}
