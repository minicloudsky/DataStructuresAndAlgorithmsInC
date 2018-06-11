#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void print(struct node *l);

void* insert(struct node **l,int x)
{
    if(*l==NULL){
        *l=(struct node *)malloc(sizeof(struct node));
        if(!*l){
            exit(0);
        }
        l[0]->data=x;
        l[0]->next=NULL;
    }else{
        struct node *p=(struct node *)malloc(sizeof(struct node));
        p->data=x;
        p->next=*l;
        l[0]=p;
    }

    return (void*)&print;
}

void print(struct node *l)
{
    for(;l;l=l->next){
        cout<<l->data<<" ";
    }
    cout<<endl;
}

void del(struct node **l,int x)
{
    if(!l[0]){
        return ;
    }else if((*l)->data==x){
        struct node *p=l[0];
        l[0]=(*l)->next;
        free(p);
    }

    /*
    Á½Ñ¡Ò»
    */
    //del(&l[0]->next,x);
    del(&(*l)->next,x);
}

int main()
{
    struct node *l=NULL;
    int n,x;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        if(x!=0){
            insert(&l,x);
        }else{
            (*(void (*)(struct node*))(insert(&l,x)))(l);
        }

    }

    print(&l[0]);

    cin>>x;
    del(&l,x);
    print(l);

    return 0;
}
