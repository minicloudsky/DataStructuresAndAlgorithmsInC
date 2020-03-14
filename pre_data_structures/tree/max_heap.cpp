/*����
����ȫ������ʵ�֣�������洢�����ڵ�Ϊi�������ӽڵ�Ϊ2*i,���ӽڵ�Ϊ2*i+1
ÿ�����Ԫ�ص���ײ�,Ȼ��ӵײ����ϱ������������Ѵ��ֵ������������
ɾ��������СԪ��ʱ�򣬰Ѹ���Ԫ�غ���ײ�Ԫ�ؽ�����Ȼ��Ӹ�����ʼ���µ�����
ÿ��ɾ��ʱ��ɾ��������СԪ�ء�
*/
#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#define eletype int
#define max_data 99999
using namespace std;

typedef struct heap
{
    eletype *arr;
    int size;
    int top;
};

heap h;

void init(heap *h,int len)
{
    h->arr = (eletype*)malloc(len*sizeof(eletype));
    h->size = len;
    h->top = 0;
    h->arr[0] = max_data;
}

void up(eletype x)
{
    for(int i = x;h.arr[i] > h.arr[i/2];i/=2)
        swap(h.arr[i],h.arr[i/2]);
}

void down(eletype x)
{
    int i,child;
    for(i = x;i<h.top-1;i = child)
    {
        child = 2*i;
        if(child>h.top)
            break;
        //�Ƚ��ҳ������ӽڵ�ڵ�
        if(child<=h.top-1&&h.arr[child+1]>h.arr[child])
            child++;
        //����ӽڵ�ȸ��ڵ�󣬾ͽ���
        if(h.arr[child]>h.arr[i])
            swap(h.arr[child],h.arr[i]);
        else
            break;
    }
}

void insert(eletype x)
{
    //����ȫ������β�������½ڵ�
    h.arr[++h.top] = x;
    //��top�ڵ����ϱ���������ӽڵ�ȸ��ڵ�󣬾ͽ����ӽڵ�͸��ڵ�
    up(h.top);
}

int empty()
{
    return h.top ==0;
}

eletype get_max()
{
    eletype m = h.arr[1];
    //���ӽڵ�͸��ڵ㽻��
    swap(h.arr[1],h.arr[h.top]);
    h.top--;
    //�Ӹ��ڵ����±���������ӽڵ�ȸ��ڵ�󣬾Ͱ��ӽڵ����������
    down(1);
    return m;
}

int main()
{
    int n;
    eletype x;
    cin>>n;
    init(&h,n);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert(x);
    }

    while(empty()==0)
    {
        cout<<get_max()<<endl;
    }

    return 0;
}
