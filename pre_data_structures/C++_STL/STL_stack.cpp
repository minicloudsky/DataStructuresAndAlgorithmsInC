#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(9);
    // get_top
    cout<<s.top()<<endl;
    // is_empty()
    cout<<s.empty()<<endl;
    while(s.empty()!=true)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}
