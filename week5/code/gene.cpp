// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  gene.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017年10月12日 09时23分13秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("E.in", "w", stdout);
    int cnt = 10;
    while (cnt --) {
        int n = rand() % 1000;
        cout << n << endl;
        for (int i = 0; i < n ; ++i) {
            int tmp = rand() % 2;
            int sgn = tmp ? 1: -1;
            cout << (rand() % 10000) * sgn << ' ';
        }
        cout << endl;
    }
    cout << 0 << endl;
    return 0;
}
