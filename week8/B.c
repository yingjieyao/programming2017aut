// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  B.c
//
// Description:
//
// Version:  1.0
// Created:  2017年11月02日 21时03分27秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//


#include <stdio.h>
#include <stdlib.h>

// 计算函数零点
double f(double x) {
    return x + 2;
}

int main() {
    double l = -100, r = 100;
    while (r - l > 1e-6) { // for (i = 0; i < 100; ++i)
        double mid = (l + r) / 2;
        if (f(mid) > 0) r = mid;
        else l = mid;
    }
    printf("%.6lf\n", l);
    return 0;
}
