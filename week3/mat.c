// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  mat.c
//
// Description: matrix multiple
//
// Version:  1.0
// Created:  2017/09/22 08时24分50秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>
#include <stdlib.h>

int fibo(int x) {
    if (x <= 2) return 1;
    else return fibo(x - 1) + fibo(x - 2);
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        printf("%d\n", fibo(n));
    }
    return 0;
}
