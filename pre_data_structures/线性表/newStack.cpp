/*
后缀表达式(逆波兰式)求值
从左向右扫描字符串
如果是数字，压入栈
如果是运算符，取出栈中数据，进行运算，运算后将结果入栈
循环遍历，直到遍历完所有表达式
*/
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
int compute(int first,int second,char com)//运算
{
    if(com=='+')
        return first+second;
    if(com=='*')
        return first*second;
    if(com=='-')
        return first-second;
    if(com =='/')
        return first/second;
}
int main()
{
    char prefix[100] = "34+5*6-";//后缀表达式
    int first,second;
    int len = strlen(prefix)-1;
    Stk *S = (Stk*) malloc(sizeof(Stk));//申请内存
    S = InitStk(S);
    int answer = 0;
    int count = 0;//计算运算次数
    for(int i = 0;i<=len;i++)
    {
        if(prefix[i]>=48&&prefix[i]<=57)// 0-9 数字压入栈
        {
            Push(S,prefix[i]-48);//记得-48，把字符串穿转化为数字
        }
        if((prefix[i]=='+') || (prefix[i]=='-') || (prefix[i]=='*') || (prefix[i]=='/'))
        {
            first = Pop(S);
            second = Pop(S);
            printf("first is %d\nSecond is %d\n",first,second);
            answer = compute(second,first,prefix[i]);
            Push(S,answer);//将计算后的数值压入栈
            printf("第%d 次运算后的答案为: %d 此时压入栈的是 %d\n",++count,answer,getTop(S));
        }
    }
    printf("前缀表达式最终的结果为 %d\n",getTop(S));//此时栈里面的为最终结果
    return 0;
}



