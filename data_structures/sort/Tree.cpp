#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct Node
{
    DataType data;
    struct Node *Lchild;
    struct Node *rchild;
}BiNode,*BiTree;
void PreOrder(BiTree root)
{
    if(root!=NULL){
        Visit(root->data);
        PreOrder();
    }

}
int main()
{

    return 0;
}
