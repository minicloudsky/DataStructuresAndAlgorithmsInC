#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    node *next;
};
node *Append(node *head)//��ӽڵ�
{
    node *p=NULL,*q=head;
    int x;
    scanf("%d",&x);
    p = (node*)malloc(sizeof(node));
    if(p == NULL)
        printf("����ӽڵ��ڴ����ʧ��\n");
    else
    {
        if(head == NULL)
            head = p;
        else
        {
            while(q->next!=NULL)//��ʱq��λ�սڵ㣬�ƶ�q����q��ָ�����һ���սڵ�
            {
                q=q->next;
            }
            q->next = p;//��qָ��p
        }
        p->data=x;
        p->next=NULL;//��������ӵ����һ���ڵ��next��Ϊ��
    }
    return head;
}
int main()
{
    node *p,*q;
    q = Append(p);
    printf("%p %d\n",q,q->next);

    return 0;
}
