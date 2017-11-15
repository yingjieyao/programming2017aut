// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  A.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/14 22时15分06秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>

typedef struct stack {
    int top;
    int s[1055];
}St;

void init(St *st) {
    st -> top = -1;
}

void push(St* st, int val) {
    st->s[++st->top] = val;
}

int empty(St* st) {
    return st -> top == -1;
}

void pop(St* st) {
    st -> top --;
}

int top(St* st) {
    return st -> s[st -> top];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    St st; init(&st);
    int num[1005];
    int n;
    while (scanf("%d", &n) == 1 && n) {
        while (scanf("%d", &num[0]) != EOF && num[0]) {
            init(&st);
            int i, j;
            push(&st, 1);
            for (i = 1; i < n; ++i) scanf("%d", &num[i]);

            for (i = 0, j = 1; i < n && j <=n;) { // 出栈序列中的第i个和到来序列中的第j个数(j)
                if (top(&st) == num[i]) { // 如果栈顶的数字和现在出栈序列中的第一个数字一样，那么直接出栈就可以
                    pop(&st); i++;
                    if (empty(&st) && ++j <= n) push(&st, j);
                } else { // 如果不相同，那么接着压下一个数
                    push(&st, ++j);
                }
            }
            if (empty(&st)) puts("Yes");
            else puts("No");
        }
        puts("");
    }

    return 0;
}
