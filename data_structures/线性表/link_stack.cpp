#include<stdio.h>
typedef struct
{
    SLink top;//Õ»¶¥Ö¸Õë
    int length;
}Stack;
void InitStack(Stack &S)
{
    S.top=NULL;
    S.length=0;
}
bool Push(Stack &S,ElemType e)
{
    p = new LNode;
    if(!p){
        return false;
    }
    p->data = e;
    p->next = S.top;
    S.top = p;
    ++S.length;
}
bool Pop(Stack &S,SElemType &e)
{
    if(!S.top)
        return false;
    else{
        e = S.top->data;
        q = S.top;
        S.top = S.top->next;
        --S.length;
        delete q;
        return true;
    }
}
int main()
{
    return 0;
}
