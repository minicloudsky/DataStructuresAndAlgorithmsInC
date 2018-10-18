#include<stdlib.h>
#include<iostream>
#define eletype int
#define LeftChild(i) (2*(i)+1)
using namespace std;
void down(eletype a[],int i,int n)
{
    int child;
    eletype temp;
    for(temp = a[i]; LeftChild(i)<n;i = child)
    {
        child = LeftChild(i);
        if(child!=n-1 && a[child+1]>a[child])
            child++;
        if(temp<a[child])
            a[i] = a[child];
        else
            break;
    }
    a[i] = temp;
}
void HeapSort(eletype a[],int n)
{
    int i;
    for(i = n/2;i>=0;i--)
        down(a,i,n);
    for(i = n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        down(a,0,i);
    }
}
int main()
{
    int a[6] = {9,4,8,-1,2,7};
    HeapSort(a,6);
    for(int i=0;i<6;i++)
        cout<<a[i]<<endl;
    return 0;
}
