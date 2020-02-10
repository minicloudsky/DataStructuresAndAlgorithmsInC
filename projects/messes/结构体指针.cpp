#include<stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int arr[12];
    int top;
};

void print(int s)
{
    printf("%d\n",s);
}

int main()
{
       /*
    int a;
    int b;
    a=1;
    printf("%p\n",&a);
    int *p=&b;
    printf("%p\n",p);
    p=(int*)malloc(sizeof(int));
    printf("%p\n",p);
  */
  Node p;
  p.arr[0] = 100;
  p.arr[1] = 200;
  p.top = -1;
  printf("%p\n",&p);
  printf("%d %d %d\n",p.arr[0],p.arr[1],p.top);
  Node *s;
  s=(Node*)malloc(sizeof(Node));
  s->top=0;
  s->arr[0] = -100;
  s->arr[1] = -200;
  printf("%d\n",s->top);
  printf("%d %d %d\n",s->arr[0],s->arr[1],sizeof(s));
    return 0;
}
