#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
    list<int> l;
    //β��������Ԫ�أ������Զ�����
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    //ͷ��������Ԫ��
    l.push_front(111);
    list<int>::iterator it;
    it = l.begin();
    it++;//���������ֻ�ܽ���++��--���������ܽ���+n����
    for(it = l.begin();it!=l.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    //�������
    /*
    list<int>::reverse_iterator rit;
    for(rit = l.rbegin();rit!=l.rend();rit++)
        cout<<*rit<<" ";
    cout<<endl;

    //delete
    l.remove(1);
    //ɾ����βԪ��
    l.pop_front();
    l.pop_back();
    //erase ɾ��������λ����Ԫ��
    it = l.begin();
    it++;
    l.erase(it);
    //clear list
    l.clear();
     */
    cout<<l.size()<<endl;
    //find
    it = find(l.begin(),l.end(),1);
    cout<<"find: "<<*it<<endl;
    //����
    l.sort();
    for(it = l.begin();it!=l.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    l.push_back(222);
    l.push_back(222);
    //�޳��ظ�Ԫ��
    l.unique();
    cout<<"after unique: "<<endl;
    for(it = l.begin();it!=l.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}
