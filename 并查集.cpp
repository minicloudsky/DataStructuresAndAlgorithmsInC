#include<stdio.h>
#define SIZE 10
void init(int S[])
{
    for(int i=0;i<SIZE;i++)
        S[i] = -1;
    printf("初始化后 : \n");
    for(int i=0;i<SIZE;i++)
        printf("%d ",S[i]);
    printf("\n");
}
int Find(int S[],int x)
{
    printf("查找节点 %d 的根\n.",x);
    while(S[x]>=0)
    {
        x = S[x];
    }
    printf("%d 的根节点为 %d.\n",x);
    return x;
}
//合并root1和root2，相当于把root2接到root1上，即是把root2的根节点改为root1
void Merge(int S[],int root1,int root2)
{
    S[root2] = root1;
}
void print(int S[])
{
    for(int i=0;i<SIZE;i++)
    {
        if(i==0)
            printf("  i   ");
        printf("%d ",i);
    }
    printf("\n");
    for(int i=0;i<SIZE;i++)
    {
        if(i==0)
            printf("root ");
        printf("%d ",S[i]);
    }
}
int main()
{
/*
并查集中的数据，i为下标，root为i对应的根
 i   0  1 2 3 4  5 6 7 8 9
root -1 0 0 2 -1 4 4 4 7 6

*/
    int S[SIZE];
    init(S);
    S[1] = S[2]=0;
    S[3] = 2;
    S[5] = S[6] = S[7] = 4;
    S[8] =7;
    S[9]=6;
    printf("添加集合后，并查集中数据为:\n");
    print(S);
    //合并1和8
    Merge(S,1,8);
    printf("合并集合1和8后，并查集中数据为:\n");
    print(S);
    //合并0和9
    Merge(S,0,9);
    printf("合并集合0和9后，并查集中数据为:\n");
    print(S);
    //查找节点7的根节点
    printf("7的根节点为 %d\n",Find(S,7));
    printf("\n");
    /*
    将除0外的所有节点与0合并
    for(int i=1;i<10;i++)
    {
        Merge(S,0,i);
    }
    print(S);
    */
    return 0;
}
