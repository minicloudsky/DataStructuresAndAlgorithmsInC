#include<stdbool.h>
#define maxsize 10
typedef int datatype;
typedef struct Stack
{
    datatype data[maxsize];
    int top;
};
void init(tack S)
{
    s.top=-1;
}
bool Empty()
{
    if(s.top==-1)
        return true;
    else
        return false;
}
bool full()
{
    if(s.top==maxsize-1)
        return true;
    else
        return false;
}
void Push(datatype element)
{
    if(!full())
    {
        s.top++;
        s.data[s.top]=element;
    }
    else
        printf("Õ»Âú\n");
}
void Pop()
{
    if(!Empty())
        s.top--;
    else
        printf("Õ»¿Õ\n");
}

datatype Top()
{
    if(!Empty())
        return s.data[s.top];
    else
        printf("Õ»¿Õ\n");
}
void Destroy()
{
    s.top=-1;
}
