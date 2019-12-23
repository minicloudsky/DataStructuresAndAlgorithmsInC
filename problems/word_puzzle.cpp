/*
t h i s
w a t s
o a h g
f g d t
this two fat that
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char arr[4][4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++){
            scanf("%c",&arr[i][j]);
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(arr[i][j]=='t'&&arr[i][j+1]=='h'&&arr[i][j+2]=='i'&&arr[i][j+3]=='s')
            {
                printf("(%d %d) (%d %d) (%d %d) (%d %d)\n",i,j,i,j+1,i,j+2,i,j+3);
            }
            if(arr[i][j]=='t'&&arr[i+1][j]=='w'&&arr[i+2][j]=='o'){
                printf("(%d %d) (%d %d) (%d %d)\n",i,j,i+1,j,i+2,j);
            }
            if(arr[i][j]=='f'&&arr[i-1][j+1]=='a'&&arr[i-2][j+2]=='t')
            {
                printf("(%d %d) (%d %d) (%d %d)",i,j,i-1,j+1,i-2,j+2);
            }
        }
    }
    return 0;
}
