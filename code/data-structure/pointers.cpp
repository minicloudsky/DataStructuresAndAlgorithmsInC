#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int *fun()
{
    int a[]={1,2,3,4,5,6};
    return a;
}

int *fun1()
{
    int a[]={2,3,4,5,6,7};
    return a;
}

void print(int *a)
{
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int *a=fun();
    fun1();
    print(a);
    return 0;
}
