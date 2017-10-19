// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  geneC.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017/10/19 17时10分29秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <ctime>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int nc = 10;
    freopen("C.in", "w", stdout);
    while (nc--) {
        int n = (rand() % INT_MAX) / 10 + 1;
        cout << n << endl;
    }
    return 0;
}
