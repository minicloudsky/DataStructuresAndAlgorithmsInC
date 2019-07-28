#include<iostream>
#include<cstdlib>
#define eletype int
using namespace std;
void Merge(eletype *a,eletype *temp,int start,int mid,int end){
    int i = start,j  = mid+1,k = start;
    while(i<=mid&&j<=end){
        if(a[i]>a[j])
            temp[k++] = a[j++];
        else
            temp[k++] = a[i++];
    }
    while(i<=mid)
        temp[k++] = a[i++];
    while(j<=end)
        temp[k++] = a[j++];
    for(i = start;i<=end;i++)
        a[i] = temp[i];

}
void MergeSort(eletype *a,int start,int end){
    int mid;
    eletype *temp = (eletype*) malloc((end-start)*sizeof(eletype));
    if(start<end){
        mid = (start+end)/2;
        MergeSort(a,start,mid);
        MergeSort(a,mid+1,end);
        Merge(a,temp,start,mid,end);
    }
}

int main()
{
    int n;
    eletype *p;
    cout<<"input n:"<<endl;
    cin>>n;
    p = (eletype*) malloc(n*sizeof(eletype));
    for(int i=0;i<n;i++)
        cin>>p[i];
    MergeSort(p,0,n);
    for(int i=0;i<n;i++)
        cout<<p[i]<<" ";
    cout<<endl;
    return 0;
}
