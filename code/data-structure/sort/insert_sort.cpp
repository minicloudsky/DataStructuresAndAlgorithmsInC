#include<stdio.h>
void insert_sort(int *arr,int n)
{
    int i,j,temp;
    //��1��ʼ�������������
    for(i=1;i<n;i++)
    {
        //�����i��Ԫ��
        temp = arr[i];
        //
        for(j= i;j>0&&arr[j-1]>temp;j--)
            arr[j] = arr[j-1];//�������һ��ֵ��ֵ��ǰһ��
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
