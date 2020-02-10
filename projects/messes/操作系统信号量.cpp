#include<stdio.h>
#include<pthread.h>
typedef struct
{
    int value;
    list of process *L;
}semphore;
void wait(static semphore s)
{
    s.value--;
    if(s.value<0)
    {
        block(s.L);
    }
}

void signal(static semphore s)
{
    s.value++;
    if(s.value<=0)
    {
        wakeup(s.L);
    }
}
