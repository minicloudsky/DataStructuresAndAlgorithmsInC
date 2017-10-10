#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    node *next;
};
node *Append(node *head)//添加节点
{
    node *p=NULL,*q=head;
    int x;
    scanf("%d",&x);
    p = (node*)malloc(sizeof(node));
    if(p == NULL)
        printf("待添加节点内存分配失败\n");
    else
    {
        if(head == NULL)
            head = p;
        else
        {
            while(q->next!=NULL)//此时q部位空节点，移动q调整q到指向最后一个空节点
            {
                q=q->next;
            }
            q->next = p;//将q指向p
        }
        p->data=x;
        p->next=NULL;//将链表添加的最后一个节点的next置为空
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
