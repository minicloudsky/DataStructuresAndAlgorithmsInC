#include<iostream>
#include<algorithm>
#define Stack_SIZE 50
using namespace std;
typedef struct MyStack
{
    int st[Stack_SIZE];
    int top;
};
void InitStack(MyStack *s)
{
    s->top = -1;
}
int Push(MyStack *s,int x)
{
    if(s->top ==Stack_SIZE)
        return false;
    s->top++;
    s->st[s->top]=x;
    return true;
}
int Pop(MyStack *s,int *x)
{
    if(s->top==-1)
        return false;
    else{
        *x = s->st[s->top];
        s->top--;
        return true;
    }
}
int main()
{
    MyStack *s;
    s->
    int num;
    return 0;
}
