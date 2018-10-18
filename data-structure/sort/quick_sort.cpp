#include<iostream>
using namespace std;
void quicksort(int *a,int left,int right)
{
    int i,j,temp;
    if(left>right)
        return;
    i = left;
    j = right;
    temp = a[left];
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
}
int main()
{
    int a[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
