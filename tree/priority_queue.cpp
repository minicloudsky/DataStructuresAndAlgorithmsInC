//调整一次树的位置，就要判断下影响，需不需要上浮或下降
//最小堆，注意调整位置，注意是向下调整还是向上调整
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
    //将子节点和根节点比较，比根节点小就交换
    for(int i = x;i>1&&h.arr[i]<h.arr[i/2];i/=2)
        swap(h.arr[i],h.arr[i/2]);
}
void down(int x)
{
    int child,i;
    //child保存树左节点
    for(i = x;i<h.top-1;i = child){
        child = 2*i;
        if(child > h.top)
            break;
        //如果右节点小于左节点，将右节点和根节点比较，找出最小的进行交换
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
    //插入新值以后，调整位置，需要将新节点与以上根节点比较，所以up()
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
    //删除根节点:将根节点和尾部节点交换，然后从根节点开始下降，调整树下降
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
