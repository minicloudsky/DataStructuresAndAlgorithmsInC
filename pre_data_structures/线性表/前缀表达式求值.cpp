/*前缀表达式(波兰表达式求值)*/
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
int compute(int first,int second,char com)
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
    char prefix[100]= "-*+3456";//前缀表达式
    int first,second;
    int len = strlen(prefix)-1;
    Stk *S = (Stk*) malloc(sizeof(Stk));//申请内存
    S = InitStk(S);
    int answer = 0;
    int count = 0;//计算运算次数
    for(int i = len;i>=0;i--)
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
            answer = compute(first,second,prefix[i]);
            Push(S,answer);//将计算后的数值压入栈
            printf("第%d 次运算后的答案为: %d 此时压入栈的是 %d\n",++count,answer,getTop(S));
        }
    }
    printf("前缀表达式最终的结果为 %d\n",getTop(S));//此时栈里面的为最终结果
    return 0;
}

// -*+3456

/*
前缀表达式的计算机求值：
从右至左扫描表达式，遇到数字时，将数字压入堆栈，遇到运算符时，
弹出栈顶的两个数，用运算符对它们做相应的计算（栈顶元素 op 次顶元素），并将结果入栈；
重复上述过程直到表达式最左端，最后运算得出的值即为表达式的结果。
例如前缀表达式“- × + 3 4 5 6”：
(1) 从右至左扫描，将6、5、4、3压入堆栈；
(2) 遇到+运算符，因此弹出3和4（3为栈顶元素，4为次顶元素，注意与后缀表达式做比较），
计算出3+4的值，得7，再将7入栈；
(3) 接下来是×运算符，因此弹出7和5，计算出7×5=35，将35入栈；
(4) 最后是-运算符，计算出35-6的值，即29，由此得出最终结果。
*/
