#ifndef OPE_N_H_INCLUDED
#define OPE_N_H_INCLUDED

#include"Cons_t.h"

//�ļ���������ĳ��Ϳ�������
void Getelem(char name[],int m,int n,double Open[V][V])
{
    FILE *fp;
    double no;
    if((fp=fopen(name,"r")) == NULL )
        printf("��ȡʱ�ļ��򿪴���\n");
    for(int i=0,k=0; i<m; i++)
    {
        if(i%10<7)
        {
            for(int j=0; j<n; j++)
            {
                fscanf(fp,"%lf",&Open[k][j]);
            }
            k++;

        }
        else
        {
            for(int j=0; j<n; j++)
            {
                fscanf(fp,"%lf",&no);
            }
        }

    }
    fclose(fp);
}

#endif // OPE_N_H_INCLUDED
