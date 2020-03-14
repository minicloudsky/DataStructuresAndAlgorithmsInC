#include<cstdio>
#include<cstdlib>
typedef struct node
{
	int data;
	node *next;
};
node *FindByValue(node *head)//��ֵ����
{
	int x,t=1;
	printf("������Ҫ���ҵĽڵ��ֵ:\n");
	scanf("%d",&x);
	node *p=head;
	while(p!=NULL)
	{
		if(p->data==x)
		{ printf("����ҵĽڵ��ַΪ:��%d���ڵ�\n�ڵ��ַΪ:%p\n����Ϊ: %d\n",t,p,p->data); return head;    }
		p=p->next;
		if(p->next==NULL&&p->data!=x)
			printf("û���ҵ�ֵΪ%d�Ľڵ�!\n",x);
		t++;
	}
}
int Getlength(node *head)//��ȡ������
{
	node *p = head;
	int i=0;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	printf("�õ�������Ϊ: %d\n",i);
	return i;
}
node *FindByIndex(node *head)//���±���ҵ�x���ڵ�
{
	int x;
	printf("������Ҫ���ҽڵ���±�:\n");
	scanf("%d",&x);
	if(x>Getlength(head)||x<0)
		printf("������������±겻����!\n");
	node *p=head;
	int i=1;
	while(p->next!=NULL)
	{
		if(i==x)
		{    printf("����ҵĽڵ��ַΪ: %p ����Ϊ: %d\n",p,p->data); return head;	}
		p = p->next;
		i++;
	}
}

node *Free(node *head)//ɾ���±�Ϊx�Ľڵ�
{
	int t=1, x;
	printf("������Ҫɾ���Ľڵ��±�:\n");
	scanf("%d",&x);
	node *p=head,*q=NULL;
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
		p = p->next;    t++;
	}
	return head;
}
node *Append(node *head)//��ӽڵ�
{
	node *p=NULL,*q=head;
	int x;
	printf("������ڵ�����:\n");
	scanf("%d",&x);
	p = (node*)malloc(sizeof(node));
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
		p->data=x;
		p->next=NULL;//��������ӵ����һ���ڵ��next��Ϊ��
	}
	return head;
}
void Print(node *head)//��ӡ�������е����нڵ�
{
	node  *p = head;
	int t=0;
	while(p!=NULL)
	{
		printf("��%d���ڵ�ĵ�ַΪ:%p\n����Ϊ:%d\n",++t,p,p->data);
		p = p->next;
	}
}
node *Insert(node *head)//�ڵ�x���ڵ���������
{
	node *p,*q=NULL;
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
			q =  (node*)malloc(sizeof(node));
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
	node *head=NULL, *p=NULL,*q=NULL;
	int choice,length,flag=1;
	int n;
	while(flag)
	{
		printf("���������ѡ��:\n");
		printf("\t~~~~~~~~~~~~~~~\n\t1 :��ӽڵ�\n\t2 :����ڵ�\n\t3 :ɾ���ڵ�\n\t4 :���±���ҽڵ�\n\t5 :��ֵ���ҽڵ�\n\t6 :��ȡ������\n\t7 :��ӡ�ڵ�\n\t0 :�˳�\n\t~~~~~~~~~~~~~~~\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case (1):{  head=Append(head);  break;   }//��ӽڵ�
			case (2):{  head = Insert(head);  break; }//����ڵ�
			case (3):{  head = Free(head);   break;  }//ɾ���ڵ�
			case (4):{  p=FindByIndex(head);  break; }//���±���ҽڵ�
			case (5):{  q=FindByValue(head); break;  }//��ֵ���ҽڵ�
			case (6):{ length = Getlength(head);break;}//��ȡ������
			case (7):{ Print(head); break;            }//��ӡ����
			case (0):{ printf("\tThanks for using our system !\n");exit(0);break;}//�˳�
			default : { printf("�������ѡ����ȷ���������������!\n");break;}
		}
		int ans ;
		getchar();
		printf("\t�Ƿ�������в�������1/0��:\n");
		scanf("%d",&ans);
		if(ans)
			flag=1;
		else if(ans==0){flag=0;}
		else
			printf("������������������!\n");
	}
	return 0;
}
