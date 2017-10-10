/* 1
  121
 12421
1248421
2**n-1
*/
#include<stdio.h>
#include<iostream>
using namespace std;
int my(int n){
    int i=1,p=1;
    for(i=1;i<n;i++)
        p=2*p;
    return p;
}
int main()
{
    int num;
    while(scanf("%d",&num)!=0)
    {
       for(int i=1;i<=num;i++)
       {
           for(int j=num-i;j>=1;j--)
            printf(" ");
           for(int k=1;k<=i;k++)
            printf("%d",my(k));
           for(int k=i-1;k>=1;k--)
            printf("%d",my(k));
           printf("\n");
       }
    }
    return 0;
}
