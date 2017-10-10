#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node *avl;
typedef struct node *position;

struct node
{
    int data;
    position left;
    position right;
    int h;
};

int high(position p)
{
    if(p==NULL)
        return -1;
    return p->h;
}

position findmin(avl t)
{
    if(t==NULL)
        return NULL;
    while(t&&t->left)
        t=t->left;
    return t;
}

position findmax(avl t)
{
    if(t==NULL)
        return NULL;
    while(t->right)
        t=t->right;
    return t;
}

position singleft(position k3)
{
    position k2=k3->left;
    k3->left=k2->right;
    k2->right=k3;
    k3->h=1+max(high(k3->left),high(k3->right));
    k2->h=1+max(high(k2->left),high(k3));

    return k2;
}

position singright(position k3)
{
    position k2=k3->right;
    k3->right=k2->left;
    k2->left=k3;
    k3->h=1+max(high(k3->left),high(k3->right));
    k2->h=1+max(high(k2->right),high(k3));

    return k2;
}

position doubleleft(position k3)
{
    k3->left=singright(k3->left);
    return singleft(k3);
}

position doubleright(position k3)
{
    k3->right=singleft(k3->right);
    return singright(k3);
}

avl _insert(avl t,int x)
{
    if(t==NULL)
    {
        t=(position)malloc(sizeof(struct node));
        if(t==NULL)
        {
            cerr<<"no memory"<<endl;
            return NULL;
        }
        t->data=x;
        t->left=t->right=NULL;
        t->h=0;
    }
    else if(x<t->data)
    {
        t->left=_insert(t->left,x);
        if(high(t->left)-high(t->right)==2)
        {
            if(x<t->left->data)
                t=singleft(t);
            else  t=doubleleft(t);
        }
    }
    else if(x>t->data)
    {
        t->right=_insert(t->right,x);
        if(high(t->right)-high(t->left)==2)
        {
            if(x>t->right->data)
                t=singright(t);
            else  t=doubleright(t);
        }
    }

    t->h=1+max(high(t->left),high(t->right));
    return t;
}

void dfs(avl l)
{
    if(l==NULL)
        return ;
    cout<<l->data<<" "<<l->h<<endl;
    if(l->left)
        dfs(l->left);
    if(l->right)
        dfs(l->right);
}

void _free(avl l)
{
    if(l==NULL)
        return ;
    if(l->left)
        _free(l->left);
    if(l->right)
        _free(l->right);
    cout<<l->data;
    free(l);
    l=NULL;
    cout<<" ok delete"<<endl;
}

int abs(int x)
{
    return x>0?x:-x;
}

position fix(position k2)
{
    if(high(k2->left)>high(k2->right))
    {
        if(high(k2->left->left)>high(k2->left->right))
            k2=singleft(k2);
        else  k2=doubleleft(k2);
    }
    else if(high(k2->right)>high(k2->left))
    {
        if(high(k2->right->right)>high(k2->right->left))
            k2=singright(k2);
        else  k2=doubleright(k2);
    }
    return k2;
}

avl _delete(avl t,int x)
{
    if(t==NULL)
    {
        cerr<<"tree is empty"<<endl;
        exit(3);
    }
    else if(x<t->data)
        t->left=_delete(t->left,x);
    else if(x>t->data)
        t->right=_delete(t->right,x);
    else if(t->left&&t->right)
    {
        position p=findmin(t->right);
        t->data=p->data;
        t->right=_delete(t->right,p->data);
    }
    else
    {
        position p=t;
        if(t->left==NULL)
            t=t->right;
        else if(t->right==NULL)
            t=t->left;
        free(p);
        p=NULL;
    }

    if(t)
    {
        t->h=max(high(t->left),high(t->right))+1;
        if(abs(high(t->left)-high(t->right))>=2)
        {
            t=fix(t);
            t->h=1+max(high(t->left),high(t->right));
        }
    }

    return t;
}

int main()
{
    avl t=NULL;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        t=_insert(t,x);
    }

    dfs(t);

    cin>>n;
    while(n--){
        cin>>x;
        t=_delete(t,x);
    }

    _free(t);

    return 0;
}
