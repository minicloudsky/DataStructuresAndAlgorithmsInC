#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<bitset>
using namespace std;
/*
bitset ��һ��bitλ���ϵ�����������ÿ��Ԫ��ֻռһ��bitλ��ȡֵ0��1������ܽ�ʡ�ڴ�ռ�

*/
int main()
{
    bitset<10> b;
    b[1] = 1;
    b[2] = 1;
    b[3] = 0;
    for(int i=0;i<b.size()-1;i++)
        cout<<b[i];
    cout<<endl;
    //����set������һ���ԵĽ�Ԫ������Ϊ1
    b.set();
    for(int i=0;i<b.size()-1;i++)
        cout<<b[i];
    cout<<endl;
    //����set(pos),��posλ����λ1
    b.set(2,1);

    //reset(pos),��pos���Ϊ0
    b.reset(2);
    b.reset(4);
    for(int i=0;i<b.size()-1;i++)
        cout<<b[i];
    cout<<endl;
    //ֱ���������Ԫ��
    cout<<"all elements:"<<endl<<b<<endl;
    return 0;
}
