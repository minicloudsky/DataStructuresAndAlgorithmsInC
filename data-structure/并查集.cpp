#include<stdio.h>
#define SIZE 10
void init(int S[])
{
    for(int i=0;i<SIZE;i++)
        S[i] = -1;
    printf("��ʼ���� : \n");
    for(int i=0;i<SIZE;i++)
        printf("%d ",S[i]);
    printf("\n");
}
int Find(int S[],int x)
{
    printf("���ҽڵ� %d �ĸ�\n.",x);
    while(S[x]>=0)
    {
        x = S[x];
    }
    printf("%d �ĸ��ڵ�Ϊ %d.\n",x);
    return x;
}
//�ϲ�root1��root2���൱�ڰ�root2�ӵ�root1�ϣ����ǰ�root2�ĸ��ڵ��Ϊroot1
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
���鼯�е����ݣ�iΪ�±꣬rootΪi��Ӧ�ĸ�
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
    printf("��Ӽ��Ϻ󣬲��鼯������Ϊ:\n");
    print(S);
    //�ϲ�1��8
    Merge(S,1,8);
    printf("�ϲ�����1��8�󣬲��鼯������Ϊ:\n");
    print(S);
    //�ϲ�0��9
    Merge(S,0,9);
    printf("�ϲ�����0��9�󣬲��鼯������Ϊ:\n");
    print(S);
    //���ҽڵ�7�ĸ��ڵ�
    printf("7�ĸ��ڵ�Ϊ %d\n",Find(S,7));
    printf("\n");
    /*
    ����0������нڵ���0�ϲ�
    for(int i=1;i<10;i++)
    {
        Merge(S,0,i);
    }
    print(S);
    */
    return 0;
}
