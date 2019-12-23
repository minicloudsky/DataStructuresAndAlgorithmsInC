#ifndef FUNTION_H_INCLUDED
#define FUNTION_H_INCLUDED

#include"Cons_t.h"

//文件名，数组的长和宽，数组名
void Getelem(char name[],int m,int n,double Open[V][V]);

//文件名，数组的长和宽，数组名
void Print(char name[],int m,int n,double Prin[V][V]);

//求协方差矩阵 , 协方差矩阵和样本矩阵
void COV(node A[V][V],double a[R][V])  ; //求协方差矩阵

//Jacobi算法求特征向量和特征值
void pca();

//标准矩阵相乘，O（n3）的时间复杂度
void mul ( double M[V][V], double N[V][V], double Z[V][V],int A,int B,int W);

//根据特殊情况优化的矩阵相乘
void mull( double M[V][V], double N[V][V],int A,int B,int W,int p,int q);

//根据特征值对特征向量进行排序
void Sort( double M[V][V], double U[V][V] );

//选出符合精度的向量
int  choose ( double M[V][V],double percent);   //选择

//输出以文本
void Print(double percent);

//输出到屏幕，用于小数据测试
void Print_Screen(double percent);

//矩阵转置
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
