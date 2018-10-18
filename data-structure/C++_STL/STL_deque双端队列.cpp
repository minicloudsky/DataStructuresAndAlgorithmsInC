#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int> d;
    //尾部插入
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_front(10);
    d.push_front(20);
    cout<<d[0]<<" "<<d[2]<<endl;
    //中间插入元素。不会增加新元素，只将原有的元素覆盖
    d.insert(d.begin()+1,88);
    cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<endl;
    //数组方式遍历
    for(int i=0;i<d.size();i++)
        cout<<d[i]<<" ";
    cout<<endl;
    //前向迭代器遍历
    deque<int>::iterator it;
    for(it = d.begin();it!=d.end();it++)
        cout<<(*it)<<" ";
    cout<<endl;
    deque<int>::reverse_iterator rit;
    for(rit = d.rbegin();rit!=d.rend();rit++)
        cout<<*rit<<" ";
    cout<<endl;
    //从头部删除元素
    d.pop_front();
    d.pop_front();
    for(it = d.begin();it!=d.end();it++)
        cout<<(*it)<<" ";
    cout<<endl;
    cout<<"after after delete: "<<endl;
    d.pop_back();
    d.pop_back();
      for(it = d.begin();it!=d.end();it++)
        cout<<(*it)<<" ";
    cout<<endl;
    //从中间删除元素，erase的参数为迭代器位置
    d.erase(d.begin()+1);
      for(it = d.begin();it!=d.end();it++)
        cout<<(*it)<<" ";
    cout<<endl;
    //clear清空deque对象
    d.clear();
    cout<<"size: "<<d.size()<<endl;
    return 0;
}
