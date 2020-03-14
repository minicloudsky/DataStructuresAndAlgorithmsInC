/*最大堆
用完全二叉树实现，用数组存储，根节点为i，则左子节点为2*i,右子节点为2*i+1
每次添加元素到最底部,然后从底部向上遍历调整树，把大的值交换到根部，
删除根部最小元素时候，把根部元素和最底部元素交换，然后从根部开始向下调整，
每次删除时候删除根部最小元素。
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
        //比较找出左右子节点节点
        if(child<=h.top-1&&h.arr[child+1]>h.arr[child])
            child++;
        //如果子节点比根节点大，就交换
        if(h.arr[child]>h.arr[i])
            swap(h.arr[child],h.arr[i]);
        else
            break;
    }
}

void insert(eletype x)
{
    //在完全二叉树尾部插入新节点
    h.arr[++h.top] = x;
    //从top节点向上遍历，如果子节点比根节点大，就交换子节点和根节点
    up(h.top);
}

int empty()
{
    return h.top ==0;
}

eletype get_max()
{
    eletype m = h.arr[1];
    //将子节点和根节点交换
    swap(h.arr[1],h.arr[h.top]);
    h.top--;
    //从根节点向下遍历，如果子节点比根节点大，就把子节点调整到根部
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
