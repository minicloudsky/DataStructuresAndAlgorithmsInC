#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(const int &a,const int &b)
{
    if(a!=b)
        return a>b;
    else
        return a>b;
}
int main()
{
    vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(i);
    //反向排列从开始到结尾
    reverse(v.begin(),v.end());
    vector<int>::iterator it;
    for(it = v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    v.push_back(45);
    v.push_back(-9);
    v.push_back(-12);
    //升序排序
    sort(v.begin(),v.end());
    cout<<endl;
    for(it = v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    //按照cmp函数降序排序
    sort(v.begin(),v.end(),cmp);
    for(it = v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    // vector size
    cout<<v.size()<<endl;
    //vector is empty ?
    cout<<v.empty()<<endl;
    //clear
    v.clear();
    return 0;
}
