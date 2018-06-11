#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

/*
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start,int len){
    int i;
    for(i = 0;i<len;i++){
        printf("%.2x ",start[i]);
    }
    printf("\n");
}
void show_int(int x){
    show_bytes((byte_pointer)&x,sizeof(int));
}
void show_float(float x){
    show_bytes((byte_pointer)&x,sizeof(float));
}
void show_pointer(void *x){
    show_bytes((byte_pointer) &x,sizeof(void*));
}
void test_show_bytes(int val){
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}
int tadd_ok(int x,int y)
{
    int sum = x+y;
    printf("%d\n",sum);
    return (sum-=x==y)&&(sum-y==x);
}
int tsub_ok(int x,int y)
{
    return(tadd_ok(x,-y));
}
int main()
{
    printf("%d\n",tsub_ok(3,-8));
    const char *s = "abcdef";
    //show_bytes((byte_pointer)s,strlen(s));
   // int s = 14;
 //   int *p = &s;
    // show_int(15);
   // show_float(15.1);
   // show_pointer(p);
    //test_show_bytes(0x87654321);
   // printf("%d\n",~1111);
    //printf("%d\n",1000&1010);
   // printf("%d\n",1111|1010);
   // printf("%d\n",1001^1110);
    //printf("%d\n",0x66&0x39);
    return 0;
}
*/

int *get_arr()
{
    int a[10]={1,1,1,1,1};
    int *aa=a;
    return aa;
}

int *get_arr2()
{
    int a[2]={2,9};
    int *aa=a;
    return aa;
}


int main()
{
    int *a;
    a=get_arr();
    get_arr2();
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}
