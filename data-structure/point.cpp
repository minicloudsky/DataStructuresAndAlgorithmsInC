#include<stdio.h>
int swap(int &a,int &b)
{
    int *p;
    p = a;
    a = b;
    b = p;
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);

    return 0;
}
