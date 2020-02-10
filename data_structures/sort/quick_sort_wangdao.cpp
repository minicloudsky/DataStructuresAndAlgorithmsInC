#include<stdio.h>
#define eletype int
int Partition(eletype a[],int low,int high)
{
    eletype pivot = a[low];
    while(low<high)
    {
        while(low<high&&a[high]>=pivot)
            --high;
        a[low] = a[high];

        for(int i=0; i<8; i++)
            printf("%d ",a[i]);
        printf("\n");

        while(low<high&&a[low]<=pivot)
            ++low;
        a[high] = a[low];

        for(int i=0; i<8; i++)
            printf("%d ",a[i]);
        printf("\n");

    }
    a[low] = pivot;

    for(int i=0; i<8; i++)
        printf("%d ",a[i]);
    printf("\n");

    return low;
}

void QuickSort(eletype a[],int low,int high)
{
    if(low<high)
    {
        int pivotpos = Partition(a,low,high);
        QuickSort(a,low,pivotpos-1);
        QuickSort(a,pivotpos+1,high);
    }
}

int main()
{
    int a[8]= {12,4,1,7,3,5,9,6};
    printf("Before sort:\n");
    for(int i=0;i<8;i++)
        printf("%d ",a[i]);
    printf("\n\nstart sort\n");

    QuickSort(a,0,7);
    for(int i=0; i<8; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
