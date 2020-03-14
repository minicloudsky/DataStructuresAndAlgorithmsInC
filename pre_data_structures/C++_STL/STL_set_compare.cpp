#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<set>
using namespace std;
struct myCmp
{
    //重载 "()" 操作符，自定义排序规则
    bool operator() (const int &a,const int &b)
    {
        if(a!=b)
            return a>b;
        else
            return a>b;
    }
};

int main()
{
    //定义元素类型为int的集合对象s，当前没有任何元素，采用的比较函数是myCmp
    set<int,myCmp> s;
    s.insert(8);
    s.insert(1);
    s.insert(12);
    s.insert(6);
    s.insert(8); //重复元素不会插入
    set<int,myCmp>::iterator it;
    for(it = s.begin();it!=s.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}
