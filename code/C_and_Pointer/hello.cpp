#include<stdio.h>
void print(int n)
{
    if(n)
    {
        print(n-1);
        printf("%d\n",n);
    }
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    //for(int i=1; i<=n; i++)
       // printf("%d\n",i);
    print(n);
    return 0;
}
