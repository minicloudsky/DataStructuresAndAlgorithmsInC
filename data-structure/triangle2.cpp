/*
   1
  121
 12421
1248421
2**n-1
*/
#include<stdio.h>
int my(int n)
{
    int i=1,p=1;
    for(i=1;i<n;i++)
    {
        p=2*p;
    }
    return p;
}
int main()
{
    int i,j,k,p,num;
    while(scanf("%d",&num)!=0)
    {
        printf("%d\n",my(num));
    }
    return 0;
}
