#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <cstring>
using namespace std;

#define N 100000000
char a[N];

void f(char *a)
{
    int t=strlen(a);
    for(int i=0;i<t;i++){

    }
    cout<<"ok"<<endl;
}

int main()
{
    for(int i=0;i<N/4;i++){
        a[i]=1;
    }

    cout<<"memset "<<endl;
    f(a);

    return 0;
}
