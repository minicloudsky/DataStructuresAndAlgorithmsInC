#include<stdio.h>
#include<iostream>
using namespace std;
void quicksort(int *a,int left,int right)
{
    int i,j,t,temp;
    if(left>right)
        return ;
        temp = a[left];
        i = left;
        j = right;
        while(i!=j)
        {
            while(a[j]>=temp&&i<j)
                j--;
            while(a[i]<=temp&&i<j)
                i++;
            if(i<j)
                swap(a[i],a[j]);
        }
        a[left] = a[i];
        a[i] = temp;
        quicksort(a,left,i-1);
        quicksort(a,i+1,right);
        return;
}
int main()
{
    int a[100];
    int i,n;
    cin>>n;
    for(i = 1;i<=n;i++)
        cin>>a[i];
    quicksort(a,1,n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<endl;
    return 0;
}
