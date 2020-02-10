#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define eletype int
#define cutoff 3
using namespace std;
eletype Median(eletype a[],int left,int right)
{
    int mid = (left+right)/2;
    if(a[left]>a[mid])
        swap(a[left],a[mid]);
    if(a[left]>a[right])
        swap(a[left],a[right]);
    if(a[mid]>a[right])
        swap(a[mid],a[right]);
    swap(a[mid],a[right-1]);
    return a[right-1];
}
void Qsort(eletype a[],int left,int right)
{
    eletype pivot;
    int i,j;
    if(left+cutoff<=right)
    {
        pivot = Median( a,left,right );
        i = left;
        j = right-1;
        for(;;)
        {
            while(a[++i]<pivot){}
            while(a[--j]<pivot){}
            if(i<j)
                swap(a[i],a[j]);
            else
                break;
        }
        swap(a[i],a[right-1]);
        Qsort(a,left,i-1);
        Qsort(a,i+1,right);
    }
    else
        InsertionSort(a+left,right-left+1);
}
int main()
{
    return 0;
}
