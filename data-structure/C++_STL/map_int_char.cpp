#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<int,char> m;
    m[0] = '0';
    m[1] = '1';
    m[2] = '2';
    m[3] = '3';
    for(int i=0;i<4;i++)
        m[i ] = '0'+i;
    int n = 3;
    string s = "The number is: ";
    cout<<s+m[n]<<endl;
    cout<<m[1]<<endl;
    return 0;
}
