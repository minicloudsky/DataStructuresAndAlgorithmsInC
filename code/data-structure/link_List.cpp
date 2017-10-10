#include<stdlib.h>
#include<stdio.h>
typedef struct node
{
    int data;
    node *next;
};
node *append(node *head)
{
    int x;
    node *p=NULL,*q = head;
    scanf("%d",&x);
    p = (node*)malloc(sizeof(node));
    if(p ==NULL)
    {
        printf("Error\n");
    }
    else
    {
        if(head ==NULL)
        {
            head = p;
        }
        else
        {
            while(q->next!=NULL)
            {
                q = q->next;
            }
            q->next = p;
        }
        p->data = x;
        p->next = NULL;
    }
    return head;
}
int main()
{
    int n,x;
    node *head = NULL;
    scanf("%d",&n);
    while(n--)
    {
        /*
        scanf("%d",&x);
        p = (node*)malloc(sizeof(node));
        if(p ==NULL)
        {
            printf("Error\n");
        }
        else
        {
            if(head ==NULL)
            {
                head = p;
            }
            else
            {
                while(q->next!=NULL)
                {
                    q = q->next;
                }
                q->next = p;
            }
            p->data = x;
            p->next = NULL;
        }
        */
        head = append(head);
    }
    while(head!=NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
    }
    return 0;
}
