#include<stdio.h>
int PrintDigit(int x)
{
    if(x>10)
    {
        PrintDigit(x/10);
    }
    else
    {
        printf("%d\n",x%10);
    }
}
int main()
{
    int x;
    PrintDigit(33);
    return 0;
}
