#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    //入队
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    //读取队首元素
    cout<<q.front()<<endl;
    //读取队尾元素
    cout<<q.back()<<endl;
    while(q.empty()!=true)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}
