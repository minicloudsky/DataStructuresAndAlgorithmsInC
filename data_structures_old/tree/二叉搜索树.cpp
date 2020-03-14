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
    printf("输入节点数据:\n");
    eletype key;
    *bst = NULL;

    scanf("%d", &key);
    while(key != ENDKEY)
    {
        InsertBST(bst,key);
        printf("输入节点数据:\n");
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
//递归查找
BSTree SearchBST(BSTree bst,eletype key)
{
    if(!bst)
        return NULL;
    else if(bst->key == key)
        return bst;//查找成功
    else if(bst->key >key)
        return SearchBST(bst->lchild,key);//在左子树继续查找
    else
        return SearchBST(bst->rchild,key);//在右子树继续查找
}
BSTNode *DelBST(BSTree t,eletype k)// 在二叉树排序树t中删去关键字为k的结点
{
    BSTNode *p,*f,*q;
    p = t;
    f = NULL;
    while(p)//查找关键字为k的待删结点p
    {
        if(p->key == k)
            break;  //找到则退出循环
        f = p; //f指向p结点双亲结点
        if(p->key>k)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if(p == NULL) //若找不到，返回原来的二叉排序树
        return t;
    if(p->lchild == NULL)//p无左子树
    {
        if(f == NULL)
            t = p->rchild; //p是原二叉树排序树的根
        else if(f->lchild == p)//p是f的左孩子
            f->lchild = p->rchild; //将p的右子树链到f的左链上
        else //p是f的右孩子
        f->rchild = p->rchild;
        free(p); //释放被删除的结点p
    }
    else//p有左子树
    {
        q = p;
        s = p->rchild;
        while(s->rchild) //在p的左子树中查找最右下结点
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
