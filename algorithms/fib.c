#include <stdio.h>

int fib(int n){
    if(n<1){
        return 0;
    }
    if(n==1 || n==2){
        return 1;
    }
    int curr=1,prev=1;
    int sum=0;
    int i =3;
    for(i=3;i<=n;i++){
        sum = prev+curr;
        prev = curr;
        curr = sum;
    }
    return curr;
}

int main()
{
    int i;
    for(i=1;i<=30;i++){
        printf("fib %d is %d\n",i,fib(i));
    }
    return 0;
}

