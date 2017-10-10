/*
DNA分子是以4种脱氧核苷酸为单位连接而成的长链，这4种脱氧核苷酸分别含有A,T,C,G四种碱基。
碱基互补配对原则：A和T是配对的，C和G是配对的。如果两条碱基链长度是相同的并且每个位置的碱基是配对的，
那么他们就可以配对合成为DNA的双螺旋结构。现在给出两条碱基链，允许在其中一条上做替换操作：
把序列上的某个位置的碱基更换为另外一种碱基。问最少需要多少次让两条碱基链配对成功
输入描述:
输入包括一行： 包括两个字符串,分别表示两条链,两个字符串长度相同且长度均小于等于50。
输出描述:
输出一个整数，即最少需要多少次让两条碱基链配对成功
示例1
输入
ACGT TGCA
输出
0
*/
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],str2[100];
    scanf("%s %s",str,str2);
    int flag[100];
    for(int i=0;i<strlen(str);i++)
    {
        if((str[i]=='A'&&str2[i]=='T')||(str[i]=='T'&&str2[i]=='A')||(str[i]=='C'&&str2[i]=='G')||(str[i]=='G'&&str2[i]=='C'))
        {
            flag[i] = 0;
        }
        else{
            flag[i]=1;
        }
    }
    int sum=0;
    for(int i=0;i<strlen(str);i++)
    {
        sum = sum+flag[i];
    }
    printf("%d\n",sum);
    return 0;
}
