#include<cstdio>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
int main()
{
    /*
    stack<int> s;
    int x;
    for(int i=0;i<5;i++)
    {
        cin>>x;
        s.push(x);
    }
    cout<<"Stack size:"<<s.size()<<endl;
    while(!s.empty())
    {
        cout<<"s.top()"<<s.top()<<endl;
        s.pop();
        cout<<"s.size()"<<s.size()<<endl;
    }
    */
    queue<char> s;
    for(int i=0;i<5;i++)
        s.push((char)65+i);
    while(!s.empty())
    {
        cout<<"front: "<<s.front()<<endl;
        s.pop();
    }
    return 0;
}
