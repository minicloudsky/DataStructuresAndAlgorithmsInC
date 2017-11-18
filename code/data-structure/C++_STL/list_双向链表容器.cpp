#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
    list<int> l;
    //尾部插入新元素，链表自动扩张
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    //头部插入新元素
    l.push_front(111);
    list<int>::iterator it;
    it = l.begin();
    it++;//链表迭代器只能进行++或--操作，不能进行+n操作
    for(it = l.begin();it!=l.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    //反向遍历
    /*
    list<int>::reverse_iterator rit;
    for(rit = l.rbegin();rit!=l.rend();rit++)
        cout<<*rit<<" ";
    cout<<endl;

    //delete
    l.remove(1);
    //删除首尾元素
    l.pop_front();
    l.pop_back();
    //erase 删除迭代器位置上元素
    it = l.begin();
    it++;
    l.erase(it);
    //clear list
    l.clear();
     */
    cout<<l.size()<<endl;
    //find
    it = find(l.begin(),l.end(),1);
    cout<<"find: "<<*it<<endl;
    //排序
    l.sort();
    for(it = l.begin();it!=l.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    l.push_back(222);
    l.push_back(222);
    //剔除重复元素
    l.unique();
    cout<<"after unique: "<<endl;
    for(it = l.begin();it!=l.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}
