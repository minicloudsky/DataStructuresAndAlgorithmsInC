#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define eletype int
using namespace std;
typedef avl *position;
typedef struct avl
{
    eletype element;
    position left;
    position right;
    int h;
};
int abs(int a,int b)
{
    int x = a-b;
    return x<0? -x : x;
}
int Max(int a,int b)
{
    return a>b? a:b;
}
position findmin(position t)
{
    if(t==NULL)
        return NULL;
    while(t->left!=NULL)
        t = t->left;
    return t;
}
position findmax(position t)
{
    if(t==NULL)
        return NULL;
    while(t->right!=NULL)
        t = t->right;
    return t;
}
int Height(position p)
{
    if(p==NULL)
        return -1;
    else
        return p->h;
}
avl Insert(eletype x,position t)
{
    if(t==NULL)
    {
        t = (avl*)malloc(sizeof(avl));
        if(t==NULL)
            printf("Out of space!\n");
    }
    else if(x<t->element)
    {
        t->left = Insert(x,t->left);
        if(abs(Height(t->left)-Height(t->right))==2)
        {
            if(x<t->left->element)
                t = SingleRotateLeft(t);
            else
                t = DoubleRotateLeft(t);
        }
    }
    else if(x>t->element)
    {
        t->right = Insert(x,t->right);
        if((Height(t->right)-Height(t->left))==2)
        {
            if(x>t->right->element)
                t = SingleRotateRight(t);
            else
                t = DoubleRotateRight(t);
        }
    }
    // x is in the tree already ;we'll do nothing.
    else
        t->h = Max(t->left,t->right)+1;
    return t;
}

/*
This function can be called only if k2 has a left child
perform a rotate between a node(k2) ans its child
update heights,then return new root
*/
position SingleRotateLeft(position k2)
{
    position k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->h = Max(Height(k2->left),Height(k2->right))+1;
    k1->h = Max(Height(k1->left),Height(k1->right))+1;
    return k1;// new root
}
position SingleRotateRight(position k1)
{
    position k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k2->h = Max(height(k2->left),Height(k2->right)) + 1;
    k1->h = Max(Height(k1->left),Height(k1->right)) + 1;
    return k2;
}
position DoubleRotateLeft(position k3)
{
    // rotate between k1 and k2
    k3->left = SingleRotateRight(k3->left);
    // rotate between k3 and k2
    return SingleRotateLeft(k3);
}
position DoubleRotateRight(position k3)
{
    k3->right = SingleRotateLeft(k3->right);
    return SingleRotateRight(k3->right);
}
void dfs(position t)
{
    if(t==NULL)
        return;
    if(t->left)
        dfs(t->left);
    cout<<t->element<<" "<<"h :"<<t->h<<endl;
    if(t->right)
        dfs(t->right);
}
int main()
{

    return 0;
}
