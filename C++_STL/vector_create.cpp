#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    //不指定容器元素个数
    vector<int> v;
    //指定元素个数
    vector<double> v2(10);
    //创建一个具有n个元素的向量容器对象，每个元素具有指定的初始值
    vector<double> v3(10,3); //10个元素，每个元素的值是3
    v.push_back(23);//尾部扩张
    v.push_back(12);
    v.push_back(45);
    v.push_back(98);
    v.push_back(7);
    v[1] = 2;
    v[2] = 7;//下标方式访问vector元素
    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
    //迭代器访问
    cout<<"visit by iterator"<<endl;
    vector<int>::iterator it;
    for(it = v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    //在最前面插入元素，值为8
    v.insert(v.begin(),8);
    //在第二个元素前面插入1
    v.insert(v.begin()+2,1);
    //尾部插入
    v.insert(v.end(),41);
    //删除两个元素，从0开始计数
    v.erase(v.begin()+2);
    for(it = v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    //删除地带器第1到底5区间的所有元素
    v.erase(v.begin()+1,v.begin()+5);
    for(it = v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    //输出向量大小
    cout<<v.size()<<endl;
    //清空向量
    v.clear();
    return 0;
}
