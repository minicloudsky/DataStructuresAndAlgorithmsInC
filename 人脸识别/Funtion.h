#ifndef FUNTION_H_INCLUDED
#define FUNTION_H_INCLUDED

#include"Cons_t.h"

//�ļ���������ĳ��Ϳ�������
void Getelem(char name[],int m,int n,double Open[V][V]);

//�ļ���������ĳ��Ϳ�������
void Print(char name[],int m,int n,double Prin[V][V]);

//��Э������� , Э����������������
void COV(node A[V][V],double a[R][V])  ; //��Э�������

//Jacobi�㷨����������������ֵ
void pca();

//��׼������ˣ�O��n3����ʱ�临�Ӷ�
void mul ( double M[V][V], double N[V][V], double Z[V][V],int A,int B,int W);

//������������Ż��ľ������
void mull( double M[V][V], double N[V][V],int A,int B,int W,int p,int q);

//��������ֵ������������������
void Sort( double M[V][V], double U[V][V] );

//ѡ�����Ͼ��ȵ�����
int  choose ( double M[V][V],double percent);   //ѡ��

//������ı�
void Print(double percent);

//�������Ļ������С���ݲ���
void Print_Screen(double percent);

//����ת��
void MatTran( double M[V][V], double N[V][V],int A,int B);

void heap_insert(value v);
void heap_init(int x);
void heap_destory();
void heap_up(int);
void heap_swap(value &a,value &b);
void heap_down(int x);
void heap_fit(int k);
value heap_get_max();
int heap_empty();
#endif // FUNTION_H_INCLUDED
