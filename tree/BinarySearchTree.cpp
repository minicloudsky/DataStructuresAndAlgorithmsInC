#include<stdlib.h>
#include<stdio.h>
#define eletype int
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
struct TreeNode
{
    eletype element;
    SearchTree Left;
    SearchTree Right;
};
SearchTree MakeEmpty(SearchTree T)
{
    if(T!=NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}
Position Find(eletype X,SearchTree T)
{
    if(T==NULL)
        return NULL;
    if(X<T->element)
        return Find(X,T->Left);
    else if(X>T->element)
        return Find(X,T->Right);
    else
        return T;
}
Position FindMin(SearchTree T)
{
    if(T == NULL)
        return NULL;
    else if(T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}
Position FindMax(SearchTree T)
{
    if(T!=NULL)
    {
        while(T->Right!=NULL)
            T = T->Right;
    }
    return T;
}
SearchTree Insert(eletype X,SearchTree T)
{
    if(T == NULL)
    {
        T = (TreeNode*)malloc(sizeof(TreeNode));
        if(T == NULL)
            printf("Fatal error.\n");
        else
        {
            T->element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if(X < T->element)
        T->Left = Insert(X,T->Left);
    else if(X > T->element)
        T->Right = Insert(X,T->Right);
    return T;
}

void PreOrder(SearchTree T)
{
    if(T!=NULL)
    {
        printf("%d\n",T->element);
        PreOrder(T->Left);
        PreOrder(T->Right);
    }
}

void InOrder(SearchTree T)
{
    if(T!=NULL)
    {
        InOrder(T->Left);
        printf("%d\n",T->element);
        InOrder(T->Right);
    }
}

void PostOrder(SearchTree T)
{
    if(T!=NULL)
    {
        PostOrder(T->Left);
        PostOrder(T->Right);
        printf("%d\n",T->element);
    }
}

SearchTree Delete(eletype X,SearchTree T)
{
    Position TmpCell;
    if(T == NULL)
        printf("Element not Found.\n");
    else if(X < T->element)
        T->Left = Delete(X,T->Left);
    else if(X>T->element)
        T->Right = Delete(X,T->Right);
    else if(T->Left && T->Right)// Two children
    {
        // Replace with smallest in right subtree
        TmpCell = FindMin(T->Right);
        T->element = TmpCell->element;
        T->Right = Delete(T->element,T->Right);
    }
    else // one or zero children
    {
        TmpCell = T;
        if(T->Left == NULL)
            T = T->Right;
        else if(T->Right == NULL)
            T = T->Left;
        free(TmpCell);
    }
    return T;
}

void leaf(Position T)
{
    if(T==NULL)  return ;
    if(T->Left==NULL && T->Right==NULL)
    {
        printf("%d\n",T->element);
    }
    if(T->Left)
        leaf(T->Left);
    if(T->Right)
        leaf(T->Right);
}

int high(Position T)
{
    int hl,hr,max;
    if(T!=NULL)
    {
        hl = high(T->Left);
        hr = high(T->Right);
        max = hl>hr ? hl: hr;
        return max+1;
    }
    else
        return 0;
}

Position Deletes(Position T,eletype X)
{
    Position TmpCell;
    if(T==NULL)
        printf("No such element.\n");
    else if(X>T->element)
        T->Right = Deletes(T->Right,X);
    else if(X<T->element)
        T->Left = Deletes(T->Left,X);
    else if(T->Left &&T->Right)
    {
        TmpCell = FindMin(T->Right);
        T->element = TmpCell->element;
        T->Right = Deletes(T->Right,X);
    }
    else
    {
        TmpCell = T;
        if(T->Left==NULL)
            T = T->Right;
        else if(T->Right==NULL)
            T = T->Left;
        free(TmpCell);
    }
    return T;
}

void PrintTree(Position T,int high)
{
    if(T==NULL)
        return;
    PrintTree(T->Right,high+1);
    for(int i=0; i<high; i++)
        printf(" ");
    printf("%d\n",T->element);
    PrintTree(T->Left,high+1);
}

Position My_Insert(Position T,eletype X)
{
    if(T==NULL)
    {
        T = (Position) malloc(sizeof(Position));
        if(T==NULL)
            printf("memory error\n");
        else
        {
            T->element = X;
            T->Left = T->Right =NULL;
        }
    }
    else if(X > T->element)
        T->Right = My_Insert(T->Right,X);
    else if(X < T->element)
        T->Left = My_Insert(T->Left,X);
    return T;
}

int main()
{
    int n,x;

    printf("Input node number:\n");
    scanf("%d",&n);
    TreeNode *T = NULL;

    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        T = My_Insert(T,x);
    }
    InOrder(T);
    return 0;
}

