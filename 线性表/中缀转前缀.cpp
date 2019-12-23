#include <stdio.h>
#include <string.h>
#include <malloc.h>
char infix[20] = "1+8-(1/4)";    //初始化中缀表达式
int top = -1;
char prefix[20];               //存放前缀表达式
char opstack[20];              //存放运算符
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
int prcd(char s)              //运算符优先级判断
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
        if(isopr(sym) == 0)      //遇到操作数直接压入prefix
        {
            prefix[j] = sym;
            j++;
        }else     //else1
        {
            if(sym == ')')          //遇到右括号，将其压栈
            {
                push(sym);
            }else if(sym == '(')      //遇到左括号， 则依次弹出stack栈顶的运算符，并压入prefix，直到遇到右括号为止
            {
                while(opstack[top] != ')')
                {
                    prefix[j] = pop();
                    j++;
                }
                pop();
            }else if(prcd(sym) >= prcd(opstack[top]))    //遇到运算符，优先级大于栈顶运算符，将其压栈
            {
                push(sym);
            }else                                     //遇到运算符，优先级小于栈顶运算符
            {
                while( prcd(sym) < prcd(opstack[top]) )
                {
                    prefix[j] = pop();
                    j++;
                }
            }
        }//else1结束
    }//for循环结束
}
int main(void)
{
    intopre();
    printf("%s",prefix);
    return 0;
}
