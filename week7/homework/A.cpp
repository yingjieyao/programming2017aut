// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  A.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017年10月26日 19时51分46秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <bits/stdc++.h>
using namespace std;


struct Node {
    int id, x, y;
}arr[100005];
int n;

bool cmp(Node a, Node b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
int main() {
    // freopen("A.in", "r", stdin);
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &arr[i].x, &arr[i].y);
            arr[i].id = i;
        }
        sort(arr, arr + n, cmp);
        cout << arr[0].id;
        for (int i = 1; i < n; ++i) {
            cout << " " << arr[i].id;
        }
        cout << endl;
    }
    return 0;
}
