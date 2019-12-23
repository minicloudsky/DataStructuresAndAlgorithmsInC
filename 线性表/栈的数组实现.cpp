#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define Size 1000
#define EleType char
typedef struct Stk
{
    EleType top;
    EleType arr[Size];
};
Stk *InitStk(Stk *S)
{
    S->top = -1;
    return S;
}
void Push(Stk *S,EleType x)
{
    if(S->top==Size-1)
        printf("Stack is full.\n");
    else
    {
        S->top++;
        S->arr[S->top] = x;
    }
}
EleType Pop(Stk *S)
{
    EleType x;
    if(S->top==-1)
        printf("Stack is empty.\n");
    else
    {
        x = S->arr[S->top];
        S->top--;
    }
    return x;
}
EleType getTop(Stk *S)
{
    return S->arr[S->top];
}
int IsEmpty(Stk *S)
{
    return S->top == -1;
}
void MakeEmpty(Stk *S)
{
    S->top = -1;
}
void DisPoseStack(Stk *S)
{
    if(S!=NULL)
    {
        free(S->arr);
        free(S);
    }
}
int main()
{
    Stk *S = (Stk*) malloc(sizeof(Stk));
    S = InitStk(S);
    return 0;
}
