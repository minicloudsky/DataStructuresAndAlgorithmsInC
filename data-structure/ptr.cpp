#include<cstdio>
#include<cstdlib>
typedef struct node
{
    int data;
    node *next;
};
node *node_update(node *head)
{
    node *q = head;
    int pos,value;
    printf("input update node pos and value:\n");
    scanf("%d %d",&pos,&value);
    int flag = 1;
    while(q->next!=NULL)
    {
        if(flag == pos)
        {
            q->data = value;
            break;
        }
        flag++;
        q = q->next;
    }
    return head;
}
int node_find(node *head)
{
    node *q = head;
    int index,flag=1;
    printf("Input the node index you finding:\n");
    scanf("%d",&index);
    while(q->next!=NULL)
    {
        if(flag==index)
        {
            return q->data;
        }
        q = q->next;
        flag++;
    }
    return -1;
}
node *node_insert(node *head)
{
    int x,pos;
    int flag = 1;
    printf("���������ڵ�λ�ú�����\n");
    scanf("%d %d",&pos,&x);

    node *p=NULL,*q = head;
    while(q->next!=NULL)
    {
        if(flag==pos)
        {
            p = (node*)malloc(sizeof(node));
            if(p==NULL)
                printf("�ڵ��ڴ�����ʧ��\n");
            else
            {
                p->next = q->next;
                q->next = p;
                p->data = x;
                break;
            }
        }
        q = q->next;
        flag++;
    }
    return head;
}
node *node_delete(node *head)
{
    node *q = head,*p=NULL;
    int pos,flag=1;
    printf("����Ҫɾ���Ľڵ�λ��\n");
    scanf("%d",&pos);
    while(q->next!=NULL)
    {
        if(flag ==pos)
        {
            p = q->next;
            q->next = q->next->next;
            free(p);
            break;
        }
        q = q->next;
        flag++;
    }
    return head;
}
node *Append(node *head)
{
    node *p=NULL,*q=head;
    int x;
    printf("input value:\n");
    scanf("%d",&x);
    p = (node*)malloc(sizeof(node));
    if(p==NULL)//�����ڴ�ʧ��
        printf("memory error\n");
    else
    {
        if(head==NULL)
        {
            head = p;//��ͷ���ָ��p��Ҳ����˵�Ѵ�ʱ����Ľڵ�p��Ϊͷ��㣬ͷ����ڴ��ַ���ʱp��ַ��ͬ
        }
        else
        {
            ////qָ��ͷ��㣬���ͷ��㲻Ϊ�գ���qһֱ�ƶ����������һ���ڵ㣬Ȼ��p��Ϊq����һ���ڵ�
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
    node *head=NULL;
    int n,x;
    printf("input num:\n");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        head = Append(head);
    }
    //head = node_insert(head);
    //head = node_delete(head);
    //head = node_update(head);
    int find_value = node_find(head);
    printf("The finding value is : %d\n",find_value);
    while(head!=NULL)
    {
        printf("%p %d %p\n",head,head->data,head->next);
        head = head->next;
    }
    return 0;
}
