// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  gene.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017年10月12日 13时34分35秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <bits/stdc++.h>
using namespace std;


struct node {
    int a, b;
    node() {}
    node(int _a, int _b) {
        a = _a, b = _b;
    }
};
bool cmp(node a, node b) {
    return a.b < b.b;
}
int main() {

    freopen("B.in_v2", "w", stdout);
    int nc = 10;
    while (nc--) {
        int n = rand() % 1000 + 1;
        cout << n << endl;
        vector<node > vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i] = node(i + 1, rand() % INT_MAX);
        }
        sort(vec.begin(), vec.end(), cmp);
        for (int i = 0; i < n; ++i) {
            cout << vec[i].a << ' ';
        }
        cout << endl;
    }
    return 0;
}
