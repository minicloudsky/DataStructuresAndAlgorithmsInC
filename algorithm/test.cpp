#include<cstdio>
int max(int x,int y)
{
    return x>y ? x:y;
}
int main()
{
    int x,y;
    printf("please input x,y:");
    scanf("%d,%d",&x,&y);
    int s= max(x,y);
    printf("%d");
    return 0;
}
