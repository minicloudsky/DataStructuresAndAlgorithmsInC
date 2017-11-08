#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int a[100];
int n;

void print_res()
{
    for(int i=0;i<n;i++)
    {
        if(a[i])
        {
            printf("%d ",i+1);
        }
    }
    printf("\n");
}

void dfs(int cur)
{
    if(cur==n)
    {
        print_res();
        return ;
    }

    for(int i=0;i<2;i++){
        a[cur]=i;
        dfs(cur+1);
    }
}

int main()
{
    cin>>n;
    dfs(0);

    return 0;
}
