// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  B.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017/10/19 15时29分42秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>

using namespace std;

#define ll long long
void quick_sort(int arr[], int beg, int ed) {
    if (beg >= ed) return;
    ll tmp = arr[beg];
    int left = beg, right = ed, t;
    while (left < right) {
        while (left < right && arr[right] >= tmp) right--;
        if (left < right) {
            arr[left] = arr[right];
            left++;
        }

        while (left < right && arr[left] <= tmp) left++;
        if (left < right) {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = tmp;
    quick_sort(arr, beg, left - 1);
    quick_sort(arr, left + 1, ed);
}

int arr[5000000];
int pre[3333];
int main() {
    int n, m;
    // freopen("B.in", "r", stdin);
    // freopen("B.out", "w", stdout);
    // clock_t start = clock();
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", pre + i);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                arr[cnt++] = pre[i] + pre[j];
            }
        }
        sort(arr, arr + cnt);
        // quick_sort(arr, 0, cnt - 1);
        for (int i = cnt - 1; i >= cnt - m; --i) printf("%d ", arr[i]);
        puts("");
    }
    // clock_t ed= clock();
    // printf("%f\n", (ed - start) * 1.0 / CLOCKS_PER_SEC);
    return 0;
}
