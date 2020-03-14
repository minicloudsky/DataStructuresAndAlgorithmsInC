#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    s = "01234567";
    int i,sum=0;
    for(i = 0;i<s.length();i++)
    {
        if(s[i]=='0')
            sum+=0;
        else if(s[i]=='1')
            sum+=1;
        else if(s[i]=='2')
            sum+=2;
    }
    cout<<sum<<endl;
    return 0;
}
