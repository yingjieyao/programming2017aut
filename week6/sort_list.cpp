// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  tmp.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017年09月27日 19时18分22秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <bits/stdc++.h>
using namespace std;


void quicksort(int arr[], int beg, int ed) {
    if (beg >= ed) return;

    int left = beg, right = ed;
    int tmp = arr[left];
    while (left < right) {
        while (left < right && arr[right]<= tmp) right--;
        while (left < right && arr[left] >= tmp) left++;
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[beg], arr[left]);
    quicksort(arr, beg, left - 1);
    quicksort(arr, left + 1, ed);
}

void pubble(int arr[], int n) {
    int k = n - 1, pos;
    for (int i = 0; i < n; ++i) {
        int fl = 0;
        for (int j = 0; j < k; ++j) {
            if (arr[j] < arr[j+1]) {
                swap(arr[j], arr[j+1]);
                pos = j;
                fl = 1;
            }
        }
        k = pos;
        if (!fl) break;
        for (int j = 0; j < n; ++j) {
            printf("%d ", arr[j]);
        }
        puts("");
    }
}
void insert(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void select(int arr[], int n) {
    int beg = 0, ed = n - 1;
    for (beg = 0, ed = n -1; beg <= ed; ++beg, --ed) {
        int minn = beg, maxx = beg;
        for (int i = beg; i <= ed; ++i) {
            if (arr[i] < arr[minn]) minn = i;
            if (arr[i] > arr[maxx]) maxx = i;
        }
        swap(arr[beg], arr[minn]);
        if (beg == maxx) maxx = minn;
        swap(arr[ed], arr[maxx]);
    }
}

int ar[1000000+5];
int main() {
    int n, m;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &ar[i]);
        }
        select(ar, n);
        for (int i = 0; i < n; ++i) {
            printf("%d ", ar[i]);
        }
        puts("");
    }
    return 0;
}
