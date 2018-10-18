#include <stdio.h>
#include <string.h>
#include <malloc.h>
char infix[20] = "1+8-(1/4)";    //��ʼ����׺���ʽ
int top = -1;
char prefix[20];               //���ǰ׺���ʽ
char opstack[20];              //��������
char pop()
{
    return (opstack[top--]);
}
void push(char symbol)
{
    opstack[++top] = symbol;
}
int isopr(char s)
{
    if(s == '+' ||  s == '-' ||  s == '*' ||  s == '/' )
    {
        return 1;
    }else return 0;
}
int prcd(char s)              //��������ȼ��ж�
{
    switch(s)
    {
        case '+':return 1;break;
        case '-':return 1;break;
        case '*':return 2;break;
        case '/':return 2;break;
        case '=':return 0;break;
    }
}
void intopre()
{
    char sym;
    int j = 0;
    opstack[++top] = '=';
    for(int i=strlen(infix)-1; i>=0 ; i--)
    {
        sym = infix[i];
        if(isopr(sym) == 0)      //����������ֱ��ѹ��prefix
        {
            prefix[j] = sym;
            j++;
        }else     //else1
        {
            if(sym == ')')          //���������ţ�����ѹջ
            {
                push(sym);
            }else if(sym == '(')      //���������ţ� �����ε���stackջ�������������ѹ��prefix��ֱ������������Ϊֹ
            {
                while(opstack[top] != ')')
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
            }else if(prcd(sym) >= prcd(opstack[top]))    //��������������ȼ�����ջ�������������ѹջ
            {
                push(sym);
            }else                                     //��������������ȼ�С��ջ�������
            {
                while( prcd(sym) < prcd(opstack[top]) )
                {
                    prefix[j] = pop();
                    j++;
                }
            }
        }//else1����
    }//forѭ������
}
int main(void)
{
    intopre();
    printf("%s",prefix);
    return 0;
}
