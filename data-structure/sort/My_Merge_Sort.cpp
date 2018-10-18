#include<iostream>
#include<cstdlib>
using namespace std;
//�ϲ���������
void Merge(int *a,int *temp,int start,int mid,int end)
{
    // iָ���һ�������һ��Ԫ�أ�jָ��ڶ��������һ��Ԫ�أ�k�������temp����
    int i = start,j = mid+1,k = start;
    while(i!=mid+1&&j!=end+1)
    {
        //��һ������Ԫ�رȵڶ�������Ԫ�ش󣬾Ͱѵڶ�������Ԫ�ظ��Ƶ�temp����
        if(a[i]>a[j])
            temp[k++] = a[j++];
        else
            temp[k++] = a[i++];
    }
    //�ѵ�һ������ʣ��Ԫ�ظ�ֵ��temp
    while(i!=mid+1)
        temp[k++] = a[i++];
    //�ѵڶ�������Ԫ�ظ��Ƶ�temp
    while(j!=end+1)
        temp[k++] = a[j++];
    //�Ѻϲ����temp���黹ԭ���Ƶ�a����
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
        //�ݹ�ؽ�a�����Ϊ��������飬Ȼ���ٺϲ�
        //����һ������鲢����
        MergeSort(a,start,mid);
        //����һ������鲢����
        MergeSort(a,mid+1,end);
        //�ϲ���������
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
