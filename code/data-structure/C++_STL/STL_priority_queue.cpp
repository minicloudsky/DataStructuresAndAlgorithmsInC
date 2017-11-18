#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int> pq;
    pq.push(8);
    pq.push(2);
    pq.push(5);
    cout<<pq.size()<<endl;
    while(pq.empty()!=true)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    return 0;
}
