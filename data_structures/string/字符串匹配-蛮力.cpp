#include<stdio.h>
#include<string.h>
int compare(char *T,char *P)
{
    int len1 = strlen(T),len2 = strlen(P);
    for(int i=0;i<len1;i++)
    {
        int tmp = i;//记录当前的开始下标
        int k = i;
        int flag = 0;
        for(int j=0;j<len2;j++)
        {
            if(T[k] == P[j])
            {
                flag++;
                k++;
            }
            else
                break;
        }
        if(flag == len2)//如果有flag个字符与len2相等，证明所有字符都匹配到
            return tmp;
    }
    return -1;
}
int stringMatch(char* T,char *P)
{
    int nLenT = strlen(T),nLenP = strlen(P);
    int i=0, j =0;
    //yuiojijiayawu  13
    //      jiaya          5
    while(i<( nLenT - nLenP+1 ))//i最大位置仅能取到nLenT - nLenP
    {
        if(T[i+j] == P[j]) //当子字符串开头匹配就一直匹配下去
        {
            if(j == nLenP-1)//当整个字符都匹配就返回i的位置
                return i;
            j++;           //未匹配完成，则匹配下一位
        }
        else    // 如果不匹配则i位置+1,j从头开始
        {
            i++;
            j = 0;
        }
    }
    return -1;
}
int main()
{
    char *T = "bebestbody";
    char *P = "best";
    int answer = stringMatch(T,P);
    printf("%d\n",answer);
    return 0;
}
