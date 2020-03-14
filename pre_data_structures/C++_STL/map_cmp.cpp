#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;
struct myCmp
{
    bool operator()(const int &a,const int &b)
    {
        if(a!=b)
            return a>b;
        else
            return a>b;
    }
};
int main()
{
    map<int,char,myCmp> m;
    m[0] = 'a';
    m[1] = 'b';
    m[2] = 'c';
    map<int ,char,myCmp>::iterator it;
    for(it = m.begin();it!=m.end();it++)
        cout<<(*it).first<<" : "<<(*it).second<<endl;
    return 0;
}
