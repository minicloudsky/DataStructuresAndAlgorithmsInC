#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    map<string,float> m;
    m["Jack"] = 98.5;
    m["bomi"] = 78.4;
    m["kate"] = 35.6;
    map<string,float>::iterator it;
    for(it = m.begin();it!=m.end();it++)
        cout<<(*it).first<<" : "<<(*it).second<<endl;
    //delete
    map<int,char> m1;
    m1[23] = 'd';
    m1[12] = 'a';
    m1[2] = 'g';
    //删除键值为2的元素
    m1.erase(2);
    map<int,char>::iterator i;
    //find
    i = m1.find(12);
    if(i!=m1.end())
        cout<<(*i).first<<" "<<(*i).second<<endl;
    else
        cout<<"error"<<endl;
    for(i=m1.begin();i!=m1.end();i++)
        cout<<(*i).first<<" : "<<(*i).second<<endl;
    //反向遍历
    cout<<"reverse traverse"<<endl;
    map<int,char>::reverse_iterator rit;
    for(rit = m1.rbegin();rit!=m1.rend();rit++)
        cout<<(*rit).first<<" : "<<(*rit).second<<endl;

    return 0;
}
