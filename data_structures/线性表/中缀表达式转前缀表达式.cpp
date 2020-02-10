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
    char mid_exp[100] = "1+((2+3)��4)-5";
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
����׺���ʽת��Ϊǰ׺���ʽ��
��ѭ���²��裺
(1) ��ʼ������ջ�������ջ S1 �ʹ����м�����ջ S2��
(2) ��������ɨ����׺���ʽ��
(3) ����������ʱ������ѹ�� S2��
(4) ���������ʱ���Ƚ����� S1 ջ������������ȼ���
(4-1) ��� S1 Ϊ�գ���ջ�������Ϊ������ ��)������ֱ�ӽ����������ջ��Push
(4-2) ���������ȼ���ջ��������Ľϸ߻���ȣ�Ҳ�������ѹ�� S1��
(4-3) ���򣬽� S1 ջ���������������ѹ�뵽 S2 �У��ٴ�ת�� (4-1) �� S1 ���µ�ջ���������Ƚϣ�
(5) ��������ʱ��
(5-1) ����������� ��)������ֱ��ѹ�� S1��
(5-2) ����������� ��(���������ε��� S1 ջ�������������ѹ�� S2��ֱ������������Ϊֹ����ʱ����һ�����Ŷ�����
(6) �ظ����� (2) �� (5)��ֱ�����ʽ������ߣ�
(7) �� S1 ��ʣ�����������ε�����ѹ�� S2��
(8) ���ε��� S2 �е�Ԫ�ز�����������Ϊ��׺���ʽ��Ӧ��ǰ׺���ʽ��

*/
