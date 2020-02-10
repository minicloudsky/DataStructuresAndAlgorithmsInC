//����һ������λ�ã���Ҫ�ж���Ӱ�죬�費��Ҫ�ϸ����½�
//��С�ѣ�ע�����λ�ã�ע�������µ����������ϵ���
#include<iostream>
#include<stdlib.h>
#define mindata -99
using namespace std;
typedef struct heap
{
  int *arr;
  int top;
  int size;
};
heap h;
heap init(heap *h,int len)
{
    h->arr = (int*) malloc(len*sizeof(int));
    h->size = len;
    h->top = 0;
    h->arr[0] = mindata;
}
void up(int x)
{
    //���ӽڵ�͸��ڵ�Ƚϣ��ȸ��ڵ�С�ͽ���
    for(int i = x;i>1&&h.arr[i]<h.arr[i/2];i/=2)
        swap(h.arr[i],h.arr[i/2]);
}
void down(int x)
{
    int child,i;
    //child��������ڵ�
    for(i = x;i<h.top-1;i = child){
        child = 2*i;
        if(child > h.top)
            break;
        //����ҽڵ�С����ڵ㣬���ҽڵ�͸��ڵ�Ƚϣ��ҳ���С�Ľ��н���
        if(child <= h.top-1&&h.arr[child+1]<h.arr[child])
            child++;
        if(h.arr[child]< h.arr[i]){
            swap(h.arr[child],h.arr[i]);
        }
        else
            break;
    }
}
void insert(int x)
{
    h.arr[++h.top] = x;
    //������ֵ�Ժ󣬵���λ�ã���Ҫ���½ڵ������ϸ��ڵ�Ƚϣ�����up()
    up(h.top);
}
int empty()
{
    return h.top==0;
}
int get_min()
{
    int m = h.arr[1];
    swap(h.arr[1],h.arr[h.top]);
    h.top--;
    //ɾ�����ڵ�:�����ڵ��β���ڵ㽻����Ȼ��Ӹ��ڵ㿪ʼ�½����������½�
    down(1);
    return m;
}
int main()
{
    int n,x;
    cin>>n;
    init(&h,n);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert(x);
    }
    while(!empty())
    {
        cout<<get_min()<<endl;
    }
    return 0;
}
