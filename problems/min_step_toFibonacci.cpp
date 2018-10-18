#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;
int fib(int n)
{
    if(n<=1)
        return 1;
    else if(n==2){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
int is_fib(int num)
{
    int a[31];
    int position;
    int step = 0,left,right;
    for(int i=1;i<=30;i++){
        a[i] = fib(i);
    }
    for(int i=1;i<=30;)
    {
        if(num==a[i])
            return 0;
        if(num>a[i]&&num<a[i+1])
            position = i+1;
        if(i==30 && num>a[i])
            return num - a[i];
        i++;
    }
    left = fabs(num - a[position-1]);
    right = fabs(a[position] - num);

    return left < right ? left: right;
}

int main()
{
    int list[31];
    int num;
    scanf("%d",&num);
    printf("%d\n",is_fib(num));
    return 0;
}
