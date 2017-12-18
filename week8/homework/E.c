// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  E.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/14 22时05分31秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <string.h>
#include <stdio.h>
#include <math.h>

#define eps 1e-10
double x, y, c;
int check(double mid) {
    return 1 - c / sqrt(x * x - mid * mid) - c / sqrt(y * y - mid * mid) > 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("E.in", "r", stdin);
#endif

    while (scanf("%lf %lf %lf", &x, &y, &c) != EOF) {
        double low = 0, high = x +y;
        while (low < high - eps) {
            double mid = (low + high) / 2;
            if (check(mid)) low = mid;
            else high = mid;
        }
        printf("%.3lf\n", low);
    }

    return 0;
}
