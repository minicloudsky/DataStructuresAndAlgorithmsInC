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
    if(*a =='\0') //此时结束符未交换位置，说明字符串a先结束，只把字符串b剩余部分拷贝到字符串a位置就好
    {
        temp = *a;
        *a = *b;
        *b = temp;//交换结束符
        ++a;
        ++b;
        while(*b!='\0'){
            *a++ = *b++;
        }
        *a = *b;//拷贝结束符
    }
    else //此时结束符未交换位置，说明字符串b先结束，只把字符串a剩余部分拷贝到字符串b位置就好
    {
        temp = *b;
        *b = *a;
        *a = temp;//交换结束符
        //拷贝a剩余字符（结束符未拷贝）
        while(*a!='\0')
            *b++ = *a++;
        *b = *a;//交换结束符
    }
}
int main(){
    char a[][7]= {"faaaaa","bar"};
    printf("%s\t%s\n",a[0],a[1]);
    swap(a[0],a[1]);
    printf("%s\t%s\n",a[0],a[1]);
    return 0;
}
