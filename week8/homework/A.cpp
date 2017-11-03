// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  A.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017年11月03日 09时20分31秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <bits/stdc++.h>
using namespace std;


void put_spaces(int cnt) {
    while (cnt--) putchar(' ');
}

int main() {
    int spaces = 0;
    char c;
    int beg = 0;
    freopen("A.in", "r", stdin);
    while ((c = getchar()) != EOF) {
        if (c == ' ') spaces++;
        else if (isalpha(c)) {
            if (beg && spaces) put_spaces(spaces);
            putchar(c);
            spaces = 0;
            if (beg == 0) beg = 1;
        } else if (c == ',' || c == '\n') {
            if (beg)puts("");
            beg = 0; spaces = 0;
        }
    }
    // if (beg) puts("");
    return 0;
}
