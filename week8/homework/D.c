// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  D.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/14 21时56分50秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <string.h>
#include <stdio.h>
#include <math.h>

#define PI  acos(-1.0)
#define eps 1e-7

int n;
int arr[10005];
int check(double mid) {
    int ans = 0, i;
    for (i = 0; i < n; ++i) {
        ans += (int)(arr[i] / mid);
    }
    return ans;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    int nc;
    scanf("%d", &nc);
    while (nc--) {
        int f;
        scanf("%d %d", &n, &f);
        f++;
        int i;
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
            arr[i] *= arr[i];
        }

        double low = 0, high = 100000050;
        while (high - low > eps) {
            double mid = (low + high) / 2;
            if (check(mid) >= f) {
                low = mid;
            } else {
                high = mid;
            }
        }
        printf("%.4f\n", low * PI);
    }
    return 0;
}
