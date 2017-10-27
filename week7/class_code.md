```C
#include <stdio.h>
#include <stdlib.h> /*header file for function malloc and free*/

struct node {
    int val;
    struct node* next;
};

#define Node struct node


// 打印链表，非递归形式
void print_list(Node* head) {
    while (head) {
        printf("%d ", head -> val);
        head = head -> next;
    }
    printf("\n");
}

// 打印链表，递归形式
void print_list_rec(Node* head) {
    if (head == NULL) return;
    printf("%d ", head -> val);
    print_list_rec(head -> next);
}

// 向头节点为head的有序链表中插入值为val的节点，返回新链表的头结点
// 并且使得新链表依然有序
Node* insert_list(Node* head, int val) {
    Node* cur = (Node*)malloc(sizeof(Node));
    // 如果malloc的返回值是NULL的话，表示分配空间错误
    // 程序直接停止即可
    if (cur == NULL) {
        printf("ERROR, no enough space\n");
        exit(0);
    }
    cur -> next = NULL;
    cur -> val = val;

    // 如果链表里面什么都没有，那么新的链表的头结点应该是当前节点cur
    if (head == NULL) return cur;

    // 如果val要比头节点的值小，那么cur应该是新的链表的头结点
    if (head -> val > val) {
        cur -> next = head;
        return cur;
    }

    // 保存现在的头结点
    Node *phead = head;

    // 找到第一个可以插入的位置
    while (head -> next != NULL && head -> next -> val < val) head = head -> next;

    // 插入cur
    cur -> next = head -> next;
    head -> next = cur;

    return phead;
}

// 释放刚才申请的空间
void destroy_list(Node* head) {
    if (head == NULL) return;
    destroy_list(head -> next);
    free(head); // 释放head所指向的那块内存
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        Node *head = NULL;
        int val, i;
        for (i = 0; i < n; ++i) {
            scanf("%d", &val);
            head = insert_list(head, val);
        }
        // 打印排好序的链表
        print_list(head);

        // 释放空间
        destroy_list(head);
    }
    return 0;
}
```