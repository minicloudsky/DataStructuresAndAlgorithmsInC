#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
typedef struct heap
{
    int *arr;
    int size;
    int top;
};
heap h;
void init(heap *h,int len)
{
    h->arr=(int *)malloc(len*sizeof(int));
    h->size=len;
    h->top=0;
    h->arr[0]= -9999;
}
void up(int x)
{
    for(int i=x;i>1&&h.arr[i]<h.arr[i/2];i/=2)
        swap(h.arr[i],h.arr[i/2]);
}
void down(int x)
{
    int child;
    for(int i=x;i<h.top-1;i=child)
    {
        child=i*2;
        if(child>h.top)  break;
        if(child<=h.top-1&&h.arr[child+1]<h.arr[child])
            child++;
        if(h.arr[child]<h.arr[i]){
            swap(h.arr[child],h.arr[i]);
        }else{
            break;
        }
    }
}
void insert(int x)
{
    h.arr[++h.top]=x;
    up(h.top);
}
int get_min()
{
    int min1=h.arr[1];
    swap(h.arr[1],h.arr[h.top--]);
    down(1);
    return min1;
}
int empty()
{
    return (h.top==0);
}
int main()
{
    int n,x;
    cin>>n;
    init(&h,n);
    for(int i=0;i<n;i++){
        cin>>x;
        insert(x);
    }
    while(empty()==0){
        printf("%d\n",get_min());
    }
    return 0;
}

