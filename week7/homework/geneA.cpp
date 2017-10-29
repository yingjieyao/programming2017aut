// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  geneA.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017年10月26日 19时55分09秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> cases = {5, 10, 100000, 100000};
    for (auto n : cases) {
        cout << n << endl;
        vector<int> vec(n);
        for (int i = 1; i <= n; ++i) {
            vec[i - 1] = i * (rand() & 1 ? -1 : 1);
        }
        random_shuffle(vec.begin(), vec.end());
        vector<int> tmp2 = vec;
        random_shuffle(tmp2.begin(), tmp2.end());
        for (int i = 0; i < n - 3; ++i) {
            cout << vec[i] << ' ' << tmp2[i] << ' ';
        }
        cout << "0 1 0 -1 0 0";
        cout << endl;
    }
    return 0;
}
