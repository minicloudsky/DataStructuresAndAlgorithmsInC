#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
char half_search(char a[],int x,int n)
{
    int left=0,right = n-1,mid = right/2;
    while(left<right)
    {
        if(x>a[mid])
            mid = (mid+right)/2;
        else if(x< a[mid])
            mid = (left+mid)/2;
        else
        {
            printf("answer :%c\n",a[mid]);
            return a[mid];

        }
    }
}
int Hash(const char *key,int tablesize)
{
    unsigned int hashval = 0;
    while(*key!='\0')
        hashval +=*key++;
    return hashval %tablesize;
}
int Hash2(const char *key,int tablesize)
{
    return (key[0]+27*key[1]+720*key[2])%tablesize;
}
int Hash3(const char *key,int tablesize)
{
    unsigned int hashval = 0;
    while(*key!='\0')
        hashval = (hashval<<5) + *key++;
    return hashval % tablesize;
}
int main()
{
    char s[7] = "abcdef";
    printf("%c\n",half_search(s,'e',7));
    /*
    printf("%d\n",'k'-'a');
    char *s = "dsvfdsgfdsdgvfdsgsfddsgfdsgfdsfdsf";
    int tablesize = 20;
    //printf("%d\n",Hash(s,tablesize));
    //printf("%d\n",Hash2(s,100));
    printf("%d\n",Hash3(s,1000));
    printf("%d\n%d\n",128<<1,128>>1);
    */
    return 0;
}
