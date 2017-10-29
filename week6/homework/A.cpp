// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  A.cpp
//
// Description:
//
// Version:  1.0
// Created:  2017/10/19 09时36分25秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <algorithm>

using namespace std;

int getint() {
    int r = 0; char t = 0;
    while (t < '0' || t > '9')  {
        if ((t = getchar()) == EOF) return EOF;
    }
    while (t >= '0' && t <= '9') {
        r = r * 10 + t - '0';
        t = getchar();
    }
    return r;
}

int k;
void quick_sort(int arr[], int beg, int ed) {
    if (beg == ed) {
        return;
    }
    int tmp = arr[beg];
    int left = beg, right = ed, t;
    while (left < right) {
        while (left < right && arr[right] >= tmp) right--;
        if (left < right) {
            arr[left] = arr[right];
            left++;
        }

        while (left < right && arr[left] <= tmp) left++;
        if (left < right) {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = tmp;
    if (left == k) {
        return;
    } else if (left > k) {
        quick_sort(arr, beg, left - 1);
    } else {
        quick_sort(arr, left + 1, ed);
    }
}

int read()
{
    int n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int arr[10000001];
int main() {
    int n, i;
<<<<<<< HEAD
=======
    freopen("A_bk.in", "r", stdin);
    freopen("A_bk.out", "w", stdout);
    clock_t start = clock(), finish;
>>>>>>> c3195a2015ec33f059af0d628c619b181bffc894
    while (scanf("%d %d", &n, &k) == 2) {
        k--;
<<<<<<< HEAD
        for (i = 0; i < n; ++i) arr[i] = getint();
        quick_sort(arr, 0, n - 1);
        printf("%d\n", arr[k]);
    }
=======
        for (i = 0; i < n; ++i) arr[i] = read();
        //  nth_element(arr, arr + k - 1, arr + n);
        // sort(arr, arr + n);
        quick_sort(arr, 0, n - 1);
        printf("%d\n", arr[k]);
    }
    finish = clock();
    printf("%lf\n", (finish - start) * 1.0 / CLOCKS_PER_SEC);
>>>>>>> c3195a2015ec33f059af0d628c619b181bffc894
    return 0;
}
