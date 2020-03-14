#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    int num;
    for(int i=0;i<10;i++)
    {
        scanf("%d",&num);
        s.push(num);
    }
    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }
    return 0;
}
