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
book *FindByBookName(book *head)//按值查找
{
    int x,t=1;
    char name[20];
    printf("请输入要查找的图书名:\n");
    scanf("%s",name);
    book *p=head;
    while(p!=NULL)
    {
        if(p->book_name == name)
        {
    printf("你查找的图书信息为\n图书名: %s\n出版社: %s\n出版时间: %s\n编号: %d\n价格:%f\n作者: %s\n图书类别: %s\n",p->book_name,p->press,p->press_time,p->book_id,p->price,p->author,p->classname);
            return head;
        }
        p=p->next;
        if(p->next==NULL&&p->book_name!=name)
            printf("没有找到%s 这本书\n",p->book_name);
        t++;
    }
}
int Getlength(book *head)//获取链表长度
{
    book *p = head;
    int i=0;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    printf("该单链表长度为: %d\n",i);
    return i;
}
book *FindByBookID(book *head)//按下标查找第x个节点
{
    int id;
}

book *Free(book *head)//删除下标为x的节点
{
    int t=1, x;
    printf("请输入要删除的节点下标:\n");
    scanf("%d",&x);
    book *p=head,*q=NULL;
    while(p!=NULL)
    {
        if(t==x-1)//遍历到要删除的节点p->next的前一个节点p
        {
            q=p->next;//用q来存储要删除的节点
            p->next= p->next->next;//将要删除的节点的前一个节点指向要删除的节点的下一个节点
            free(q);
            printf("节点%d已经成功删除\n",x);
            break;
        }
        p = p->next;
        t++;
    }
    return head;
}
book *Append(book *head)//添加图书
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
    printf("请输入图书的以下信息:\n书名\n出版社名称\n出版时间\n图书编号\n价格\n作者\n图书类别\n");
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
        printf("待添加节点内存分配失败\n");
    }
    else
    {
        if(head==NULL)
            head = p;
        else
        {
            while(q->next!=NULL)//此时q部位空节点，移动q调整q到指向最后一个空节点
            {
                q=q->next;
            }
            q->next = p;//将q指向p
        }
        p->author = author;
        p->book_id = book_id;
        p->book_name = book_name;
        p->classname = classname;
        p->press = press;
        p->press_time = press_time;
        p->price = price;
        p->next=NULL;//将链表添加的最后一个节点的next置为空
    }
    return head;
}
void Print(book *head)//打印单链表中的所有节点
{
    book  *p = head;
    int t=0;
    while(p!=NULL)
    {
        printf("第%d个节点的地址为:%p\n数据为:%d\n",++t,p,p->data);
        p = p->next;
    }
}
book *Insert(book *head)//在第x个节点后插入数据
{
    book *p,*q=NULL;
    p=head;
    int t=1,num, x;
    printf("请输入在第几个节点后插入节点:\n");
    scanf("%d",&x);
    while(p->next!=NULL)
    {
        if(t==x)
        {
            printf("请输入要插入节点的数据:\n");
            scanf("%d",&num);
            q =  (book*)malloc(sizeof(book));
            if(q==NULL)
            {
                printf("待插入节点内存分配失败!\n");
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
        printf("请输入你的选择:\n");
        printf("\t~~~~~~~~~~~~~~~\n\t1 :添加节点\n\t2 :插入节点\n\t3 :删除节点\n\t4 :按下标查找节点\n\t5 :按值查找节点\n\t6 :获取链表长度\n\t7 :打印节点\n\t0 :退出\n\t~~~~~~~~~~~~~~~\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case (1):
        {
            head=Append(head);     //添加节点
            break;
        }
        case (2):
        {
            head = Insert(head);     //插入节点
            break;
        }
        case (3):
        {
            head = Free(head);      //删除节点
            break;
        }
        case (4):
        {
            p=FindByIndex(head);     //按下标查找节点
            break;
        }
        case (5):
        {
            q=FindByValue(head);    //按值查找节点
            break;
        }
        case (6):
        {
            length = Getlength(head);    //获取链表长度
            break;
        }
        case (7):
        {
            Print(head);    //打印链表
            break;
        }
        case (0):
        {
            printf("\tThanks for using our system !\n");    //退出
            exit(0);
            break;
        }
        default :
        {
            printf("你输入的选择不正确，请检查后重新输入!\n");
            break;
        }
        }
        int ans ;
        getchar();
        printf("\t是否继续进行操作？（1/0）:\n");
        scanf("%d",&ans);
        if(ans)
            flag=1;
        else if(ans==0)
        {
            flag=0;
        }
        else
            printf("输入错误，请检查后再输入!\n");
    }
    return 0;
}
