#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *
add(struct node *list_head,int x)
{
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    if(!tmp){
        cout<<"asda"<<endl;
    }
    tmp->data=x;

    tmp->next=list_head;

    list_head=tmp;

    return list_head;
}

struct node *rever(struct node *head,struct node *new_head)
{
    if(head){
        new_head=add(new_head,head->data);
        return rever(head->next,new_head);
    }else{
        return new_head;
    }
}

void print(struct node *l)
{
    if(l!=NULL){
        cout<<l->data<<" ";
        print(l->next);
    }else{
        cout<<endl;
        return ;
    }
}

int main()
{
    struct node *list_head=NULL;

    int n,x;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>x;
        list_head=add(list_head,x);
    }


    print(list_head);

    list_head=rever(list_head,NULL);
    print(list_head);
    return 0;
}
