#ifndef PRINTOUT_H_INCLUDED
#define PRINTOUT_H_INCLUDED

#include"All_h.h"

void  Sort( node M[V][V], double U[V][V] )
{
    double N[V];
    double t;
    for(int i = 0 ;  i < T-1 ; i++ )        //
    {
        for( int j = 0 ; j < T-1-i; j++)
        {
            if( M[j][j].x < M[j+1][j+1].x )
            {
                t = M[j][j].x;
                M[j][j].x = M[j+1][j+1].x;
                M[j+1][j+1].x = t;
                for( int l = 0 ; l < T ; l++ )
                {
                    N[l] = U[l][j];
                }
                for( int l = 0 ; l < T ; l++ )
                {
                    U[l][j] = U[l][j+1];
                }
                for( int l = 0 ; l < T ; l++ )
                {
                    U[l][j+1] = N[l];
                }
            }
        }
    }
}

int  choose ( node M[V][V],double percent)
{
    double s=0,ss=0;      //
    int i;
    for( i=0; i<T; i++)
    {
        ss+=M[i][i].x;
    }
    for(i=0; i<T; i++)
    {
        s+=M[i][i].x;
        if(s/ss>=percent)
            break;
    }
    if(i==T)
        i=300;
    return i;
}

void Print( double percent)
{
    FILE *fp;

    //����ֵ
    if((fp=fopen("tzz.txt","w+"))==NULL)
        printf("����ֵ�ı��ļ�д�����\n");
    for(int i=0; i<T; i++)
    {
        for(int j=0;j<T;j++)
        fprintf(fp,"%.20f ",A[i][j]);
        fprintf(fp,"\n");
    }
    fclose(fp);


    //��������
    if((fp=fopen("tzxl.txt","w+"))==NULL)
        printf("���������ı��ļ�д�����\n");
    for(int i=0; i<T; i++)
    {
        for(int j=0; j<T; j++)
        {
            fprintf(fp,"%.20f ",U[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);


    //ѡ��֮�����������
    Sort( A,U );   //����
    int op=choose( A,percent);    //ѡ��
    if((fp=fopen("c_tzxl.txt","w+"))==NULL)
         printf("ѡ�������������ı��ļ�д�����\n");
    for(int i=0; i<T; i++)
    {
        for(int j=0; j<op; j++)
        {
            fprintf(fp,"%.20f ",U[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);


    //��ά����
    memset(_Low,0,sizeof(_Low));
    mul(a,U,_Low,C,op,T);     //��ά
    if((fp=fopen("low.txt","wt+")) == NULL )
         printf("��ά�����ı��ļ�д�����\n");
    for(int i=0; i<C; i++)
    {
        for(int j=0; j<op; j++)
        {
            fprintf(fp,"%.20f ",_Low[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}

#endif // PRINTOUT_H_INCLUDED
