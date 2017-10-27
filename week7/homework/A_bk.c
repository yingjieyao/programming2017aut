// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  A_bk.c
//
// Description:
//
// Version:  1.0
// Created:  2017年10月27日 20时10分23秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>

#define Node struct node
struct node{
    int x, y;
    int id;
}arr[100000 + 5];

int cmp(Node i, Node j) {
    if ((i.x < j.x) || (i.x == j.x && i.y < j.y))
        return 1;
    else return 0;
}
void quick_sort(int beg, int ed) {
    if (beg >= ed) {
        return ;
    }
    Node tmp = arr[beg];
    int left = beg, right = ed;
    while (left < right) {
        while (left < right && cmp(tmp, arr[right]) == 1) right--;
        if (left < right) {
            arr[left] = arr[right];
            left++;
        }
        while (left < right && cmp(arr[left], tmp) == 1) left++;
        if (left < right) {
            arr[right] = arr[left];
            right--;
        }
    }
    arr[left] = tmp;
    quick_sort(beg, left - 1);
    quick_sort(left + 1, ed);
}

int main() {
    int n;
    freopen("A.in", "r", stdin);
    while (scanf("%d", &n) == 1) {
        int i;
        for (i = 0; i < n; ++i) {
            scanf("%d %d", &arr[i].x, &arr[i].y);
            arr[i].id = i;
        }
        quick_sort(0, n - 1);
        printf("%d", arr[0].id);
        for (i = 1; i < n; ++i) {
            printf(" %d", arr[i].id);
        }
        puts("");
    }

    return 0;
}

