#include<stdio.h>
void insert_sort(int *arr,int n)
{
    int i,j,temp;
    //从1开始遍历到数组结束
    for(i=1;i<n;i++)
    {
        //保存第i个元素
        temp = arr[i];
        //
        for(j= i;j>0&&arr[j-1]>temp;j--)
            arr[j] = arr[j-1];//将数组后一个值赋值给前一个
        arr[j] = temp;
    }
}
int main()
{
    int arr[6] = {324,-9,46,33,-90,12};
    insert_sort(arr,6);
    for(int i=0;i<6;i++)
        printf("%d\n",arr[i]);
}
