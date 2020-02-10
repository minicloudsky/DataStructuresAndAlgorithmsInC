#ifndef CONST_H_INCLUDED
#define CONST_H_INCLUDED

#include"All_h.h"
using namespace std;
//����ά��,Ĭ��32*32��1024
const int T=1024;

//��T��һ�㣬���ڶ�������
const int V=2000;

//��������
const int C=280;

//��C��һ�㣬���ڶ�������
const int R=500;

//��������
const int LE=(T*T-T)/2;

//Э�������

/*struct node
{
    int x,y;
    int index;    //����ָ������
    double data;   //��ŵ�����
}A[V][V];*/

struct L
{
    int P,Q;             //�����к���
    double data;        //A�еķǶԽ���Ԫ��
} s[LE];


//�۳˺�ľ��󡢵����е�u���󡢸�������
double U[V][V],u[V][V],UU[V][V],AA[V][V],_Low[V][V];

//��������
double a[R][V];

//����0
double zero=1e-16;

//ѡȡ����ռȫ�������İٷֱ�
double percent=0.99;

//��

using namespace std;

struct point
{
    int x;
    int y;
};

struct node
{
    double x;
    int index;
    struct point x_y;
};

typedef struct node *value;

node A[V][V];

struct heap
{
    int sizei;
    value *arr;
};

heap h;
const double ZERO = 0.000000001;

void heap_init(int x);
void heap_destory();
void heap_up(int);

void heap_init(int x)
{
    h.arr=(value*)malloc(sizeof(value)*x+1);
    assert(h.arr);
    h.sizei=0;
    value vv=(value)malloc(sizeof(struct node));
    vv->index=0;
    vv->x=65534.0;
    h.arr[0]=vv;
}

void heap_swap(value &a,value &b)
{
    value t=a;
    a=b;
    b=t;
    int tt=a->index;
    a->index=b->index;
    b->index=tt;
}

void heap_up(int x)
{
    for(int i=x;i>1;i/=2)
    {
        if(fabs(h.arr[i]->x)-fabs(h.arr[i/2]->x)>ZERO)
            heap_swap(h.arr[i],h.arr[i/2]);
        else break;
    }
}

void heap_down(int x)
{
    int child;
    for(int i=x;i<h.sizei&&i*2<=h.sizei;i=child)
    {
        child=i*2;
        if(child<h.sizei&&fabs(h.arr[child+1]->x)-fabs(h.arr[child]->x)>ZERO)
            child++;
        if(fabs(h.arr[i]->x)-fabs(h.arr[child]->x)<ZERO)
            heap_swap(h.arr[i],h.arr[child]);
        else  break;
    }
}

void heap_insert(value v)
{
    h.arr[++h.sizei]=v;
    v->index=h.sizei;
    heap_up(h.sizei);
}

value heap_get_max()
{
    return h.arr[1];
}

void heap_fit(int k)
{
    heap_up(k);
    heap_down(k);
}


int heap_empty()
{
    return h.sizei==0;
}


void heap_destory()
{
    free(h.arr);
    free(h.arr[0]);
}



#endif // CONST_H_INCLUDED
