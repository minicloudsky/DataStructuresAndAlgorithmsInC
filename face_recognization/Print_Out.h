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

    //特征值
    if((fp=fopen("tzz.txt","w+"))==NULL)
        printf("特征值文本文件写入错误\n");
    for(int i=0; i<T; i++)
    {
        for(int j=0;j<T;j++)
        fprintf(fp,"%.20f ",A[i][j]);
        fprintf(fp,"\n");
    }
    fclose(fp);


    //特征向量
    if((fp=fopen("tzxl.txt","w+"))==NULL)
        printf("特征向量文本文件写入错误\n");
    for(int i=0; i<T; i++)
    {
        for(int j=0; j<T; j++)
        {
            fprintf(fp,"%.20f ",U[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);


    //选择之后的特征向量
    Sort( A,U );   //排序
    int op=choose( A,percent);    //选择
    if((fp=fopen("c_tzxl.txt","w+"))==NULL)
         printf("选择后的特征向量文本文件写入错误\n");
    for(int i=0; i<T; i++)
    {
        for(int j=0; j<op; j++)
        {
            fprintf(fp,"%.20f ",U[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);


    //降维矩阵
    memset(_Low,0,sizeof(_Low));
    mul(a,U,_Low,C,op,T);     //降维
    if((fp=fopen("low.txt","wt+")) == NULL )
         printf("降维矩阵文本文件写入错误\n");
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
