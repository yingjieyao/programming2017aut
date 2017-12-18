// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  D.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/15 09时39分07秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define FLAG (flag ? -1: 1)

int __gcd(int a, int b) {
    return b ? __gcd(b, a % b) : a;
}

void deal(char* s, int* x, int *y) {
    *x = *y = 0;
    int len = strlen(s);
    int flag = 0, digit = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '-') {
            if (digit) *y += (flag ? -1: 1) *digit;
            flag = 1;
            digit = 0;
        } else if (s[i] >= '0' && s[i] <= '9') digit = digit * 10 + (int)(s[i] - '0');
        else if (s[i] == 'x') {
            if (!digit && !isdigit(s[i-1])) digit = 1;
            *x += (FLAG) * digit;
            digit = 0;
            flag = 0;
        } else if (s[i] == '+') {
            *y += (FLAG) * digit;
            flag = 0;
            digit = 0;
        }
    }
    if (digit) *y += (FLAG) * digit;
    // cout << *x << ' ' << *y << endl;
}

char s[155];
int main() {

#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif

    while (scanf("%s", s) == 1) {
        int st = 0, len = strlen(s);
        while (st < len && s[st] != '=') st++;

        int x, y, xx, yy;
        char *second = &s[st+1];
        s[st] = '\0';
        deal(s, &x, &y);
        deal(second, &xx, &yy);

        x -= xx, yy -= y;

        if (x) {
            if (yy % x == 0) {
                printf("x=%d\n", yy / x);
            } else {
                int flag = (x * yy < 0);
                yy = abs(yy), x = abs(x);
                int gcd = __gcd(yy, x);
                printf("x=%d/%d\n", (flag ? - 1: 1) * yy / gcd, x / gcd);
            }
        } else {
            if (yy == 0) {
                puts("Infinite many solutions");
            } else {
                puts("No solution");
            }
        }
    }
    return 0;
}
