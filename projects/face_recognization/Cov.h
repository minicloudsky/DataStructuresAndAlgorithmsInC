#ifndef COV_H_INCLUDED
#define COV_H_INCLUDED

#include"Cons_t.h"

void COV(node A[V][V],double a[R][V])   //求协方差矩阵
{
    int i,j,l;
    double sum;
    for(i=0; i<T; i++)     //求协方差矩阵
    {
        for(j=0; j<T; j++)
        {
            sum=0;
            for(l=0; l<C; l++)       //求第i列的平均值
            {
                sum+=a[l][i];
            }
            double x=sum/C;
            sum=0;
            for(l=0; l<C; l++)      //求第j列的平均值
            {
                sum+=a[l][j];
            }
            double y=sum/C;
            sum=0;
            for(l=0; l<C; l++)      //公式sum( (dim1-mean(dim1)) .* (dim2-mean(dim2)) );
            {
                sum+=(a[l][i]-x)*(a[l][j]-y);
            }
            A[i][j].x=sum/(C-1); //除以n-1之后变成i,j之间的协方差，然后储存在协方差数组里。
            A[i][j].x_y.x=i;
            A[i][j].x_y.y=j;
        }
    }
  /*  for(int i=0;i<T;i++)   //测试
    {
        for(int j=0;j<T;j++)
        {
             printf("%lf ",A[i][j].x);
        }
        printf("\n");
    }*/

}


#endif // COV_H_INCLUDED
