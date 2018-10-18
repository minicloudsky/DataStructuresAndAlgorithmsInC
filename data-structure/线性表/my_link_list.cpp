#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    node *next;
};
node *Append(node *head)
{
    node *p=NULL,*q = head;
    int x;
    printf("input node value:\n");
    scanf("%d",&x);
    p = (node*) malloc(sizeof(node));
    if(head==NULL)
    {
        head = p;
    }
    else
    {
        while(q->next!=NULL)
            q = q->next;
        q->next = p;
    }
    p->data = x;
    p->next = NULL;
    return head;
}
node *node_delete(node *head)
{
    int pos,flag=0;
    printf("input the deleting node:");
    scanf("%d",&pos);
    node *p = head,*q;
    while(p->next!=NULL)
    {
        if(flag==pos)
        {
            q = p->next;
            p->next = p->next->next;
            free(p);
            break;
        }
        p = p->next;
        flag++;
    }
    return head;
}
node *nodeInsert(node *head)// insert x into list at position pos
{
    node *p=head,*q=NULL;
    int pos,x;
    int flag=1;
    scanf("%d %d",&pos,&x);
    while(p->next!=NULL)
    {
        if(flag == pos)
        {
            q = (node*) malloc(sizeof(node));
            q->next = p->next;
            p->next = q;
            q->data = x;
            break;
        }
        p = p->next;
        flag++;
    }
    return head;
}
int getLength(node *head){
    int count = 0;
    while(head!=NULL){
        count = count+1;
        head = head->next;
    }
    return count;
}
int main()
{
    int n;
    scanf("%d",&n);
    node *head=NULL;
    while(n--){
        head = Append(head);
    }
    head = nodeInsert(head);
    head = node_delete(head);
    while(head!=NULL)
    {
        printf("%p   %d %p\n",head,head->data,head->next);
        head = head->next;
    }
    return 0;
}
