#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct myCmp
{
    //重载 '()' 操作符定义运算符优先级
    bool operator() (const int &a,const int &b)
    {
        return a>b;
    }
};
int main()
{
    priority_queue<int,vector<int>,myCmp> pq;
    pq.push(45);
    pq.push(4);
    pq.push(3);
    pq.push(-1);
    while(pq.empty()!=true)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    return 0;
}
