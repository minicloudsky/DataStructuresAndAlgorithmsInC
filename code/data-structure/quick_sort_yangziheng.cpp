#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int div(int *a,int l,int r)
{
    int p=a[(l+r)/2];
    int i=l;
    int j=r;
    for(;;){
        while(i<=r&&a[i]<p)
            i++;
        while(j>=0&&a[j]>p)
            j--;
        if(i<j)  swap(a[i],a[j]);
        else   break;
    }

    return i;
}

void qsort(int *a,int l,int r)
{
    if(l<r){
        int p=div(a,l,r);
        qsort(a,l,p-1);
        qsort(a,p+1,r);
    }
}

int main()
{
    int a[100];
    int n;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    qsort(a,0,n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}
