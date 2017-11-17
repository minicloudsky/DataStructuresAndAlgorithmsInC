#include <stdlib.h>
#include <stdio.h>
//二路一次归并过程的算法
//low为本次二路归并排序的第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
void Merge(int a[],int temp[],int start, int mid, int end)
{
    // mid+1为第二个有序区第一个元素,mid为第一个有序区的最后一个元素
    int i = start, j=mid+1, k = start;
    while(i!=mid+1 && j!=end+1)
    {
        //找出a，b数组中小的值复制到a数组
        if(a[i] > a[j])
            temp[k++] = a[j++];
        else
            temp[k++] = a[i++];
    }
     //比完之后，假如第1个有序区仍有剩余，则直接全部复制到 temp 数组
    while(i != mid+1)
        temp[k++] = a[i++];
    //比完之后，假如第2个有序区还有剩余，则直接全部复制到 temp 数组
    while(j != end+1)
        temp[k++] = a[j++];
    //将排好序的序列，重存回到 list 中 low 到 high 区间
    for(i=start; i<=end; i++)
        a[i] = temp[i];
}
//递归地将待排序数组分割成一个个小数组进行排序，然后再合并
void MergeSort(int a[],int start, int end)
{
    int *temp = (int*) malloc((end-start)*sizeof(int));
    int mid;
    if(start < end)
    {
        mid = (start + end) / 2;
        MergeSort(a, start, mid);
        MergeSort(a, mid+1, end);
        Merge(a, temp, start, mid, end);//合并a和temp数组
    }
}
int main()
{
   // int a[8] = {1,13,24,26,2,15,27,38};
    int a[6] = {8,3,1,5,4,7};
    int i, b[8];
    MergeSort(a,0, 5);
    for(i=0; i<6; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
