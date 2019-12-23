#include<stdio.h>
#define SIZE 10000
typedef struct sta
{
  int top=0;
  int arr[SIZE];
};
int is_Empty(sta *s)
{
    return s->top==0;
}
int pop(sta *s)
{
    if(is_Empty(s)){
        printf("栈为空，不能出栈\n");
    }
    int x = s->arr[s->top];
    s->top = s->top-1;
    return x;
}
void push(sta *s,int x)
{
    if(s->top!=SIZE-1)
    {
        s->top = s->top+1;
        s->arr[s->top] = x;
    }
    else
        printf("Stack is full");
}
int main()
{
    sta s;
    int num;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&num);
        push(&s,num);
    }
    for(int i=0;i<5;i++)
        printf("%d ",pop(&s));
    return 0;
}
