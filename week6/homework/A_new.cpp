// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  A_new.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017年10月25日 11时22分39秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <bits/stdc++.h>
using namespace std;

int read()
{
    int n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

#define ll long long
int arr[10000000+5];
int partion(int beg, int ed, int pvi) {
    while (1) {
        while (arr[beg] < arr[pvi]) beg++;
        ed--;
        while (pvi < arr[ed]) ed--;
        if (!(beg < ed)) return beg;
        int tmp = arr[beg];
        arr[beg] = arr[ed];
        arr[ed] = tmp;
        beg++;
    }
}

void quick_kth(int beg, int ed, int k) {
    while (ed - beg > 3) {
        int midd = beg + (ed - beg) / 2;
        ll pvi = arr[beg] + arr[ed - 1] + arr[midd] - min(arr[midd], min(arr[beg], arr[ed-1]));
        pvi -= max(arr[midd], max(arr[beg], arr[ed-1]));
        int part = partion(beg, ed, (int)pvi);
        if (part <= k) beg = part;
        else ed = part;
    }
}

int main() {
    int n, k;
    freopen("A_bk.in", "r", stdin);
    freopen("A_bk_quick.out", "w", stdout);
    clock_t start = clock(), finish;
    while (scanf("%d%d", &n, &k) == 2) {
        for (int i = 0; i < n; ++i) arr[i] = read();
        nth_element(arr, arr + k - 1, arr + n);
        // quick_kth(0, n, k - 1);
        printf("%d\n", arr[k - 1]);
    }
    finish = clock();
    printf("%f\n", (finish - start) * 1.0 / CLOCKS_PER_SEC);
    return 0;
}
