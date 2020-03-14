#include<iostream>
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
    if(!temp)
        cout<<"�������ʧ�ܣ�";
    //˳��ѡȡ�����������Ľ�СԪ�أ��洢��t�����У���Ϊ�ǵ�������
    while(i <= mid && j <= high)
    {
        //��С��Ԫ�أ�����temp��ʱ������
        if(List[i] <= List[j])
            temp[k++] = List[i++];
        else
            temp[k++] = List[j++];
    }// end of while
    //����֮�󣬼����1������������ʣ�࣬��ֱ��ȫ�����Ƶ� temp ����
    while(i <= mid)
        temp[k++] = List[i++];
    //����֮�󣬼����2������������ʣ�࣬��ֱ��ȫ�����Ƶ� temp ����
    while(j <= high)
        temp[k++] = List[j++];
    //���ź�������У��ش�ص� list �� low �� high ����
    for(i = low, k = 0; i <= high; i++, k++)
        List[i] = temp[k];
    //delete [] ɾ����̬������ڴ�
    delete []temp;
}

//�ݹ�ʵ�ֶ�·�鲢����Ҳ���Ƿ��η���˼�룩
void mergeSort(int List[], int low, int high)
{
    //��·�鲢���򣬷�Ϊ��·
    int mid = (low + high) / 2;
    //��ֹ������low >= high�� ����while���Ҳ����Ⱥţ�������ѭ��
    if(low < high)
    {
        //�ݹ���̣���·�鲢����ݹ����
        mergeSort(List, low, mid);
        mergeSort(List, mid + 1, high);
        //�鲢
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
