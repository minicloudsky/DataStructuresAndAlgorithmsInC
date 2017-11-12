#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define minsize 100
#define mindata -1000
using namespace std;
typedef struct Heap *PriorityQueue;
/*
struct Heap
{
    int top;
    int size;
    int *element;
};
PriorityQueue init(int size,int capacity)
{
    PriorityQueue h;
    h->element = (int*) malloc(sizeof(size));
    h->size = 0;
    h->top = -9999;
}
void up(PriorityQueue h)
{
    int i= h->size;
    while(h->size>0)
    {
        if(h->element[i]<h->element[i/2])
            swap(h->element[i],h->element[i/2]);
        i = i/2;
    }
}
void down(PriorityQueue h)
{
    int i = 0;
    while(h->size>0)
    {
        if(h->element[i] <  )
    }
}
void push(PriorityQueue h,int x)
{

}
int Pop(PriorityQueue h)
{

}
int getTop(PriorityQueue h)
{
    return h->element[h->size];
}
int main()
{
    PriorityQueue h = init();

    return 0;
}
*/

int n;

void dfs(int cur)
{
    if(n==cur)
        return ;

    cout<<cur<<endl;

    dfs(cur+1);

    cout<<cur+1<<endl;

}

int main()
{
    cin>>n;
    dfs(0);
    return 0;
}
