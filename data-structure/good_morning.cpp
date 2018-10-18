/* good morning */
#include<stdio.h>

struct zone
{
    struct zone *front;
    struct zone *next;
};

struct node
{
    int data;
    char ch;
    struct zone link;
};

int main()
{
    /*
    struct node s;
    s.data=1;
    s.ch='a';
    struct node h;
    h.ch='b';
    h.data=11;
    s.link.next=&h.link;
    h.link.front=&s.link;
    h.link.next=NULL;
    for(struct zone *p=&s.link;p;p=p->next){
        char *pc=(char *)p;
        printf("%d\n",*((int*)(pc-8)));
    }
    */

    double loop =5.0730449399930849e+45;
    printf("%d\n",sizeof(double));
/*
    for(char *p=(char*)&loop,i=0;i<sizeof(double)/sizeof(char);p++,i++){
        printf("%c",*p);
    }
*/

    for(int i=sizeof(double);i--; i>=0)
        printf("%c",*((char*)(&loop)+i));
    return 0;
}
/* good night */

