#include<stdlib.h>
#include<stdio.h>
#define eletype int
typedef struct node
{
    eletype data;
    node *left;
    node *right;
};
node *insert(node *t,eletype x)
{
    if(t==NULL)
    {
        t = (node*) malloc(sizeof(node));
        t->data = x;
        t->left=t->right= NULL;
    }
    else if(x < t->data)
    {
        t->left = insert(t->left,x);
    }
    else if(x > t->data)
    {
        t->right = insert(t->right,x);
    }
    return t;
}

void dfs(node *t)
{
    if(t==NULL) return;
    dfs(t->left);
    printf("%d\n",t->data);
    dfs(t->right);
}

void memset(void *a,int x,int size)
{
    char *s=(char *)a;
    for(int i=0;i<size;i++){
        s[i]=x;
    }
}

int main()
{
    int a;
    memset(&a,1,sizeof(int));
    printf("%d\n",a);
    return 0;
}
