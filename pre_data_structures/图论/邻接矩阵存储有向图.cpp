#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
int  edge[100][100];
using namespace std;
/*
��������ͼ����i������Ԫ��ֵΪ1�ĸ�����ʾ����i�Ķ���
��������ͼ����i������Ԫ��ֵΪ1�ĸ�����ʾ����i�ĳ��ȣ���j������Ԫ��ֵΪ1�ĸ�����ʾ����j�ĳ���
*/
int main()
{
    int i,j;
    int n,m;//�������,����
    int u,v;//�ߵ������յ�
    int od,id;//����ĳ��Ⱥ����
    while(1)
    {
        cout<<"���붥����,����:"<<endl;
        scanf("%d %d",&n,&m);
        if(n==0 && m==0)
            break;
        memset(edge,0,sizeof(edge));
        cout<<"����ÿ���ߵ������յ�:"<<endl;
        for(i = 0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            edge[u-1][v-1] = 1;
        }
        cout<<"�������Ϊ: "<<endl;
        for(i=0;i<n;i++)
        {
            od = 0;
            for(j = 0;j<n;j++)
                od+=edge[i][j];
            if(i==0)
                cout<<od;
            else
                cout<<" "<<od;
        }
        cout<<endl;
        cout<<"�������Ϊ: "<<endl;
        for(i=0;i<n;i++)
        {
            id = 0;
            for(j =0;j<n;j++)
                id +=edge[j][i];
            if(i==0)
                cout<<id;
            else
                cout<<" "<<id;
        }
        cout<<endl;
    }
    return 0;
}
