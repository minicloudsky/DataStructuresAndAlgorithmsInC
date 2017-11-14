#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct heap
{
  int *arr;
  int top;
  int size;
};
heap h;
void init(heap *h,int len)
{
    h->arr = (int*)malloc(len*sizeof(int));
    h->top = 0;
    h->size = len;
    h->arr[0] = -9999;
}
void up(int x)
{
    for(int i = x;i>0&&h.arr[i]<h.arr[i/2];i/=2)
        swap(h.arr[i],h.arr[i/2]);
}
void down(int x)
{
    int i,child;
    for(i = x;i<h.top-1;i = child)
    {
        child = 2*i;
        if(child>h.top)
            break;
        if(child<=h.top-1&&h.arr[child+1]<h.arr[child])
            child++;
        if(h.arr[child]<h.arr[i])
            swap(h.arr[child],h.arr[i]);
        else
            break;
    }
}
void insert(int x)
{
    h.arr[++h.top] = x;
    up(h.top);
}
int empty()
{
    return h.top ==0;
}
int getmin()
{
    int x = h.arr[1];
    swap(h.arr[1],h.arr[h.top]);
    h.top--;
    down(1);
    return x;
}
int main()
{
    int n,x;
    int a[6];
    cout<<"请输入元素数量";
    cin>>n;
    init(&h,n);
    cout<<"请输入元素"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert(x);
    }
    for(int i=0;i<6;i++)
        a[i] = getmin();
    cout<<"堆排序后的结果为:"<<endl;
    for(int i=0;i<6;i++)
        cout<<a[i]<<endl;
    return 0;
}
