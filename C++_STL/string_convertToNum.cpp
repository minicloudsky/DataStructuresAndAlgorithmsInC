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
// c++ 将string转化为数值
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
    //数值转化为string，c方法
    char b[10];
    string a;
    sprintf(b,"%d",1975);
    a = b;
    cout<<a<<endl;
    //c++ 方法
    string cc = convertToString(1979);
    cout<<cc<<endl;
    string dd = "1867";
    int p = convertFromString(dd)+2;
    cout<<p<<endl;

    return 0;
}
/*
sscanf 用法

char buf[512] = ;
sscanf("123456 ", "%s", buf);
printf("%s\n", buf);
结果为：123456
　　2. 取指定长度的字符串。如在下例中，取最大长度为 4 字节的字符串。

sscanf("123456 ", "%4s", buf);
printf("%s\n", buf);
结果为：1234
　　3. 取到指定字符为止的字符串。如在下例中，取遇到空格为止字符串。
sscanf("123456 abcdedf", "%[^ ]", buf);
printf("%s\n", buf);
结果为：123456
　　4. 取仅包含指定字符集的字符串。如在下例中，取仅包含 1 到 9 和小写字母的字符串。

sscanf("123456abcdedfBCDEF", "%[1-9a-z]", buf);
printf("%s\n", buf);
结果为：123456abcdedf
　　5. 取到指定字符集为止的字符串。如在下例中，取遇到大写字母为止的字符串。

sscanf("123456abcdedfBCDEF", "%[^A-Z]", buf);
printf("%s\n", buf);
结果为：123456abcdedf
　　6、给定一个字符串 iios/12DDWDFF@122，获取 / 和 @ 之间的字符串，先将 "iios/" 过滤掉，
再将非'@'的一串内容送到 buf 中

sscanf("iios/12DDWDFF@122", "%*[^/]/%[^@]", buf);
printf("%s\n", buf);
结果为：12DDWDFF
　　7、给定一个字符串 "hello, world"，仅保留 "world"。（注意：“，” 之后有一空格）

sscanf(“hello, world”, "%*s%s", buf);
printf("%s\n", buf);
结果为：world
　　P.S. %*s 表示第一个匹配到的 %s 被过滤掉，即 hello 被过滤了，
　　如果没有空格则结果为 NULL
*/
