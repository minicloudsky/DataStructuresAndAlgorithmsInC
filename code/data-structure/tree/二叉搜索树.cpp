#include<cstdlib>
#include<cstdio>
#define eletype int
#define ENDKEY -1
typedef struct node
{
    eletype key;
    node *lchild,*rchild;
}BSTNode,*BSTree;
void InsertBST(BSTree *bst,eletype key)
{
    BSTree s;
    if(*bst == NULL)
    {
        s = (BSTree) malloc(sizeof(BSTNode));
        s->key = key;
        s->lchild = NULL;
        s->rchild = NULL;
        *bst = s;
    }
    else if(key <(*bst)->key)
        InsertBST(&((*bst)->lchild),key);
    else if(key>(*bst)->key)
    {
        InsertBST(&((*bst)->rchild),key);
    }
}
void CreateBST(BSTree *bst)
{
    printf("����ڵ�����:\n");
    eletype key;
    *bst = NULL;

    scanf("%d", &key);
    while(key != ENDKEY)
    {
        InsertBST(bst,key);
        printf("����ڵ�����:\n");
        scanf("%d",&key);
    }
}
/*
BSTree SearchBST(BSTree *bst, eletype key)
{
    BSTree *q;
    q = bst;
    while(q)
    {
        if(q->key == key)
            return q;
        if(q->key->key)
            q = q->lchild;
        else
            q = q->rchild;
    }
    return NULL;
}
*/
//�ݹ����
BSTree SearchBST(BSTree bst,eletype key)
{
    if(!bst)
        return NULL;
    else if(bst->key == key)
        return bst;//���ҳɹ�
    else if(bst->key >key)
        return SearchBST(bst->lchild,key);//����������������
    else
        return SearchBST(bst->rchild,key);//����������������
}
BSTNode *DelBST(BSTree t,eletype k)// �ڶ�����������t��ɾȥ�ؼ���Ϊk�Ľ��
{
    BSTNode *p,*f,*q;
    p = t;
    f = NULL;
    while(p)//���ҹؼ���Ϊk�Ĵ�ɾ���p
    {
        if(p->key == k)
            break;  //�ҵ����˳�ѭ��
        f = p; //fָ��p���˫�׽��
        if(p->key>k)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if(p == NULL) //���Ҳ���������ԭ���Ķ���������
        return t;
    if(p->lchild == NULL)//p��������
    {
        if(f == NULL)
            t = p->rchild; //p��ԭ�������������ĸ�
        else if(f->lchild == p)//p��f������
            f->lchild = p->rchild; //��p������������f��������
        else //p��f���Һ���
        f->rchild = p->rchild;
        free(p); //�ͷű�ɾ���Ľ��p
    }
    else//p��������
    {
        q = p;
        s = p->rchild;
        while(s->rchild) //��p���������в��������½��
        {
            q = s;
            s = s->rchild;
        }
        if(q ==p)
        {
            q->lchild = s->lchild;
        }
        else
            q->rchild = s->lchild;
        p->key = s->key;
        free(s);
    }
    return t;
}
int main()
{
    BSTree *bst;
    CreateBST(bst);
    return 0;
}
