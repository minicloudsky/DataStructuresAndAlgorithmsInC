#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<set>
using namespace std;
struct myCmp
{
    //���� "()" ���������Զ����������
    bool operator() (const int &a,const int &b)
    {
        if(a!=b)
            return a>b;
        else
            return a>b;
    }
};

int main()
{
    //����Ԫ������Ϊint�ļ��϶���s����ǰû���κ�Ԫ�أ����õıȽϺ�����myCmp
    set<int,myCmp> s;
    s.insert(8);
    s.insert(1);
    s.insert(12);
    s.insert(6);
    s.insert(8); //�ظ�Ԫ�ز������
    set<int,myCmp>::iterator it;
    for(it = s.begin();it!=s.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}
