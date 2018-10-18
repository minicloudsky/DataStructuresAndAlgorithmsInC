#include<iostream>
#include<stdlib.h>
#include <stdio.h>
using namespace std;

class A
{
public:
    A(int x,int y){
        this->x=x;
        this->y=y;
    }

    void print();

    void prints()
    {
        void *p=(void *)&print;
        printf("%p\n",p);
    }

    int x;
    int y;
};

void A::print(){
    cout<<"hello"<<endl;
}

int main()
{
    A a(1,2);
    a.prints();
    printf("%p\n",&a);
    return 0;
}
