// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  C.c
//
// Description:
//
// Version:  1.0
// Created:  2017年10月27日 21时17分41秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
struct Node {
    int x;
    node* next;
};
int main() {
    int n, d;
    char s[11];
    while (scanf("%d", &n) == 1) {
        node* head = (node*)malloc(sizeof(node));
        while (n--) {
            scanf("%s", s);
            if (s[2] == 'S') {
                scanf("%d", &d);
                node* cur = (node*)malloc(sizeof(node));
                cur -> x = d;
                cur -> next = head -> next;
                head -> next = cur;
            } else if (s[2] == 'E') {
                if (head -> next) printf("%d\n", head -> next-> x);
                else puts("NULL");
            } else {
                if (head -> next) {
                    head -> next = head -> next -> next;
                }
                else puts("I can't do that!");
            }
        }

    }
    return 0;
}

