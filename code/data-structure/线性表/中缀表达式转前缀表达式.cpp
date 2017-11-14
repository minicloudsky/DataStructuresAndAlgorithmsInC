#include<cstdio>
#include<cstdlib>
#include<string.h>
#define element char
#define Size 100
typedef struct Stk
{
    element arr[Size];
    int top;
};
Stk *Init(Stk *S)
{
    S->top = -1;
    return S;
}
void Push(Stk *S,int x)
{
    if(S->top == Size-1)
        printf("Stack is full.\n");
    else
    {
        S->top++;
        S->arr[S->top] = x;
    }
}
element Pop(Stk *S)
{
    element x;
    if(S->top ==-1)
        printf("Stack is empty.\n");
    else
    {
        x = S->arr[S->top];
        S->top--;
    }
    return x;
}
int IsEmpty(Stk *S)
{
    return S->top ==-1;
}
int getTop(Stk *S)
{
    return S->arr[S->top];
}

int compare_operator(char op1,char op2)
{
    switch(op1)
    {
        case '+': case '-':
        {
            return (op2 =='*' || op2=='/' ? -1:0);
        }
        case '*': case '/':
        {
            return (op2 == '+' || op2 == '-' ? 1:0);
        }
    }
    return 1;
}
int main()
{
    char s1 = '*';
    char s2 = '+';
    printf("%d\n",compare_operator(s1,s2));
    Stk *S1 = (Stk*) malloc(sizeof(Stk));
    Stk *S2 = (Stk*) malloc(sizeof(Stk));
    S1 = Init(S1);
    S2 = Init(S2);
    char mid_exp[100] = "1+((2+3)×4)-5";
    int len = strlen(mid_exp);
    for(int i=len;i>=0;i--)
    {
        if(mid_exp[i]>=48 && mid_exp[i]<=57)
            Push(S2,mid_exp[i]);
        if(mid_exp[i] == '+'|| mid_exp[i] =='-' || mid_exp[i]=='*' || mid_exp[i] =='/')
        {
            if((IsEmpty(S1)) || (getTop(S1)==')'))
                Push(S1,mid_exp[i])
            else if ()
        }
    }
    return 0;
}
/*
将中缀表达式转换为前缀表达式：
遵循以下步骤：
(1) 初始化两个栈：运算符栈 S1 和储存中间结果的栈 S2；
(2) 从右至左扫描中缀表达式；
(3) 遇到操作数时，将其压入 S2；
(4) 遇到运算符时，比较其与 S1 栈顶运算符的优先级：
(4-1) 如果 S1 为空，或栈顶运算符为右括号 “)”，则直接将此运算符入栈；Push
(4-2) 否则，若优先级比栈顶运算符的较高或相等，也将运算符压入 S1；
(4-3) 否则，将 S1 栈顶的运算符弹出并压入到 S2 中，再次转到 (4-1) 与 S1 中新的栈顶运算符相比较；
(5) 遇到括号时：
(5-1) 如果是右括号 “)”，则直接压入 S1；
(5-2) 如果是左括号 “(”，则依次弹出 S1 栈顶的运算符，并压入 S2，直到遇到右括号为止，此时将这一对括号丢弃；
(6) 重复步骤 (2) 至 (5)，直到表达式的最左边；
(7) 将 S1 中剩余的运算符依次弹出并压入 S2；
(8) 依次弹出 S2 中的元素并输出，结果即为中缀表达式对应的前缀表达式。

*/
