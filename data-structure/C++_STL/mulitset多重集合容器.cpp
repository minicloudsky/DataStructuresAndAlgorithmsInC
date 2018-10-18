//multiset多重集合容器，与set不同的是，multiset允许重复元素键值插入
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<set>
using namespace std;
int main()
{
    multiset<string> ms;
    ms.insert("324");
    ms.insert("111");
    ms.insert("222");
    multiset<string>::iterator it;
    for(it = ms.begin();it!=ms.end();it++)
        cout<<*it<<endl;
    int n = ms.erase("123");
    cout<<"Total deleted: "<<n<<endl;
    cout<<"all elements after deleted :"<<endl;
    for(it = ms.begin();it!=ms.end();it++)
        cout<<*it<<endl;
    it = ms.find("111");
    cout<<"find: "<<endl;
    if(it!=ms.end())
        cout<<*it<<endl;
    else
        cout<<"not found";
    return 0;
}
