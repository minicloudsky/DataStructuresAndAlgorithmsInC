#include<cstdio>
#include<string.h>
#include<string>
using namespace std;
int main()
{
    char aim[10] = "abcdefg";
    char tmp[10];
    printf("%s\n",strncpy(tmp,aim,4));
    return 0;
}
