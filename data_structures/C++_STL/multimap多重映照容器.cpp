#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    //允许插入重复键值对
    map<string,double> m;
    m.insert(pair<string,double>("Jack",30.3));
    m.insert(pair<string,double>("tony",3.3));
    m.insert(pair<string,double>("full",31));
    //插入重复的
    m.insert(pair<string,double>("Jack",89.1));
    multimap<string,double>::iterator it;
    for(it = m.begin();it!=m.end();it++)
        cout<<(*it).first<<" : " <<(*it).second<<endl;
    m.erase("Jack");
    cout<<"the elements after deleted:"<<endl;
    for(it = m.begin();it!=m.end();it++)
        cout<<(*it).first<<" : " <<(*it).second<<endl;
    cout<<"search: "<<endl;
    it = m.find("full");
    if(it!=m.end())
        cout<<(*it).first<<" "<<(*it).second<<endl;
    return 0;
}
