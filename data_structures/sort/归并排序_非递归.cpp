#include<iostream>
#include<stdlib.h>
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
    if(!temp){
        cout<<"数组分配失败！";
        exit(0);
    }
    //顺序选取两个有序区的较小元素，存储到t数组中，因为是递增排序
    while(i<=mid&&j<high){
        if(List[i] <= List[j]){
            temp[k++] = List[i++];
        }else{
            temp[k++] = List[j++];
        }
    }
    //比完之后，假如第1个有序区仍有剩余，则直接全部复制到 temp 数组
    while(i <= mid){
        temp[k++] = List[i++];
    }
    //比完之后，假如第2个有序区还有剩余，则直接全部复制到 temp 数组
    while(j <= high){
        temp[k++] = List[j++];
    }
    for(i = low, k = 0; i <= high; i++, k++){
        List[i] = temp[k];
    }
    delete []temp;
}
//非递归算法实现二路归并排序，length代表数组长度，即数组最大下标是 legth - 1
void mergeSort(int List[],int length)
{
    //回忆图解的过程，二路归并算法的流程，不同于递归，递归是先递归语句，然后归并函数，
    //这样归并函数是倒序执行（和递归函数执行顺序相反）
    int size = 1;
    int low,mid,high;
    //size 是标记当前各个归并序列的high-low，从1，2，4，8，……，2*size
    while(size <= length - 1){
        //从第一个元素开始扫描，low代表第一个分割的序列的第一个元素
        low = 0;
        //当前的归并算法结束的条件
        while(low + size <= length - 1){
            //mid代表第一个分割的序列的最后一个元素
            mid = low + size - 1;
            //high 代表第二个分割的序列的最后一个元素
            high = mid + size;
            //判断一下：如果第二个序列个数不足size个
            if(high > length - 1){
                //调整 high 为最后一个元素的下标即可
                high = length - 1;
            }
            //调用归并函数，进行分割的序列的分段排序
            merge(List, low, mid, high);
            //打印出每次归并的区间
            cout << "low:" << low << " mid:" << mid << " high:" << high << endl;
            //下一次归并时第一序列的第一个元素位置
            low = high + 1;
        }
        //范围扩大一倍，二路归并的过程
        size *= 2;
    }
}
int main()
{
    int a[6] = {9,7,2,4,5,8};
    mergeSort(a,6);
    for(int i=0;i<6;i++)
        cout<<a[i]<<endl;
    return 0;
}
