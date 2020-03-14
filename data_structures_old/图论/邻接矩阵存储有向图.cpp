#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
int  edge[100][100];
using namespace std;
/*
对于无向图，第i行所有元素值为1的个数表示顶点i的度数
对于有向图，第i行所有元素值为1的个数表示顶点i的出度，第j列所有元素值为1的个数表示顶点j的出度
*/
int main()
{
    int i,j;
    int n,m;//顶点个数,边数
    int u,v;//边的起点和终点
    int od,id;//顶点的出度和入度
    while(1)
    {
        cout<<"输入顶点数,边数:"<<endl;
        scanf("%d %d",&n,&m);
        if(n==0 && m==0)
            break;
        memset(edge,0,sizeof(edge));
        cout<<"输入每条边的起点和终点:"<<endl;
        for(i = 0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            edge[u-1][v-1] = 1;
        }
        cout<<"顶点出度为: "<<endl;
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
        cout<<"顶点入度为: "<<endl;
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
