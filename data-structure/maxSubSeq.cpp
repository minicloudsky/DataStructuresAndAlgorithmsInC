#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int MaxSubseqSum4(int a[],int N)
{
    int ThisSum,MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for(i = 0;i<N;i++)
    {
        ThisSum += a[i];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}
int main()
{
    int a[8] = {1,4,-9,23,5,-2,7,14};
    int max = MaxSubseqSum4(a,8);
    printf("%d\n",max);
    return 0;
}
