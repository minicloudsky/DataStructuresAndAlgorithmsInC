#ifndef JACOBI_H_INCLUDED
#define JACOBI_H_INCLUDED

#include"All_h.h"
using namespace std;
long long int CONUT = 0;

void pca()    //pca�㷨�����ſɱ��㷨������ֵ����������
{
    //�����������ǶԽ���Ԫ���е����ֵ�ĺ������������
    int num=0,p,q;

    //�ǶԽ���Ԫ���е����ֵ
    double Max;

    //���
    heap_init(20000000);
    for(int i=0; i<T; i++)
    {
        for(int j=0; j<i; j++)
        {
            heap_insert(&A[i][j]);

        }
    }



    while(num<LE)          //��ʼ����
    {

        num++;
        if(CONUT%10000==0)                 //����������������CONUTΪ520000ʱ���ͽ�������
        {
            printf("%lld\n",CONUT);
        }
        CONUT++;

        //�Ӷ���ȡ�����ڵ�
        value cur=heap_get_max();
        double Max=fabs(cur->x);
        p=cur->x_y.x;
        q=cur->x_y.y;
        if(Max<zero)           //���ֵС�ھ���ֵ������ѭ��
            break;
        double x ;           //����A[][];
        x= 0.5*atan2(-2*A[p][q].x,A[q][q].x-A[p][p].x);     //�Ƕ�

        //����Jacobi�㷨�����
        //��aa[i]�ֱ��¼�ı��˵�ֵ������������õ�֮ǰ�ı����ֵ�����Բ���ֱ�Ӹ�
        double aa1=A[p][p].x,aa2=A[q][q].x,aa3[1024],aa4[1024],aa5=A[p][q].x;

        //A[p][p],A[q][q];
        aa1=A[p][p].x*cos(x)*cos(x)+A[q][q].x*sin(x)*sin(x)+2*A[p][q].x*sin(x)*cos(x);
        aa2=A[q][q].x*cos(x)*cos(x)+A[p][p].x*sin(x)*sin(x)-2*A[p][q].x*sin(x)*cos(x);

        //A[p][i],A[i][p];
        for(int i=0; i<T; i++)
            if((i!=p)&&(i!=q))
            {
                if(fabs(A[p][i].x)<zero)
                    continue;
                aa3[i]=A[p][i].x*cos(x)+A[q][i].x*sin(x);
            }
        //A[q][i],A[i][q];
        for(int i=0; i<T; i++)
            if((i!=p)&&(i!=q))
            {
                if(fabs(A[i][q].x)<zero)
                    continue;
                aa4[i]=-A[p][i].x*cos(x)+A[q][i].x*sin(x);
            }
        //A[p][q],A[q][p];
        if(fabs(A[p][q].x)>zero)
        {
            aa5=(A[q][q].x-A[p][p].x)*sin(2*x)/2+A[p][q].x*cos(2*x);
        }

        //�ı����


        A[p][p].x=aa1;

        A[q][q].x=aa2;


        for(int i=0; i<T; i++)
            if((i!=p)&&(i!=q))
            {
                if(fabs(A[p][i].x)<zero)
                    continue;
                A[p][i].x=aa3[i];
                A[i][p].x=A[p][i].x;
                if(i<p)
                {
                    heap_fit(A[p][i].index);
                }
                else
                {
                    heap_fit(A[i][p].index);
                }

            }

        for(int i=0; i<T; i++)
            if((i!=p)&&(i!=q))
            {
                if(fabs(A[i][q].x)<zero)
                    continue;
                A[q][i].x=aa4[i];
                A[i][q].x=A[q][i].x;
                if(i<q)
                {
                    heap_fit(A[q][i].index);
                }
                else
                {
                    heap_fit(A[i][q].index);
                }

            }

        //A[p][q],A[q][p];
        A[p][q].x=aa5;

        A[q][p].x=aa5;
        if(p<q)
        {
            heap_fit(A[q][p].index);
        }
        if(p>q)
        {
            heap_fit(A[p][q].index);
        }
       // printf("1\n");

        //���ݽǶ�x����u����


        u[p][p]=cos(x);
        u[q][q]=cos(x);
        for(int m=0; m<T; m++)
        {
            if(m!=p&&m!=q)
                u[m][m]=1;
        }
        u[p][q]=-sin(x);

        u[q][p]=sin(x);


        //��һ��ѭ����U����u
        if(num==1)
        {
            for(int m=0; m<T; m++)
            {
                for(int n=0; n<T; n++)
                {
                    U[m][n]=u[m][n];
                }
            }
        }
        else   //U��u��˽������U��
        {
            memset(UU,0,sizeof(UU));
            mull(U,u,T,T,T,p,q);
        }

        // printf("2\n");
    }
    /* for(int i=0; i<T; i++)
     {

         for(int j=0; j<T; j++)
         {
             printf("%lf ",A[i][j].x);
         }
         printf("\n");
     }*/
}


#endif // JACOBI_H_INCLUDED
