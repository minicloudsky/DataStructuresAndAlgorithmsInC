#include<cstdio>
#include<cstdlib>
typedef struct node
{
	int data;
	node *next;
};
node *FindByValue(node *head)//按值查找
{
	int x,t=1;
	printf("请输入要查找的节点的值:\n");
	scanf("%d",&x);
	node *p=head;
	while(p!=NULL)
	{
		if(p->data==x)
		{ printf("你查找的节点地址为:第%d个节点\n节点地址为:%p\n数据为: %d\n",t,p,p->data); return head;    }
		p=p->next;
		if(p->next==NULL&&p->data!=x)
			printf("没有找到值为%d的节点!\n",x);
		t++;
	}
}
int Getlength(node *head)//获取链表长度
{
	node *p = head;
	int i=0;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	printf("该单链表长度为: %d\n",i);
	return i;
}
node *FindByIndex(node *head)//按下标查找第x个节点
{
	int x;
	printf("请输入要查找节点的下标:\n");
	scanf("%d",&x);
	if(x>Getlength(head)||x<0)
		printf("你输入的链表下标不存在!\n");
	node *p=head;
	int i=1;
	while(p->next!=NULL)
	{
		if(i==x)
		{    printf("你查找的节点地址为: %p 数据为: %d\n",p,p->data); return head;	}
		p = p->next;
		i++;
	}
}

node *Free(node *head)//删除下标为x的节点
{
	int t=1, x;
	printf("请输入要删除的节点下标:\n");
	scanf("%d",&x);
	node *p=head,*q=NULL;
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
		p = p->next;    t++;
	}
	return head;
}
node *Append(node *head)//添加节点
{
	node *p=NULL,*q=head;
	int x;
	printf("请输入节点数据:\n");
	scanf("%d",&x);
	p = (node*)malloc(sizeof(node));
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
		p->data=x;
		p->next=NULL;//将链表添加的最后一个节点的next置为空
	}
	return head;
}
void Print(node *head)//打印单链表中的所有节点
{
	node  *p = head;
	int t=0;
	while(p!=NULL)
	{
		printf("第%d个节点的地址为:%p\n数据为:%d\n",++t,p,p->data);
		p = p->next;
	}
}
node *Insert(node *head)//在第x个节点后插入数据
{
	node *p,*q=NULL;
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
			q =  (node*)malloc(sizeof(node));
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
	node *head=NULL, *p=NULL,*q=NULL;
	int choice,length,flag=1;
	int n;
	while(flag)
	{
		printf("请输入你的选择:\n");
		printf("\t~~~~~~~~~~~~~~~\n\t1 :添加节点\n\t2 :插入节点\n\t3 :删除节点\n\t4 :按下标查找节点\n\t5 :按值查找节点\n\t6 :获取链表长度\n\t7 :打印节点\n\t0 :退出\n\t~~~~~~~~~~~~~~~\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case (1):{  head=Append(head);  break;   }//添加节点
			case (2):{  head = Insert(head);  break; }//插入节点
			case (3):{  head = Free(head);   break;  }//删除节点
			case (4):{  p=FindByIndex(head);  break; }//按下标查找节点
			case (5):{  q=FindByValue(head); break;  }//按值查找节点
			case (6):{ length = Getlength(head);break;}//获取链表长度
			case (7):{ Print(head); break;            }//打印链表
			case (0):{ printf("\tThanks for using our system !\n");exit(0);break;}//退出
			default : { printf("你输入的选择不正确，请检查后重新输入!\n");break;}
		}
		int ans ;
		getchar();
		printf("\t是否继续进行操作？（1/0）:\n");
		scanf("%d",&ans);
		if(ans)
			flag=1;
		else if(ans==0){flag=0;}
		else
			printf("输入错误，请检查后再输入!\n");
	}
	return 0;
}
