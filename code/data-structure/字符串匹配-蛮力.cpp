#include<stdio.h>
#include<string.h>
int compare(char *T,char *P)
{
    int len1 = strlen(T),len2 = strlen(P);
    for(int i=0;i<len1;i++)
    {
        int tmp = i;//��¼��ǰ�Ŀ�ʼ�±�
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
        if(flag == len2)//�����flag���ַ���len2��ȣ�֤�������ַ���ƥ�䵽
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
    while(i<( nLenT - nLenP+1 ))//i���λ�ý���ȡ��nLenT - nLenP
    {
        if(T[i+j] == P[j]) //�����ַ�����ͷƥ���һֱƥ����ȥ
        {
            if(j == nLenP-1)//�������ַ���ƥ��ͷ���i��λ��
                return i;
            j++;           //δƥ����ɣ���ƥ����һλ
        }
        else    // �����ƥ����iλ��+1,j��ͷ��ʼ
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
