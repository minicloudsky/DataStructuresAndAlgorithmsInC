#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<set> // based on red-black tree
using namespace std;
int main()
{
    set<int>s ;
    s.insert(2);
    s.insert(4);
    s.insert(77);
    s.insert(5);
    s.insert(5); //有重复元素不会执行
    set<int>::iterator it;
    for(it = s.begin();it!=s.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    set<int>::reverse_iterator rit;
    for(rit = s.rbegin();rit!=s.rend();rit++)
        cout<<*rit<<" ";
    cout<<endl;
    //delete
    s.erase(5);
    //size
    cout<<s.size()<<endl;
    // find
    it = s.find(2);
    if(it!=s.end())
        cout<<"*it "<<*it<<endl;
    else
        cout<<"not found"<<endl;
    it = s.find(77);
    if(it!=s.end())
        cout<<"*it "<<*it<<endl;
    else
        cout<<"not found"<<endl;

    return 0;
}
