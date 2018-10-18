#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    map<char,int> m;
    m['0'] = 0;
    m['1'] = 1;
    m['2'] = 2;
    for(int i=0;i<2;i++)
        m['0'+i] = i;
    string sa,sb;
    sa = "2624";
    int i;
    int sum = 0;
    for(i =0;i<sa.length();i++)
        sum+=m[sa[i]];
    cout<<"sum = "<<sum<<endl;
    return 0;
}
