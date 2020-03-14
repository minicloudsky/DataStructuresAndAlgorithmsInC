#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;
struct Info
{
    string name;
    float score;
    //重载 '<' 操作符,自定义排序规则
    bool operator < (const Info &a) const
    {
        //按score从小到大排序
        return a.score<score;
    }
};
int main()
{
    //定义map对象
    map<Info,int> m;
    //定义Info结构体变量
    Info info;
    //插入元素，按照键值对大小放入黑白树
    info.name = "jack";
    info.score = 90;
    m[info] = 25;
    info.name = "jia";
    info.score = 87;
    m[info] = 23;
    map<Info,int>::iterator it;
    for(it = m.begin();it!=m.end();it++)
    {
        cout<<(*it).second<<" : ";
        cout<<((*it).first).name<<" : "<<((*it).first).score<<endl;
    }
    return 0;
}
