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
    //���� '<' ������,�Զ����������
    bool operator < (const Info &a) const
    {
        //��score��С��������
        return a.score<score;
    }
};
int main()
{
    //����map����
    map<Info,int> m;
    //����Info�ṹ�����
    Info info;
    //����Ԫ�أ����ռ�ֵ�Դ�С����ڰ���
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
