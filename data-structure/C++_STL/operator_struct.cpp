#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<set>
using namespace std;
struct Info
{
    string name;
    float score;
    bool operator < (const Info &a) const
    {
        //按score大小排序，如果要由小到大排列，使用>即可
        return a.score<score;
    }
};
int main()
{
    //定义元素类型为Info结构体的对象s
    set<Info> s;
    Info info;
    info.name = "Jack";
    info.score = 67.4;
    s.insert(info);
    info.name = "Tomi";
    info.score = 20.5;
    s.insert(info);
    info.name = "Tiny";
    info.score = 78.8;
    s.insert(info);
    set<Info>::iterator it;
    // 定义前向迭代器
    for(it = s.begin();it!=s.end();it++) //定义
        cout<<(*it).name<<" : "<<(*it).score<<endl;
    return 0;
}
