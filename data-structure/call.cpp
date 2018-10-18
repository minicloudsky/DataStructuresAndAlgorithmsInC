#include<stdio.h>

typedef void (*fun)();

void f()
{
    printf("call ao ba ma\n");
}

void f2()
{
    printf("call f2\n");
}

int x=4;

int main()
{
    char s=1;
    int *x=(int*)&s;
    printf("%d\n",*x);
    printf("\n");
    printf("%p\n%p\n%p\n%p\n%p\n",main[0],main[1],main[2],main[3],main[4]);
    /*
    int *a[100];
    a[0]=(int*)f;
    a[1]=(int*)f2;
    printf("%p\n",f);
    printf("%p\n",f2);
    printf("%p\n",main);
    for(int i=0;i<2;i++){
        ((fun)a[i])();
    }*/

    return 0;
}
