#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    //��ָ������Ԫ�ظ���
    vector<int> v;
    //ָ��Ԫ�ظ���
    vector<double> v2(10);
    //����һ������n��Ԫ�ص�������������ÿ��Ԫ�ؾ���ָ���ĳ�ʼֵ
    vector<double> v3(10,3); //10��Ԫ�أ�ÿ��Ԫ�ص�ֵ��3
    v.push_back(23);//β������
    v.push_back(12);
    v.push_back(45);
    v.push_back(98);
    v.push_back(7);
    v[1] = 2;
    v[2] = 7;//�±귽ʽ����vectorԪ��
    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
    //����������
    cout<<"visit by iterator"<<endl;
    vector<int>::iterator it;
    for(it = v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    //����ǰ�����Ԫ�أ�ֵΪ8
    v.insert(v.begin(),8);
    //�ڵڶ���Ԫ��ǰ�����1
    v.insert(v.begin()+2,1);
    //β������
    v.insert(v.end(),41);
    //ɾ������Ԫ�أ���0��ʼ����
    v.erase(v.begin()+2);
    for(it = v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    //ɾ���ش�����1����5���������Ԫ��
    v.erase(v.begin()+1,v.begin()+5);
    for(it = v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    //���������С
    cout<<v.size()<<endl;
    //�������
    v.clear();
    return 0;
}
