#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
// c plus plus,convert number to string
string convertToString(double x)
{
    ostringstream o;
    if(o<<x)
        return o.str();
    return "convertion error";// if error
}
// c++ ��stringת��Ϊ��ֵ
double convertFromString(const string &s)
{
    istringstream i(s);
    double x;
    if(i>>x)
        return x;
    return 0.0;//if error
}

int main()
{
    //��ֵת��Ϊstring��c����
    char b[10];
    string a;
    sprintf(b,"%d",1975);
    a = b;
    cout<<a<<endl;
    //c++ ����
    string cc = convertToString(1979);
    cout<<cc<<endl;
    string dd = "1867";
    int p = convertFromString(dd)+2;
    cout<<p<<endl;

    return 0;
}
/*
sscanf �÷�

char buf[512] = ;
sscanf("123456 ", "%s", buf);
printf("%s\n", buf);
���Ϊ��123456
����2. ȡָ�����ȵ��ַ��������������У�ȡ��󳤶�Ϊ 4 �ֽڵ��ַ�����

sscanf("123456 ", "%4s", buf);
printf("%s\n", buf);
���Ϊ��1234
����3. ȡ��ָ���ַ�Ϊֹ���ַ��������������У�ȡ�����ո�Ϊֹ�ַ�����
sscanf("123456 abcdedf", "%[^ ]", buf);
printf("%s\n", buf);
���Ϊ��123456
����4. ȡ������ָ���ַ������ַ��������������У�ȡ������ 1 �� 9 ��Сд��ĸ���ַ�����

sscanf("123456abcdedfBCDEF", "%[1-9a-z]", buf);
printf("%s\n", buf);
���Ϊ��123456abcdedf
����5. ȡ��ָ���ַ���Ϊֹ���ַ��������������У�ȡ������д��ĸΪֹ���ַ�����

sscanf("123456abcdedfBCDEF", "%[^A-Z]", buf);
printf("%s\n", buf);
���Ϊ��123456abcdedf
����6������һ���ַ��� iios/12DDWDFF@122����ȡ / �� @ ֮����ַ������Ƚ� "iios/" ���˵���
�ٽ���'@'��һ�������͵� buf ��

sscanf("iios/12DDWDFF@122", "%*[^/]/%[^@]", buf);
printf("%s\n", buf);
���Ϊ��12DDWDFF
����7������һ���ַ��� "hello, world"�������� "world"����ע�⣺������ ֮����һ�ո�

sscanf(��hello, world��, "%*s%s", buf);
printf("%s\n", buf);
���Ϊ��world
����P.S. %*s ��ʾ��һ��ƥ�䵽�� %s �����˵����� hello �������ˣ�
�������û�пո�����Ϊ NULL
*/
