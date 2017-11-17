#include<iostream>
#include<cstdlib>
using namespace std;
//合并两个数组
void Merge(int *a,int *temp,int start,int mid,int end)
{
    // i指向第一个数组第一个元素，j指向第二个数组第一个元素，k用来标记temp数组
    int i = start,j = mid+1,k = start;
    while(i!=mid+1&&j!=end+1)
    {
        //第一个数组元素比第二个数组元素大，就把第二个数组元素复制到temp数组
        if(a[i]>a[j])
            temp[k++] = a[j++];
        else
            temp[k++] = a[i++];
    }
    //把第一个数组剩余元素赋值到temp
    while(i!=mid+1)
        temp[k++] = a[i++];
    //把第二个数组元素复制到temp
    while(j!=end+1)
        temp[k++] = a[j++];
    //把合并后的temp数组还原复制到a数组
    for(i = start;i<=end;i++)
        a[i] = temp[i];
}
void MergeSort(int *a,int start,int end)
{
    int mid;
    int *temp = (int*) malloc((end-start+1)*sizeof(int));
    if(start<end)
    {
        mid = (start+end)/2;
        //递归地将a数组分为多个子数组，然后再合并
        //对左一半数组归并排序
        MergeSort(a,start,mid);
        //对右一半数组归并排序
        MergeSort(a,mid+1,end);
        //合并左右数组
        Merge(a,temp,start,mid,end);
    }
}
int main()
{
    int *a,n;
    cin>>n;
    a = (int*) malloc((n+1)*sizeof(int));
    for(int i=0;i<n;i++)
        cin>>a[i];
    MergeSort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    free(a);
    cout<<endl;
    return 0;
}
