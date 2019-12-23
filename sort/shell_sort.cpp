#include<iostream>
using namespace std;
void shellsort(int *a,int n)
{
    int h=1;
    while(h<n/2){
        h=h*2+1;
    }
    while(h>0){
        for(int i=h;i<n;i++){
            for(int j=i;j>=h&&a[j]<a[j-h];j-=h){
                swap(a[j],a[j-h]);
            }
        }
        h/=3;
    }
}
void shell_sort(int *a,int n)
{
    int i,j,temp,gap;
    //步长为n/2，折半
    for(gap = n/2;gap>0;gap/=2)
    {
        for(i = gap;i<n;i++)
        {
            //保存每个按照步长分组里的第一个数字
            temp = a[i];
            //遍历每个分组中数字
            for(j = i;j>=gap;j-=gap)
            {
                if(temp<a[j-gap])
                    a[j] = a[j-gap];
                else
                    break;
            }
            a[j] = temp;
        }
    }
}
int main()
{
    int a[6]= {35,46,90,-87,32432,111};
    shell_sort(a,6);
    for(int i=0;i<6;i++)
        cout<<a[i]<<endl;
    return 0;
}
