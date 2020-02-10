#include<stdio.h>
int main()
{
    int bucket[1001],i,j,t,n;
    for(i=0;i<=1000;i++)
        bucket[i] = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        //把数字放入桶里面
        bucket[t]++;
    }
    for(i = 0;i<=1000;i++)
    {
        for(j =1;j<=bucket[i];j++)
            printf("%d ",i);
    }
    return 0;
}
