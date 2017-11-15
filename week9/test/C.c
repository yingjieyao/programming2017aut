// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  C.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/15 09时56分32秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>
#include <stdlib.h>

#define ll long long

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int arr[100005];
int n, m;
int check(int mid) {
    ll ret = 0;
    int i;
    if (mid == 1) {
        for (i = 0; i < n; ++i) {
            ret += (ll)arr[i];
        }
        return ret >= m;
    } else {
        for (i = 0; i < n; ++i) {
            if (arr[i] >= mid) {
                int tmp = arr[i], t = 1;
                while (tmp > mid) {
                    if (tmp / 2 >= mid) t <<= 1;
                    else if ((tmp + 1) / 2 >= mid) t++;
                    if (t >= m) return 1;
                    tmp >>= 1;
                }
                ret += t;
                if (ret >= m) return 1;
            }
        }
    }
    return ret >= m;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    int T; scanf("%d", &T);
    while (T--) {
        int i;
        scanf("%d %d", &n, &m);
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        qsort(arr, n, sizeof(int), cmp);
        int low = 0, high = 10000000;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (check(mid)) low = mid + 1;
            else high = mid - 1;
        }
        if (low == 1) puts("-1");
        else printf("%d\n", low - 1);

    }
    return 0;
}
