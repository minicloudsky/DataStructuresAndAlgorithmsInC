#include<cstdio>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
int IsEmpty()
{
    return S->Next === NULL;
}
Stack CreateStack(void)
{
    Stack S;
    S = (Stack*)malloc(sizeof(struct Node));
    if(S ==NULL)
        FatalError();
}
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(int X,Stack S);
int Top(Stack S);
struct Node
{
    int Element;
    PtrToNode Next;
};
int main()
{
    return 0;
}
