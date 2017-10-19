// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  geneD.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017/10/19 16时09分34秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <algorithm>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

struct N {
    int val, id;
    N() {}
    N(int _val, int _id) {
        val = _val, id = _id;
    }
    bool operator<(const N &a) const {
        return a.val < val;
    }
};
int main() {
    int nc = 10;
    freopen("D.in", "w", stdout);
    while (nc--) {
        int n = 5000;
        cout << n << endl;
        vector<N> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i] = N(rand() % n, i);
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < n; ++i) {
            cout << vec[i].id << ' ';
        }
        cout << endl;
    }
    return 0;
}
