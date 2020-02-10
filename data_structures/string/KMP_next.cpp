#include<cstdio>
#include<string.h>
#define N 100
void getNext(char *p,int *next)
{
    int lenp = strlen(p);
    next[0] = -1;
    int j=0;
    int k = -1;
    while(j<lenp-1)
    {
        if(k==-1||p[j] == p[k])
        {
            if(p[++j] == p[++k])//当两个字符相等时候要跳过
                next[j] = next[k];
            else
                next[j] = k;
        }
        else
            k = next[k];
    }
}
int KMP(char *t,char *p)
{
    int lent = strlen(t);
    int lenp = strlen(p);
    int i=0;//主串的位置
    int j = 0;//模式串的位置
    int next[N];
    getNext(p,next);
    while(i<lent && j< lenp)
    {
        if(j == -1 || t[i] == p[j])//当j为-1时候，要移动的是i，当然j也要归0
        {
            i++;
            j++;
        }
        else
        {
            //i不需要回溯了
            //i = i-j+1;
            j = next[j];
        }
    }
    if(j == lenp)
        return i-j;
    else
        return -1;
}
int main()
{
    char p[N] = "abcd";
    char t[N] = "aaaabcd";
    int next[N];
    getNext(p,next);
    printf("%d\n",KMP(t,p));
    return 0;
}
