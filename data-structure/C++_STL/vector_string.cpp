#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    //string对象作为vector元素
    vector<string> v;
    v.push_back("Jack");
    v.push_back("Tinyjia");
    v.push_back("jiajia");
    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v[0][0]<<endl;
    cout<<v[0][1]<<endl;
    cout<<v[0][2]<<endl;
    cout<<v[0][3]<<endl;
    cout<<"v[2].length: "<<v[2].length();
    return 0;
}
