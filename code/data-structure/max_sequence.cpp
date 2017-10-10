#include<stdio.h>
#include<algorithm>
using namespace std;

struct node
{
    int x;
    int yy;
    double ss;
};

int main()
{
    int f=-1;
    unsigned int x=9;
    printf("%d\n%d\n",sizeof(f),sizeof(x));
    if(-1>sizeof(f)){
        printf("yes\n");
    }

    return 0;
}

/*
int MaxSubSequenceSum(const int a[],int N)
{
    int ThisSum,MaxSum,i,j,k;
    MaxSum = 0;
    for(i=0;i<N;i++)
    {
        for(j=i;j<N;j++)
        {
            ThisSum = 0;
            for(k=i;k<=j;k++)
            {
                ThisSum +=a[k];
            }
            if(ThisSum >MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}
int main()
{
    int arr[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int sum = MaxSubSequenceSum(arr,n);
    printf("%d \n",sum);
    return 0;
}
*/
