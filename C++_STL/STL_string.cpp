#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    char ss[100];
    string s;
    // s = "Hello C++ STL";
    // cout<<s<<endl;
    //���ַ�ָ�븳ֵ��һ���ַ�������
    scanf("%s",ss);
    s = ss;
    //β������ַ�
    s = s+'a';
    s = s +'f';
    s = s+ 'q';
    //β��׷���ַ���
    s = s + " plusplus";
    cout<<s<<endl;
    //append
    s.append(" append");
    s.append(" end");
    cout<<s<<endl;
    // insert
    string::iterator it;
    it = s.begin();
    //��'p'���뵽��һ���ַ�ǰ��(�ַ�λ���Ǵ�0��ʼ����)
    s.insert(it+1,'x');
    cout<<s<<endl;
    //�����Ԫ��
    cout<<s[0]<<endl;
    //ɾ����3��Ԫ�أ�Ԫ��λ�ô�0��ʼ����
    s.erase(it,it+3);
    cout<<s<<endl;
    //ɾ��0-4��������Ԫ��
    s.erase(it,it+4);
    cout<<"after erase(it,it+4)"<<endl<<s<<endl;
    cout<<s.length()<<endl;
    cout<<s.empty()<<endl;
    s.clear();
    s.append("abcdefg");
    // �ӵ�������ʼ����������3���ַ��滻Ϊ"good"
    s.replace(3,3,"good");
    cout<<s<<endl;
    //���ҵ�һ���ַ�'g',�����±�ֵ
    cout<<s.find('g')<<endl;
    s.append("catcat");
    //���ҵ�һ���Ӵ�'cat',�����±�ֵ
    cout<<s.find("cat")<<endl;
    //���ҵ�һ���Ӵ�cats�����Ҳ�������4292967295
    cout<<s.find("cats")<<endl;
    s.clear();
    cout<<"s is :"<<s<<endl;
    s = "cat dog cat";
    // compare ��s�󷵻�1����ȷ���0С�ڷ���-1
    cout<<s.compare("cat")<<endl<<s.compare("cat dog cat")<<endl<<s.compare("dog")<<endl;
    s.clear();
    s = "123456789";
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}
