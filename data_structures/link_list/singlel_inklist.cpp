//
// Created by jia on 2020/2/11.
//
#include <cstdio>
#include <cstdlib>

typedef struct node {
    int data;
    node *next;
};

node *add(node *head, int value) {
    node *p, *q = head; // p为新增节点，q用来暂时存放head，用于遍历
    p = (node *) malloc(sizeof(node));
    if (p == NULL) {
        printf("allocate memory error");
        exit(-1);
    } else {
        if (head == NULL) {
            head = p;
        } else {
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = p;
        }
        p->data = value;
        p->next = NULL;
    }

    return head;
}

void echo(node *head) {
    while (head) {
        printf("%p %d \n", head, head->data);
        head = head->next;
    }
}

node *insertByIndex(node *head, int index, int value) {
    node *p = head, *q;
    if (index < 0) {
        printf("insert position must great than 0");
    }
    int count = 0;
    while (index > count && p->next) {
        p = p->next;
        count++;
    }
    if (count == index) {
        q = (node *) malloc(sizeof(node));
        if (q == NULL) {
            printf("allocate memory error");
            exit(0);
        }
        q->next = p->next;
        p->next = q;
        q->data = value;
        return head;
    } else {
        printf("insert error");
        exit(0);
    }
}

//node    *delete(node *head, int value) {
//    node *p = head, *q = NULL;
//    if (head == NULL) {
//        return head;
//    }
//    while (p->next != NULL && p->next->data != value) {
//        p = p->next;
//    }
//    q = p->next;
//    p->next = q->next;
//    free(q);
//
//    return head;
//}

node *reverseList(node *head) {
    if (NULL == head || NULL == head->next)
        return head;
    node *p = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return p;
}


node *revert(node *head) {
    // 1 2 3 4 5
    node *p = head, *q = NULL;
}

//int main() {
//    node *head = NULL, *p = NULL, *q = NULL;
//    for (int i = 0; i < 10; i++) {
//        head = add(head, i);
//    }
//    //head = insertByIndex(head, 0, 111);
//    //echo(head);
//    //printf("after insert\n");
////    echo(head);
////    head = delete (head, 5);
////    printf("after delete\n");
////    echo(head);
//    head = reverseList(head);
//    echo(head);
//
//    return 0;
//}
