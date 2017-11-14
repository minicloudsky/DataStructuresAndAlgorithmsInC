#include<stdio.h>
#include<iostream>
#include<cstdlib>
#define eletype int
using namespace std;
void Merge(eletype a[],eletype temp[],int lpos,int rpos,int rightend)
{
    int i,leftend,numelements,temppos;
    leftend = rpos -1;
    temppos = lpos;
    numelements = rightend - lpos+1;
    while(lpos <= leftend&& rpos<=rightend)
    {
        if(a[lpos]<=a[rpos])
            temp[temppos++] = a[lpos++];
        else
            temp[temppos++] = a[rpos++];
    }
    while(lpos<=leftend)
        temp[temppos++] = a[lpos++];
    while(rpos<=rightend)
        temp[temppos++] = a[rpos++];
    for(i = 0;i<numelements;i++,rightend--)
        a[rightend] = temp[rightend];
}

void Msort(eletype a[],eletype temp[],int left,int right)
{
    int center;
    if(left<right)
    {
        center = (right+left)/2;
        Msort(a,temp,left,right);
        Msort(a,temp,center+1,right);
        Merge(a,temp,left,center+1,rihgt);
    }
}

void MergeSort(eletype a[],int n)
{
    eletype *temp;
    temp = (eletype*) malloc(n*sizeof(eletype));
    if(temp!=NULL)
    {
        Msort(a,temp,0,n-1);
        free(temp);
    }
    else
        printf("No space for temp array.\n");
}

int main()
{
    int n,x;
    cin>>n;
    int *arr = (int*)malloc(sizeof(n));
    for(int i=0;i<n;i++)
    {
        cin>>x;
        arr[i] = x;
        cout<<arr[i]<<endl;
    }
    return 0;
}
