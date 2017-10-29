// Copyright (c) 2017 , yogurt.yyj.
// All rights reserved.
//
// Filename:  B.c
//
// Description:
//
// Version:  1.0
// Created:  2017年10月27日 20时41分33秒
// Compiler:  g++
//
// Author:  yogurt (yyj), yyjhit@sina.com
//


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node node;
struct Node {
    int x;
    node* next;
};

node* quick_sort_list(node* head) {
    if (!head) return NULL;
    node *low = NULL, *high = NULL;
    node *equ = NULL;
    int val = abs(head -> x);
    while (head) {
        node *tmp = head -> next;
        if (abs(head -> x) > val) {
            if (high == NULL) {
                high = head;
                high -> next = NULL;
            } else {
                head -> next = high -> next;
                high -> next = head;
            }
        } else if(abs(head->x) < val){
            if (low == NULL) {
                low = head;
                low -> next = NULL;
            } else {
                head -> next = low -> next;
                low -> next = head;
            }
        } else {
            if (equ == NULL) {
                equ = head;
                equ -> next = NULL;
            } else {
                head -> next = equ -> next;
                equ -> next = head;
            }
        }
        head = tmp;
    }

    low = quick_sort_list(low);
    high = quick_sort_list(high);

    if (low) head = low;
    else if (equ) head = equ;
    else head = high;

    while (low && low -> next) low = low -> next;
    if (low && equ) low -> next = equ;
    else if (low) low -> next = high;

    while (equ && equ -> next) equ = equ -> next;
    if (equ) equ -> next = high;

    return head;
}

void print_list(node *head) {
    if (!head) return;
    print_list(head -> next);
    printf("%d ", head -> x);
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n) {
        int d, i;
        node* head = NULL;
        for (i = 0; i < n; ++i) {
            scanf("%d", &d);
            node* cur = (node*)malloc(sizeof(node));
            cur -> x = d;
            cur -> next = NULL;
            if (head == NULL) {
                head = cur;
            } else {
                cur -> next = head -> next;
                head -> next = cur;
            }
        }
        head = quick_sort_list(head);
        print_list(head);
        puts("");
    }
    return 0;
}

