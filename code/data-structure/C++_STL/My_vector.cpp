#include<stdio.h>
#include<stdlib.h>
#include<iostream>
//向量需要
#include<vector>
//accumulate算法需要
#include<numeric>
using namespace std;
int main()
{
    vector<int> v;
    int i;
    for(i = 0;i<10;i++)
        v.push_back(i);
    //使用迭代器遍历所有元素
    for(vector<int>::iterator it = v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    cout<<accumulate(v.begin(),v.end(),0)<<endl;

    return 0;
}
