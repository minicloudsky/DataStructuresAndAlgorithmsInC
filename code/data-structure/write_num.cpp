/*
读入一个自然数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10100。

输出格式：在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
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
