// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  C.c
//
// Description:
//
// Version:  1.0
// Created:  2017/11/14 17时09分21秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top;
    char s[105][77];
}St;

void init(St *st) {
    st -> top = -1;
}

void push(St* st, char s[]) {
    strcpy(st -> s[++st->top], s);
}

int empty(St* st) {
    return st -> top == -1;
}

void pop(St* st) {
    st -> top --;
}

char* top(St* st) {
    return st -> s[st -> top];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    St fow, bak;
    init(&fow), init(&bak);
    // push(&fow, "http://www.acm.org");
    char current[77] = "http://www.acm.org/";
    char op[11];
    while (1) {
        scanf("%s", op);
        if (op[0] == 'Q') break;
        if (op[0] == 'V') {
            push(&bak, current);
            scanf("%s", current);
            puts(current);
            init(&fow);
        } else if (op[0] == 'F') {
            if (empty(&fow))  puts("Ignored");
            else {
                push(&bak, current);
                strcpy(current, top(&fow));
                pop(&fow);
                puts(current);
            }
        } else if (op[0] == 'B') {
            if (empty(&bak)) puts("Ignored");
            else {
                push(&fow, current);
                strcpy(current, top(&bak));
                pop(&bak);
                puts(current);
            }
        }
    }

    return 0;
}
