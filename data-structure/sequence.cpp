#include<stdio.h>
int subSeq(int *arr,int n)
{
    int this_sum=0,sum=0;
    for(int i=0;i<n;i++)
    {
        sum +=arr[i];
        if(this_sum>sum)
        {
            sum = this_sum;
        }
        else if(this_sum <0)
        {
            this_sum = 0;
        }

    }
    return sum;
}
int main()
{
    int arr[6] = {1,-9,2,65,-23,29};
    int s = subSeq(arr,6);
    printf("%d\n",s);
    return 0;
}
