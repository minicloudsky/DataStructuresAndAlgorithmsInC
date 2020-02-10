#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<set>
using namespace std;


struct fen
{
    int a;
    int b;
    fen(int a,int b){
        this->a=a;
        this->b=b;
    }

    fen& operator + (fen &s){
        a+=s.a;
        b+=s.b;
        return *this;
    }
};

int main()
{
    fen a(1,2);
    fen b(2,3);
    a=a+b;
    cout<<a.a<<" "<<a.b<<endl;
    return 0;
}
