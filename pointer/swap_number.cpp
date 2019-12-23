#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/*
C语言交换数据方法
*/
void Swap(int *a,int *b)
{
    int temp;
    temp  = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 5,b  =10;
    // Swap(&a,&b);
    printf("%d  %d\n",a,b);
    //用加减或乘除
    // a=a+b;   //a=a*b;
    // b=a-b;   //b=a/b;
    // a=a-b;   //a=a/b;

    //异或交换
    // a = a^b;
    // b = a^b;
    // a = a^b;
    //位运算
    b = (__int64)((__int64)a << 32 | (a = b)) >>32;
    /**
    __int64 表示 64 位整型变量，这个在 VC6.0 里是支持的。
    b = (__int64)((__int64)a << 32 | (a = b)) >> 32； 这个语句中 a=b 的值为 b 的值 20，
    同时把 b 的值赋给 a。整个语句的意思：先把 a 强制转化为 64 位整型变量，然后把它左移 32
    位后与（a=b）按位或，把整个结果再强制转换为 64 位整型变量，然后右移 32 位得到 b 的值。
    其实，求 b 的值没必要有 |（a=b）这部分，但因为想同时把 b 的值赋给 a，且把 |（a=b）
    放在这儿不会影响到 b 最终的值，所以写成这样。这儿就采用移位的方法避免了用中间变量
    */

    printf("交换前a,b的值分别为: \n");
    printf("%d\n",a);
    printf("%d\n",b);
    return 0;
}
