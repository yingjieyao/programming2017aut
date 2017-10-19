// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  geneB.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017/10/19 15时35分13秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int nc = 10;
    freopen("B.in", "w", stdout);
    while (nc--) {
        int n = 3000, m = 1000;
        cout << n << ' ' << m << endl;
        for (int i = 0;  i < n; ++i) {
            int t = nc ? n : INT_MAX;
            t = 5000;
            cout << rand() % t << ' ';
        }
        cout << endl;
    }
    nc = 10;
    return 0;
}
