#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;
    //���
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    //��ȡ����Ԫ��
    cout<<q.front()<<endl;
    //��ȡ��βԪ��
    cout<<q.back()<<endl;
    while(q.empty()!=true)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}
