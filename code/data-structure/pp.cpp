/*
2�����ж���int a[]={1,3,5,7,9},*p=a;���Ϊ7�ı��ʽ��( )

A. *(p+3)

B. *(p+4)

C.*p+3

D.*p+4
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
    int a[] = {1,3,5,7,9};
    int *p=a;

    printf("%d %d %d %d",*(p+3),*(p+4),*p+3,*p+4);
    return 0;
}
