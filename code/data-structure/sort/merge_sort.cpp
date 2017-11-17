#include <stdlib.h>
#include <stdio.h>
//��·һ�ι鲢���̵��㷨
//lowΪ���ζ�·�鲢����ĵ�1�������ĵ�1��Ԫ�أ�iָ���1��Ԫ��, midΪ��1�����������1��Ԫ��
void Merge(int a[],int temp[],int start, int mid, int end)
{
    // mid+1Ϊ�ڶ�����������һ��Ԫ��,midΪ��һ�������������һ��Ԫ��
    int i = start, j=mid+1, k = start;
    while(i!=mid+1 && j!=end+1)
    {
        //�ҳ�a��b������С��ֵ���Ƶ�a����
        if(a[i] > a[j])
            temp[k++] = a[j++];
        else
            temp[k++] = a[i++];
    }
     //����֮�󣬼����1������������ʣ�࣬��ֱ��ȫ�����Ƶ� temp ����
    while(i != mid+1)
        temp[k++] = a[i++];
    //����֮�󣬼����2������������ʣ�࣬��ֱ��ȫ�����Ƶ� temp ����
    while(j != end+1)
        temp[k++] = a[j++];
    //���ź�������У��ش�ص� list �� low �� high ����
    for(i=start; i<=end; i++)
        a[i] = temp[i];
}
//�ݹ�ؽ�����������ָ��һ����С�����������Ȼ���ٺϲ�
void MergeSort(int a[],int start, int end)
{
    int *temp = (int*) malloc((end-start)*sizeof(int));
    int mid;
    if(start < end)
    {
        mid = (start + end) / 2;
        MergeSort(a, start, mid);
        MergeSort(a, mid+1, end);
        Merge(a, temp, start, mid, end);//�ϲ�a��temp����
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
