/*
����һ����Ȼ�� n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�

�����ʽ��ÿ������������� 1 ��������������������Ȼ�� n ��ֵ�����ﱣ֤ n С�� 10100��

�����ʽ����һ������� n �ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ��� 1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�

����������
1234567890987654321123456789
���������
yi san wu
*/
#include<stdio.h>
#include<string.h>
int main()
{
    char num[110];
    char ans[11][11] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu","shi"};
    int a[110];
    scanf("%s",num);
    int sum=0;
    int count=0,k=0;
    for(int i=0;i<strlen(num);i++)
    {
        sum = sum+num[i]-48;
    }
    int temp=0,t=0;
    while(sum!=0)
    {
        t = sum%10;
        a[temp] = t;
        sum=sum/10;
        temp++;
    }
    for(int i=temp-1;i>=0;i--)
    {
        if(i!=0)
        {
            printf("%s ",ans[a[i]]);
        }
    else
        printf("%s",ans[a[i]]);

    }
    printf("\n");
    return 0;
}
