#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int> d;
    //β������
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_front(10);
    d.push_front(20);
    cout<<d[0]<<" "<<d[2]<<endl;
    //�м����Ԫ�ء�����������Ԫ�أ�ֻ��ԭ�е�Ԫ�ظ���
    d.insert(d.begin()+1,88);
    cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<endl;
    //���鷽ʽ����
    for(int i=0;i<d.size();i++)
        cout<<d[i]<<" ";
    cout<<endl;
    //ǰ�����������
    deque<int>::iterator it;
    for(it = d.begin();it!=d.end();it++)
        cout<<(*it)<<" ";
    cout<<endl;
    deque<int>::reverse_iterator rit;
    for(rit = d.rbegin();rit!=d.rend();rit++)
        cout<<*rit<<" ";
    cout<<endl;
    //��ͷ��ɾ��Ԫ��
    d.pop_front();
    d.pop_front();
    for(it = d.begin();it!=d.end();it++)
        cout<<(*it)<<" ";
    cout<<endl;
    cout<<"after after delete: "<<endl;
    d.pop_back();
    d.pop_back();
      for(it = d.begin();it!=d.end();it++)
        cout<<(*it)<<" ";
    cout<<endl;
    //���м�ɾ��Ԫ�أ�erase�Ĳ���Ϊ������λ��
    d.erase(d.begin()+1);
      for(it = d.begin();it!=d.end();it++)
        cout<<(*it)<<" ";
    cout<<endl;
    //clear���deque����
    d.clear();
    cout<<"size: "<<d.size()<<endl;
    return 0;
}
