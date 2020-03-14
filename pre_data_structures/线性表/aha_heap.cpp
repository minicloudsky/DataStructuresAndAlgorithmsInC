#include<stdio.h>
#include<iostream>
using namespace std;
int h[101];
int n;
void down(int i)
{
    int t,flag = 0;
    while(i*2<=n && flag==0)
    {
        if(h[i] > h[i*2])
            t = i*2;
        else
            t = i;
        if(2*i+1<=n)
        {
            if(h[t]>h[2*i+1])
                t = 2*i+1;
        }
        if(t!=i)
        {
            swap(t,i);
            i = t;
        }
        else
            flag = 1;
    }
    return ;
}
void create()
{
    int i;
    for(i=n/2;i>=1;i--)
    {
        down(i);
    }
    return ;
}
int deletemax()
{
    int t;
    t = h[1];
    h[1] = h[n];
    n--;
    down(1);
    return t;
}
int main()
{
    int i,num;
    scanf("%d",&num);
    for(i=1;i<=num;i++)
        scanf("%d",&h[i]);
    n = num;
    create();
    for(i = 1;i<=num;i++)
        printf("%d\n",deletemax());
    return 0;
}
