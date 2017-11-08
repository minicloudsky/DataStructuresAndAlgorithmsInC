/*
��׺���ʽ(�沨��ʽ)��ֵ
��������ɨ���ַ���
��������֣�ѹ��ջ
������������ȡ��ջ�����ݣ��������㣬����󽫽����ջ
ѭ��������ֱ�����������б��ʽ
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
int compute(int first,int second,char com)//����
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
    char prefix[100] = "34+5*6-";//��׺���ʽ
    int first,second;
    int len = strlen(prefix)-1;
    Stk *S = (Stk*) malloc(sizeof(Stk));//�����ڴ�
    S = InitStk(S);
    int answer = 0;
    int count = 0;//�����������
    for(int i = 0;i<=len;i++)
    {
        if(prefix[i]>=48&&prefix[i]<=57)// 0-9 ����ѹ��ջ
        {
            Push(S,prefix[i]-48);//�ǵ�-48�����ַ�����ת��Ϊ����
        }
        if((prefix[i]=='+') || (prefix[i]=='-') || (prefix[i]=='*') || (prefix[i]=='/'))
        {
            first = Pop(S);
            second = Pop(S);
            printf("first is %d\nSecond is %d\n",first,second);
            answer = compute(second,first,prefix[i]);
            Push(S,answer);//����������ֵѹ��ջ
            printf("��%d �������Ĵ�Ϊ: %d ��ʱѹ��ջ���� %d\n",++count,answer,getTop(S));
        }
    }
    printf("ǰ׺���ʽ���յĽ��Ϊ %d\n",getTop(S));//��ʱջ�����Ϊ���ս��
    return 0;
}



