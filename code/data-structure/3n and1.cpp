#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int step = 0;
    while(n!=1){
        if(n%2==0)
            n=n/2;
        else{
            n = (3*n+1)/2;
        }
        step+=1;
    }
    printf("%d\n",step);
    return 0;
}
