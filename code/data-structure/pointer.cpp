#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string.h>
using namespace std;

static int ZERO=0;

class A
{
public:
    A(){
        if(count==NULL)
            count=(int *)malloc(sizeof(int));
        a=new int;
        (*count)++;
    }
    A(A &a){
        ++(*count);
    }

    ~A()
    {
        --(*count);
        if((*count)==0){
            cout<<"delete"<<endl;
            delete a;
            delete count;
        }
    }

    int *count;
    int *a;
};

void f()
{
    A a;
    cout<<a.count<<endl;
}

int main()
{
    /*
    char (**p)[10];
    char a[10];
    char b[10];
    cin>>a;
    cin>>b;
    p=(char(**)[10])malloc(2*sizeof(char(*)[10]));
    p[0]=&a;

    p[1]=&b;

    cout<<p[0][0]<<endl;

    cout<<p[1][0]<<endl;

*/
    A a;


    //cout<<b.count<<endl;
    return 0;
}
