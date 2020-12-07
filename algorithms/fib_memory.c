#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    if(n<1){
        return 0;
    }
    int memo[n+1];
    memset(memo,0,sizeof(int));
    return helper(memo,n);
}

// remember the sub number already calculated 
int helper(int *memo,int n){
    if(n==1 || n==2) return 1;
    if(memo[n]!=0) return memo[n];
    memo[n] = helper(memo,n-1) + helper(memo,n-2);
    return memo[n];
}

int main()
{
    int i;
    printf("fib %d is %d\n",10,fib(10));
    return 0;
}

