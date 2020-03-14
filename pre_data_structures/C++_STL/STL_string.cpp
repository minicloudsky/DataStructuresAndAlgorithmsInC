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
    //把字符指针赋值给一个字符串对象
    scanf("%s",ss);
    s = ss;
    //尾部添加字符
    s = s+'a';
    s = s +'f';
    s = s+ 'q';
    //尾部追加字符串
    s = s + " plusplus";
    cout<<s<<endl;
    //append
    s.append(" append");
    s.append(" end");
    cout<<s<<endl;
    // insert
    string::iterator it;
    it = s.begin();
    //把'p'插入到第一个字符前，(字符位置是从0开始计数)
    s.insert(it+1,'x');
    cout<<s<<endl;
    //输出首元素
    cout<<s[0]<<endl;
    //删除第3个元素，元素位置从0开始计数
    s.erase(it,it+3);
    cout<<s<<endl;
    //删除0-4区间所有元素
    s.erase(it,it+4);
    cout<<"after erase(it,it+4)"<<endl<<s<<endl;
    cout<<s.length()<<endl;
    cout<<s.empty()<<endl;
    s.clear();
    s.append("abcdefg");
    // 从第三个开始，将连续的3个字符替换为"good"
    s.replace(3,3,"good");
    cout<<s<<endl;
    //查找第一个字符'g',返回下标值
    cout<<s.find('g')<<endl;
    s.append("catcat");
    //查找第一个子串'cat',返回下标值
    cout<<s.find("cat")<<endl;
    //查找第一个子串cats，查找不到返回4292967295
    cout<<s.find("cats")<<endl;
    s.clear();
    cout<<"s is :"<<s<<endl;
    s = "cat dog cat";
    // compare 比s大返回1，相等返回0小于返回-1
    cout<<s.compare("cat")<<endl<<s.compare("cat dog cat")<<endl<<s.compare("dog")<<endl;
    s.clear();
    s = "123456789";
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}
