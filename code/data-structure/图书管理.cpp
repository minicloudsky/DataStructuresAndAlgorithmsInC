#include<cstdio>
#include<cstdlib>
typedef struct book
{
    char book_name[30];
    char press[50];
    char press_time[50];
    int book_id;
    float price;
    char author[20];
    char classname[20];
    book *next;
};
book *FindByBookName(book *head)//��ֵ����
{
    int x,t=1;
    char name[20];
    printf("������Ҫ���ҵ�ͼ����:\n");
    scanf("%s",name);
    book *p=head;
    while(p!=NULL)
    {
        if(p->book_name == name)
        {
    printf("����ҵ�ͼ����ϢΪ\nͼ����: %s\n������: %s\n����ʱ��: %s\n���: %d\n�۸�:%f\n����: %s\nͼ�����: %s\n",p->book_name,p->press,p->press_time,p->book_id,p->price,p->author,p->classname);
            return head;
        }
        p=p->next;
        if(p->next==NULL&&p->book_name!=name)
            printf("û���ҵ�%s �Ȿ��\n",p->book_name);
        t++;
    }
}
int Getlength(book *head)//��ȡ������
{
    book *p = head;
    int i=0;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    printf("�õ�������Ϊ: %d\n",i);
    return i;
}
book *FindByBookID(book *head)//���±���ҵ�x���ڵ�
{
    int id;
}

book *Free(book *head)//ɾ���±�Ϊx�Ľڵ�
{
    int t=1, x;
    printf("������Ҫɾ���Ľڵ��±�:\n");
    scanf("%d",&x);
    book *p=head,*q=NULL;
    while(p!=NULL)
    {
        if(t==x-1)//������Ҫɾ���Ľڵ�p->next��ǰһ���ڵ�p
        {
            q=p->next;//��q���洢Ҫɾ���Ľڵ�
            p->next= p->next->next;//��Ҫɾ���Ľڵ��ǰһ���ڵ�ָ��Ҫɾ���Ľڵ����һ���ڵ�
            free(q);
            printf("�ڵ�%d�Ѿ��ɹ�ɾ��\n",x);
            break;
        }
        p = p->next;
        t++;
    }
    return head;
}
book *Append(book *head)//���ͼ��
{
    book *p=NULL,*q=head;
    int x;
    char book_name[30];
    char press[50];
    char press_time[50];
    int book_id;
    float price;
    char author[20];
    char classname[20];
    printf("������ͼ���������Ϣ:\n����\n����������\n����ʱ��\nͼ����\n�۸�\n����\nͼ�����\n");
    scanf("%s",book_name);
    scanf("%s",press);
    scanf("%s",press_time);
    scanf("%d",&book_id);
    scanf("%f",&price);
    scanf("%s",author);
    scanf("%s",classname);
    p = (book*)malloc(sizeof(book));
    if(p==NULL)
    {
        printf("����ӽڵ��ڴ����ʧ��\n");
    }
    else
    {
        if(head==NULL)
            head = p;
        else
        {
            while(q->next!=NULL)//��ʱq��λ�սڵ㣬�ƶ�q����q��ָ�����һ���սڵ�
            {
                q=q->next;
            }
            q->next = p;//��qָ��p
        }
        p->author = author;
        p->book_id = book_id;
        p->book_name = book_name;
        p->classname = classname;
        p->press = press;
        p->press_time = press_time;
        p->price = price;
        p->next=NULL;//��������ӵ����һ���ڵ��next��Ϊ��
    }
    return head;
}
void Print(book *head)//��ӡ�������е����нڵ�
{
    book  *p = head;
    int t=0;
    while(p!=NULL)
    {
        printf("��%d���ڵ�ĵ�ַΪ:%p\n����Ϊ:%d\n",++t,p,p->data);
        p = p->next;
    }
}
book *Insert(book *head)//�ڵ�x���ڵ���������
{
    book *p,*q=NULL;
    p=head;
    int t=1,num, x;
    printf("�������ڵڼ����ڵ�����ڵ�:\n");
    scanf("%d",&x);
    while(p->next!=NULL)
    {
        if(t==x)
        {
            printf("������Ҫ����ڵ������:\n");
            scanf("%d",&num);
            q =  (book*)malloc(sizeof(book));
            if(q==NULL)
            {
                printf("������ڵ��ڴ����ʧ��!\n");
                exit(0);
            }
            q->next = p->next;
            p->next = q;
            q->data = num;
            break;
        }
        else
            p = p->next;
        t++;
    }
    return head;
}
int main()
{
    book *head=NULL, *p=NULL,*q=NULL;
    int choice,length,flag=1;
    int n;
    while(flag)
    {
        printf("���������ѡ��:\n");
        printf("\t~~~~~~~~~~~~~~~\n\t1 :��ӽڵ�\n\t2 :����ڵ�\n\t3 :ɾ���ڵ�\n\t4 :���±���ҽڵ�\n\t5 :��ֵ���ҽڵ�\n\t6 :��ȡ������\n\t7 :��ӡ�ڵ�\n\t0 :�˳�\n\t~~~~~~~~~~~~~~~\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case (1):
        {
            head=Append(head);     //��ӽڵ�
            break;
        }
        case (2):
        {
            head = Insert(head);     //����ڵ�
            break;
        }
        case (3):
        {
            head = Free(head);      //ɾ���ڵ�
            break;
        }
        case (4):
        {
            p=FindByIndex(head);     //���±���ҽڵ�
            break;
        }
        case (5):
        {
            q=FindByValue(head);    //��ֵ���ҽڵ�
            break;
        }
        case (6):
        {
            length = Getlength(head);    //��ȡ������
            break;
        }
        case (7):
        {
            Print(head);    //��ӡ����
            break;
        }
        case (0):
        {
            printf("\tThanks for using our system !\n");    //�˳�
            exit(0);
            break;
        }
        default :
        {
            printf("�������ѡ����ȷ���������������!\n");
            break;
        }
        }
        int ans ;
        getchar();
        printf("\t�Ƿ�������в�������1/0��:\n");
        scanf("%d",&ans);
        if(ans)
            flag=1;
        else if(ans==0)
        {
            flag=0;
        }
        else
            printf("������������������!\n");
    }
    return 0;
}
