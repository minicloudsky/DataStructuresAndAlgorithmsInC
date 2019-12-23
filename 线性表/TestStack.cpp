#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct node
{
    int member;            //������
    node *pNext;//ָ����
}Node,*pNode;
typedef struct stack
{
    pNode Top;            //ջ��
    pNode Bottom;        //ջ��
}Stack,*pStack;
void InitStack(pStack );        //    ��ʼ��ջ�ĺ���
bool Push(pStack ,int);            //    ����ѹջ�����ĺ���
void TraverseStack(pStack );    //    ����ջ����
bool Empty(pStack );            //    �ж�ջ�Ƿ�Ϊ�յĺ���
int Pop(pStack );                //    ���г�ջ�����ĺ���
void Clear(pStack );            //    ���ջ�ĺ���
int main(void)
{
    Stack s;                        //    ����һ��ջ
    int i;
    int num;
    int data;                        //    ��ʱ�����û����������
    int re_num;                        //    ����Pop�����ķ���ֵ
    InitStack(&s);
    printf("�������뼸�����ݰ���");
    scanf("%d",&num);
    for (i = 0;i < num;i++)
    {
        printf("�� %d ������",i+1);
        scanf("%d",&data);
        if (Push(&s,data))                //    ����Push����
            continue;
        else
        {
            printf("���н�ջ����ʧ�ܣ�\n");
            exit(-1);
        }
    }
    TraverseStack(&s);                //    ���ñ�������
    printf("����ȥ����������: ");
    scanf("%d",&data);
    printf("��ȥ���������ǣ�");
    for (i = 0; i < data;i++)
    {
        re_num = Pop(&s);            //    ����Pop���������ѷ���ֵ����re_num;
        printf("%d ",re_num);
    }
    printf("����ɾ������ɶ��");
    TraverseStack(&s);
    printf("\n");
    Clear(&s);                        //    �������ջ����
    printf("�����¿���ջ���û��������\n");
    TraverseStack(&s);
    printf("\n");
    return 0;
}

//    ����ջ�ĳ�ʼ���ĺ���
void InitStack(pStack ps)
{
    ps->Top = (pNode)malloc(sizeof(Node));        //    �����ڴ�ռ��ջ��
    if (NULL == ps->Top)
    {
        printf("��̬�����ڴ�ʧ��\n");
        exit(-1);
    }
    else
    {
        ps->Bottom = ps->Top;                    //    ʹջ��Ҳָ��ջ���ռ�
        ps->Top->pNext = NULL;                    //    ջ��ָ����ΪNULL��
    }
    return ;
}
//    ���н�ջ�����ĺ���
bool Push(pStack ps,int data)
{
    pNode pNew = (pNode)malloc(sizeof(Node));    //    ����һ���½ڵ㣬�������ڴ�ռ�
    if (NULL == pNew)
        return false;
    pNew->member = data;                        //    ��Ҫ��ջ�����ݸ����½ڵ��member��Ա
    pNew->pNext = ps->Top;                        //    ʹ�½ڵ��ָ��ָ��ջ��
    ps->Top = pNew;                                //    ���½ڵ���Ϊ��ջ��
    return true;
}
void TraverseStack(pStack ps)
{
    pNode pNew = ps->Top;
    while(pNew!= ps->Bottom)                //    ֻҪջ��������ջ�ף�ѭ��
    {
        printf("%d ",pNew->member);            //    ��ӡջ���ĳ�Աmember
        pNew = pNew->pNext;                //    ջ��ָ�������ƶ�һ��
    }
    return ;
}
bool Empty(pStack ps)
{
    if(ps->Top == ps->Bottom)    //    ջ������ջ�ף�������ջ��û����ô
        return true;
    else
        return false;
}
int Pop(pStack ps)
{
    pNode pSwap = NULL;
    int return_val;
    if (Empty(ps))                //�ж�ջ�Ƿ�Ϊ�գ�Ϊ�վͲ��ܽ��г�ջ����
        exit(-1);
    else
    {
        return_val = ps->Top->member;    //    ��ջ���ĳ�Աmember��ֵ����return_val��Ϊ��������ֵ
        pSwap = ps->Top;                //    ʹpSwapָ��ջ��
        ps->Top = ps->Top->pNext;        //    ʹջ��ָ��ջ����һ���ڵ�
        free(pSwap);                    //    �ͷ���ǰ��ջ���ռ�
        return return_val;
    }
}
void Clear(pStack ps)
{
    pNode pNew = NULL;
    while (ps->Top != ps->Bottom)        //    ջ����ջ�ײ��ȣ�ѭ��
    {
        pNew = ps->Top;                    //    ʹһ���½ڵ��ջ��ָ��ͬһ�ռ�
        ps->Top = ps->Top->pNext;        //    ʹջ��ָ��ջ������һ���ڵ�
        free(pNew);                        //    �ͷŵ���ǰ��ջ���ռ�
    }
    return ;
}
