//Õ∞≈≈–Ú
#include<string.h>
#include<stdio.h>
#define max 100
int radix_sort(int arr[],int n)
{
    int radix[max];
    memset(radix,0,sizeof(radix));
    for(int i=0;i<n;i++)
    {
        radix[arr[i]]++;
    }
    for(int i=0;i<max;i++)
    {
        while(radix[i]>0)
        {
            printf("%d ",i);
            radix[i]--;
        }

    }
    printf("\n");
}
int main()
{
    int arr[6] = {3,5,47,87,90,44};
    radix_sort(arr,6);
    return 0;
}
