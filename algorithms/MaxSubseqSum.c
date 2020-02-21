#include <stdio.h>

/**
 * 最大连续子序列和
 *
 * 
 */
int MaxSubseqSum(int A[],int N)
{
    int ThisSum,MaxSum;
    int i;
    int index[1000]= {};
    int j = 0;
    ThisSum=MaxSum=0;
    for(i=0;i<N;i++){
        ThisSum +=A[i];
        if(ThisSum>MaxSum){
            MaxSum=ThisSum;
            index[j++];
        } else if(ThisSum < 0){
            ThisSum=0;
        }
    }
    for(int k=0;k<j;k++){
        printf("%d\n",index[k]);
    }
    return MaxSum;
}

int main()
{
    int A[] = {4,-5,12,4,-23,45,6,8};
    printf("%d\n", MaxSubseqSum(A,8));

    return 0;
}

