// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  geneE.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017年10月12日 13时41分03秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    freopen("E.in_v2", "w", stdout);

    int nc = 10;
    while (nc--) {
        n = rand() % 100 + 1;
        cout << n << endl;
        vector<int> vec(n);
        int pre = 0;
        for (int i = 0; i < n; ++i) {
            int cur = pre + rand() % 50000 + 1;
            vec[i] = cur;
            pre = cur;
        }
        for (int i = 0; i < n; ++i) {
            if (rand() & 1) cout << vec[i] << ' ';
            else cout << -vec[i] << ' ';
        }
        cout << endl;
    }
    cout << 0 << endl;
    return 0;
}
