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
#include <bits/stdc++.h>

using namespace std;

#define ll long long
int main() {
    int nc = 1;
    freopen("A_bk.in", "w", stdout);
    while (nc--) {
        int n = 10000000;
        int t = rand() % n + 1;
//        int queries = 20;
//        cout << n << endl;
//        for (int i = 0; i < n; ++i) {
//            cout << rand() % INT_MAX << ' ';
//        }
//        cout << endl;
//        cout << queries << endl;
//        vector<ll> vec(queries);
//        vec[0] = vec[1] = 1LL;
//        for (int i = 2; i < queries; ++i) {
//            vec[i] = vec[i - 1] + vec[i-  2];
//        }
//        random_shuffle(vec.begin(), vec.end());
//        copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
//        cout << endl;
        cout << n << ' ' << t + 1 << endl;
        cout << t << endl;
        for (int i = 1; i < t; ++i) {
            cout << rand() % t << ' ';
        }
        for (int i = t; i < n - 1; ++i) {
            cout << rand() % 100 + t << ' ';
        }

        cout << INT_MAX << endl;
    }

    // rand order
    int n = 1000000;
    // int t = rand() % n + 1;
    // cout << n << ' ' << t + 1 << endl;
    // for (int i = 0; i < n; ++i) cout << rand() % n << ' ';
    // cout << endl;

    // // nc cases first best
    // nc = 5;
    // while (nc--) {
    //     n = 100000;
    //     int t = rand() % n + 1;
    //     cout << n << ' ' << t + 1 << endl;
    //     cout << t << endl;
    //     for (int i = 1; i < t; ++i) cout << rand() % t << ' ';
    //     for (int i = t; i < n; ++i) {
    //         cout << rand() % n + t << ' ';
    //     }
    //     cout << endl;
    // }

    // ascending order

    n = 1000000;
    cout << n << ' ' << rand() % n + 1 << endl;
    for (int i = n; i >= 1; --i) cout << n - i << ' ';
    cout << endl;
    return 0;
}
