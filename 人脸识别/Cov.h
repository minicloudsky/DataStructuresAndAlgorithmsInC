#ifndef COV_H_INCLUDED
#define COV_H_INCLUDED

#include"Cons_t.h"

void COV(node A[V][V],double a[R][V])   //��Э�������
{
    int i,j,l;
    double sum;
    for(i=0; i<T; i++)     //��Э�������
    {
        for(j=0; j<T; j++)
        {
            sum=0;
            for(l=0; l<C; l++)       //���i�е�ƽ��ֵ
            {
                sum+=a[l][i];
            }
            double x=sum/C;
            sum=0;
            for(l=0; l<C; l++)      //���j�е�ƽ��ֵ
            {
                sum+=a[l][j];
            }
            double y=sum/C;
            sum=0;
            for(l=0; l<C; l++)      //��ʽsum( (dim1-mean(dim1)) .* (dim2-mean(dim2)) );
            {
                sum+=(a[l][i]-x)*(a[l][j]-y);
            }
            A[i][j].x=sum/(C-1); //����n-1֮����i,j֮���Э���Ȼ�󴢴���Э���������
            A[i][j].x_y.x=i;
            A[i][j].x_y.y=j;
        }
    }
  /*  for(int i=0;i<T;i++)   //����
    {
        for(int j=0;j<T;j++)
        {
             printf("%lf ",A[i][j].x);
        }
        printf("\n");
    }*/

}


#endif // COV_H_INCLUDED
