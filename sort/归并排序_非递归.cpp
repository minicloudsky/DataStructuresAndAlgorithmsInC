#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
//lowΪ���ζ�·�鲢����ĵ�1�������ĵ�1��Ԫ�أ�iָ���1��Ԫ��, midΪ��1�����������1��Ԫ��
void merge(int List[], int low, int mid, int high)
{
    //mid+1Ϊ��2��������1��Ԫ�أ�midΪ��1�����������1��Ԫ��
    //i ָ��� 1 �������ĵ� 1 ��Ԫ��
    int i = low;
    //j ָ��� 2 �������ĵ� 1 ��Ԫ�أ�high Ϊ�� 2 �����������һ��Ԫ��
    int j = mid + 1;
    //temp�����ݴ�ϲ�����������
    int *temp = new int[high - low + 1];
    //������ʱ�����ָʾ��־ k
    int k = 0;
    //�ڴ����ʧ��
    if(!temp){
        cout<<"�������ʧ�ܣ�";
        exit(0);
    }
    //˳��ѡȡ�����������Ľ�СԪ�أ��洢��t�����У���Ϊ�ǵ�������
    while(i<=mid&&j<high){
        if(List[i] <= List[j]){
            temp[k++] = List[i++];
        }else{
            temp[k++] = List[j++];
        }
    }
    //����֮�󣬼����1������������ʣ�࣬��ֱ��ȫ�����Ƶ� temp ����
    while(i <= mid){
        temp[k++] = List[i++];
    }
    //����֮�󣬼����2������������ʣ�࣬��ֱ��ȫ�����Ƶ� temp ����
    while(j <= high){
        temp[k++] = List[j++];
    }
    for(i = low, k = 0; i <= high; i++, k++){
        List[i] = temp[k];
    }
    delete []temp;
}
//�ǵݹ��㷨ʵ�ֶ�·�鲢����length�������鳤�ȣ�����������±��� legth - 1
void mergeSort(int List[],int length)
{
    //����ͼ��Ĺ��̣���·�鲢�㷨�����̣���ͬ�ڵݹ飬�ݹ����ȵݹ���䣬Ȼ��鲢������
    //�����鲢�����ǵ���ִ�У��͵ݹ麯��ִ��˳���෴��
    int size = 1;
    int low,mid,high;
    //size �Ǳ�ǵ�ǰ�����鲢���е�high-low����1��2��4��8��������2*size
    while(size <= length - 1){
        //�ӵ�һ��Ԫ�ؿ�ʼɨ�裬low�����һ���ָ�����еĵ�һ��Ԫ��
        low = 0;
        //��ǰ�Ĺ鲢�㷨����������
        while(low + size <= length - 1){
            //mid�����һ���ָ�����е����һ��Ԫ��
            mid = low + size - 1;
            //high ����ڶ����ָ�����е����һ��Ԫ��
            high = mid + size;
            //�ж�һ�£�����ڶ������и�������size��
            if(high > length - 1){
                //���� high Ϊ���һ��Ԫ�ص��±꼴��
                high = length - 1;
            }
            //���ù鲢���������зָ�����еķֶ�����
            merge(List, low, mid, high);
            //��ӡ��ÿ�ι鲢������
            cout << "low:" << low << " mid:" << mid << " high:" << high << endl;
            //��һ�ι鲢ʱ��һ���еĵ�һ��Ԫ��λ��
            low = high + 1;
        }
        //��Χ����һ������·�鲢�Ĺ���
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
