#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define eletype int
using namespace std;
typedef struct TreeNode *PriorityQueue;
struct TreeNode
{
    eletype element;
    PriorityQueue *left;
    PriorityQueue *right;
    int npl;// 0路径长，npl(x) 为从x到一个没有两个儿子节点的最短路径的长,npl(NULL) = -1
};

int IsEmpty(PriorityQueue h)
{
    return h==NULL;
}
PriorityQueue Merge1(PriorityQueue h1,PriorityQueue h2)
{
    if(h1->left==NULL) // Single node
        h1->left = h2; // h1->right is already NULL
        // h1->npl is already 0
    else
    {
        h1->right = Merge(h1->right,h2);
        if(h1->left->npl<h1->right->npl)
            SwapChildren(h1);
    }
    return h1;
}
PriorityQueue Merge(PriorityQueue h1,PriorityQueue h2)
{
    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;
    if(h1->element<h2->element)
        return Merge1(h1,h2);
    else
        return Merge1(h2,h1);
}

PriorityQueue Insert1(eletype x,PriorityQueue h)
{
    PriorityQueue singlenode;
    singlenode = (TreeNode*) malloc(sizeof(struct TreeNode));
    if(singlenode==NULL)
        printf("Out of space\n");
    else
    {
        singlenode->element = x;
        singlenode->npl = 0;
        singlenode->left = singlenode->right = NULL;
        h = Merge(singlenode,h);
    }
    return h;
}
PriorityQueue DeleteMin(PriorityQueue h)
{
    PriorityQueue leftheap,rightheap;
    if(IsEmpty(h))
    {
        printf("Priority queue is empty\n");
        return h;
    }
    leftheap = h->left;
    rightheap = h->right;
    free(h);
    return Merge(leftheap,rightheap);
}
int main()
{
    return 0;
}
