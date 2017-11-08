#include<stdio.h>
#include<stdlib.h>
typedef struct avl *position;
typedef struct avl *avlTree;
typedef struct avl
{
    int data;
    position left;
    position right;
    int h;
}
int max(int a,int b)
{
    return a>b? a:b;
}
int height(avlTree t)
{
    if(t==NULL)
        return -1;
    else
        return t->h;
}
position left_left(avlTree k2)
{
    avlTree k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left),height(k2->right)) + 1;
    k1->h = max(height(k1->left),k2->h) + 1;
    k2->h = max(height(k2->left),height(k2->right)) +1;
    return k1;
}
position DoubleLeft(position k3)
{
    k3->left =
}
int main()
{
    int *p=f1();
    f2();
    printf("%d %d %d\n",p[0],p[1],p[2]);
    return 0;
}
