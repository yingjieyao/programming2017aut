// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  A.c
//
// Description:
//
// Version:  1.0
// Created:  2017年11月02日 20时53分34秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>
#include <stdlib.h>

// 定义栈的最大容量是100
#define maxn 100
#define ERROR -1

typedef struct stack {
    int arr[maxn];
    int top;
}Stack;


// 如果栈满了，返回1; 否则返回0
int full(Stack* stk) {
    return stk-> top == maxn - 1;
}

// 压栈,　如果栈满了，返回ERROR；否则返回1
int push(Stack* stk, int val) {
    if (full(stk)) {
        return ERROR;
    }
    stk->arr[++stk->top] = val;
    return 1;
}

// 判断栈是否是空，空返回1,否则返回-1
int empty(Stack* stk) {
    return stk -> top == -1;
}

// 返回栈顶元素
int top(Stack* stk) {
    if (empty(stk)) {
        return ERROR;
    }
    return stk -> arr[stk->top];
}

// 将栈顶元素弹出
int pop(Stack* stk) {
    if (empty(stk)) {
        return ERROR;
    }
    stk -> top --;
    return 1;
}

int main() {
    Stack stk;
    stk.top = -1;
    push(&stk, 1);
    push(&stk, 2);
    pop(&stk);
    printf("%d\n", top(&stk));
    return 0;
}
