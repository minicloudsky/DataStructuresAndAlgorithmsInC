#include<stdio.h>
void swap(char *a,char *b)
{
    char temp = -1;
    while(*a!='\0' && *b!='\0'){
        temp = *a;
        *a = *b;
        *b = temp;
        ++a;
        ++b;
    }
    if(*a =='\0') //��ʱ������δ����λ�ã�˵���ַ���a�Ƚ�����ֻ���ַ���bʣ�ಿ�ֿ������ַ���aλ�þͺ�
    {
        temp = *a;
        *a = *b;
        *b = temp;//����������
        ++a;
        ++b;
        while(*b!='\0'){
            *a++ = *b++;
        }
        *a = *b;//����������
    }
    else //��ʱ������δ����λ�ã�˵���ַ���b�Ƚ�����ֻ���ַ���aʣ�ಿ�ֿ������ַ���bλ�þͺ�
    {
        temp = *b;
        *b = *a;
        *a = temp;//����������
        //����aʣ���ַ���������δ������
        while(*a!='\0')
            *b++ = *a++;
        *b = *a;//����������
    }
}
int main(){
    char a[][7]= {"faaaaa","bar"};
    printf("%s\t%s\n",a[0],a[1]);
    swap(a[0],a[1]);
    printf("%s\t%s\n",a[0],a[1]);
    return 0;
}
