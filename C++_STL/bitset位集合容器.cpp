#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<bitset>
using namespace std;
/*
bitset 是一个bit位集合的序列容器，每个元素只占一个bit位，取值0或1，因而很节省内存空间

*/
int main()
{
    bitset<10> b;
    b[1] = 1;
    b[2] = 1;
    b[3] = 0;
    for(int i=0;i<b.size()-1;i++)
        cout<<b[i];
    cout<<endl;
    //采用set方法，一次性的将元素设置为1
    b.set();
    for(int i=0;i<b.size()-1;i++)
        cout<<b[i];
    cout<<endl;
    //采用set(pos),将pos位置置位1
    b.set(2,1);

    //reset(pos),将pos社会为0
    b.reset(2);
    b.reset(4);
    for(int i=0;i<b.size()-1;i++)
        cout<<b[i];
    cout<<endl;
    //直接输出所有元素
    cout<<"all elements:"<<endl<<b<<endl;
    return 0;
}
