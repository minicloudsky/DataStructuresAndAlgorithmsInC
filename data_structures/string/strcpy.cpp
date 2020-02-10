#include<string.h>
#include<stdio.h>
void mystr(char *s,char *t)
{
    int len = strlen(s);
    for(int i=0;i<len;i++)
    {
        t[i] = s[i];
    }
    //t[len] = '\0';
}
int main()
{
    char s[10] = "¼ÖÑÇÎä";
    char t[10] = "";
    strcpy(t,s);
    printf("%s\n",t);
    return 0;
}
