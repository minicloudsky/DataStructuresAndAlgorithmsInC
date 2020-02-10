#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define stack struct Stack
#define STACK_POP_ERR 42
struct Stack
{
  int val[10];
  int top;
};

bool empty(stack *stk)
{
    return stk->top == 0;
}
void push(stack *stk, int x)
{
  stk->top=stk->top+1;
  stk->val[stk->top]=x;
}
int pop(stack *stk)
{
  if(empty(stk))
    return STACK_POP_ERR;
  else
  {
    stk->top=stk->top-1;
    return stk->val[stk->top+1];
  }
}
int main()
{
  stack stk;
  stk.top=0;
  push(&stk, 3);
  push(&stk, 4);
  push(&stk, 1);
  push(&stk, 9);
  printf("%d ", pop(&stk));
  printf("%d ", pop(&stk));
  printf("%d ", pop(&stk));
  return 0;
}
