#include<iostream>
#include<stdio.h>
using namespace std;
//low为本次二路归并排序的第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
void merge(int List[], int low, int mid, int high)
{
    //mid+1为第2有序区第1个元素，mid为第1有序区的最后1个元素
    //i 指向第 1 有序区的第 1 个元素
    int i = low;
    //j 指向第 2 有序区的第 1 个元素，high 为第 2 有序区的最后一个元素
    int j = mid + 1;
    //temp数组暂存合并的有序序列
    int *temp = new int[high - low + 1];
    //设置临时数组的指示标志 k
    int k = 0;
    //内存分配失败
    if(!temp)
        cout<<"数组分配失败！";
    //顺序选取两个有序区的较小元素，存储到t数组中，因为是递增排序
    while(i <= mid && j <= high)
    {
        //较小的元素，存入temp临时数组中
        if(List[i] <= List[j])
            temp[k++] = List[i++];
        else
            temp[k++] = List[j++];
    }// end of while
    //比完之后，假如第1个有序区仍有剩余，则直接全部复制到 temp 数组
    while(i <= mid)
        temp[k++] = List[i++];
    //比完之后，假如第2个有序区还有剩余，则直接全部复制到 temp 数组
    while(j <= high)
        temp[k++] = List[j++];
    //将排好序的序列，重存回到 list 中 low 到 high 区间
    for(i = low, k = 0; i <= high; i++, k++)
        List[i] = temp[k];
    //delete [] 删除动态数组的内存
    delete []temp;
}

//递归实现二路归并排序（也就是分治法的思想）
void mergeSort(int List[], int low, int high)
{
    //二路归并排序，分为二路
    int mid = (low + high) / 2;
    //终止条件，low >= high， 不是while，且不含等号，否则死循环
    if(low < high)
    {
        //递归过程，二路归并排序递归过程
        mergeSort(List, low, mid);
        mergeSort(List, mid + 1, high);
        //归并
        merge(List, low, mid, high);
    }
}
int main(void)
{
    int source[7] = {49, 38, 65, 97, 76, 13, 27};
    mergeSort(source, 0, 6);
    for (int i = 0; i < 7; i++)
        printf(" %d  ", source[i]);
    return 0;
}
