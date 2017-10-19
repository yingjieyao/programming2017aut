// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  geneA.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017/10/19 10时05分09秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int nc = 1;
    freopen("A.in", "w", stdout);
    while (nc--) {
        int n = 1000000;
        int t = rand() % n + 1;
        cout << n << ' ' << t + 1 << endl;
        cout << t << endl;
        for (int i = 1; i < t; ++i) {
            cout << rand() % t << ' ';
        }
        for (int i = t; i < n; ++i) {
            cout << rand() % 100 + t << ' ';
        }
        cout << endl;
    }
    nc = 10;
    while (nc--) {
        int n = 100000;
        int t = rand() % n + 1;
        cout << n << ' ' << t + 1 << endl;
        cout << t << endl;
        for (int i = 1; i < t; ++i) cout << rand() % t << ' ';
        for (int i = t; i < n; ++i) {
            cout << rand() % 100 + t << ' ';
        }
        cout << endl;
    }
    return 0;
}
