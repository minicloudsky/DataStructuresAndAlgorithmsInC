#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    node *pre;
    node *next;
};
node *Create(node *head)
{
    int num;
    printf("Input node number:\n");
    scanf("%d",&num);
    node *p=NULL,*q = head;
    p = (node*) malloc(sizeof(node));
    if(p==NULL)
    {
        printf("memory distribution error. \n");
        exit(0);
    }
    else
    {
        if(head==NULL)
        {
            head = p;
            head->pre = NULL;
        }
        else
        {
            while(q->next!=NULL)
            {
                q = q->next;
            }
            q->next = p;
            p->pre = q;
        }
    }
}
int main()
{
    printf("%d\n",sizeof(unsigned char*));
    return 0;
}
