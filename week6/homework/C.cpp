// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  C.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017/10/19 17时08分24秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <cstdio>

#define ll long long

ll cal(ll n) {
    return n * (n - 1) / 2;
}
int main() {
    ll n;
    // freopen("C.in", "r", stdin);
    // freopen("C.out", "w", stdout);
    while (scanf("%lld", &n) == 1) {
        printf("%lld\n", cal(n/2) + cal(n - n / 2));
    }
    return 0;
}
