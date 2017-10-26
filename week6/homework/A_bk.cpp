// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  A_bk.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017年10月20日 17时58分51秒
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
int arr[10000000+5];
int main() {
    int n, k;
    freopen("A_bk.in", "r", stdin);
    freopen("Abk.out", "w", stdout);
    clock_t start = clock(), finish;
    while (~scanf("%d%d", &n, &k)) {
        for (int i = 0; i < n; ++i) arr[i] = read();
        nth_element(arr, arr + k - 1, arr + n);
        printf("%d\n", arr[k - 1]);
    }
    finish = clock();
    printf("%f\n", (finish - start) * 1.0 / CLOCKS_PER_SEC);
    return 0;
}
