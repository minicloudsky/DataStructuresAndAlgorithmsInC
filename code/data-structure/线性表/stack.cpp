#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 1000
typedef struct My_Stack
{
    int arr[MAX_SIZE];
    int top;
};
bool empty(My_Stack *stk)
{
    return stk->top==0;
}
void push(My_Stack *stk,int x)
{
    stk->top=stk->top+1;
    stk->arr[stk->top]=x;
}
int pop(My_Stack *stk)
{
    if(empty(stk))
        return -1;
    else{
        stk->top = stk->top-1;
        return stk->arr[stk->top+1];
    }
}
int main()
{
    My_Stack stk;
    stk.top=0;
    push(&stk,10);
    push(&stk,12);
    push(&stk,109);
    push(&stk,1243);
    //µ¯³ö3¸ö
    printf("%d ",pop(&stk));
    printf("%d ",pop(&stk));
    printf("%d ",pop(&stk));
    return 0;
}
