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
        //��score��С�������Ҫ��С�������У�ʹ��>����
        return a.score<score;
    }
};
int main()
{
    //����Ԫ������ΪInfo�ṹ��Ķ���s
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
    // ����ǰ�������
    for(it = s.begin();it!=s.end();it++) //����
        cout<<(*it).name<<" : "<<(*it).score<<endl;
    return 0;
}
