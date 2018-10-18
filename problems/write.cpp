#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<unistd.h>
using namespace std;
int myval;
int main(int argc,char *argv[])
{
    myval = atoi(argv[1]);
    while(1){
        printf("myval is %d,loc0x%lx\n",myval,(long)&myval);
    }
   return 0;
}
