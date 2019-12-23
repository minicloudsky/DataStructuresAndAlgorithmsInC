#include<stdio.h>
#include<iostream>
using namespace std;
int buddle_sort(int a[],int n)
{
    int i,j,t;
    for(int i=0;i<n-1;i++){
        for(int j = 1;j<n;j++)
        {
            if(a[j-1]>a[j])
            {
                t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
            }
        }
    }
}
int swap_sort(int a[],int n)
{
    int i,j,t;
    for(int)
}

int main()
{
    int n,a[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    buddle_sort(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
