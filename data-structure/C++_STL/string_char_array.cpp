#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    char ss[100];
    scanf("%s",&ss);
    s = ss;
    printf(s.c_str());
    cout<<endl;
    printf("%s\n",ss);
    // string and sscanf
    string s1,s2,s3;
    cout<<"sscanf:"<<endl;
    char sa[100],sb[100],sc[100];
    sscanf("abc 123 pc","%s %s %s",sa,sb,sc);
    s1 =sa;
    s2 = sb;
    s3 = sc;
    cout<<s1<<endl<<s2<<endl<<s3<<endl;
    int a,b,c;
    sscanf("1 2 3","%d %d %d",&a,&b,&c);
    cout<<a<<b<<" "<<c<<" "<<endl;
    int x,y,z;
    sscanf("4,5#6","%d,%d#%d",&x,&y,&z);
    cout<<x<<" "<<y<<" "<<z<<endl;

    return 0;
}
