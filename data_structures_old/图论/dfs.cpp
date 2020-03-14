// 输入n个整数，判断能否从中选择若干数，结果恰为k
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define max 100
int a[max+1];
int n,k;
int count =0;
bool dfs(int i,int sum)
{
    count++;
    if(i==n)
        return sum==k;
    if(dfs(i+1,sum))
        return true;
    if(dfs(i+1,sum+a[i]))
        return true;
    cout<<"count: "<<count<<endl;
    return false;
}
void solve()
{
    if(dfs(0,0))
        printf("YES\n");
    else
        printf("NO\n");
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    solve();
    return 0;
}
