#include<string.h>
#include<stdio.h>
int main()
{
    char c;
    char s[10000];
    int count =0;
    gets(s);
    scanf("%c",&c);
    for(int i=0;i<strlen(s);i++)
    {
        if((s[i] == c) || (s[i]+32 ==c) || (s[i]-32 ==c))
            count++;
    }
    printf("%d\n",count);
    return 0;
}
