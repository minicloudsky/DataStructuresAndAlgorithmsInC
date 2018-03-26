#include<stdio.h>
int main()
{
    int m,n;
    int a[10]= {0},count = 0;
    while(scanf("%d %d",&m,&n)!=EOF){
        for(int i = m; i<=n; i++){
            if((i/100)*(i/100)*(i/100)+(i%100/10)*(i%100/10)*(i%100/10)+(i%10)*(i%10)*(i%10)==i)
            {
                a[count++] = i;
            }
        }
        if(count!=0)
        {
            for(int i=0; i<10; i++){
                if(a[i]!=0)
                    printf("%d",a[i]);
                if(a[i+1!=0]){
                    printf(" ");
                }
                else{
                    break;
                }
            }
        }
        else
            printf("no\n");
    }
    return 0;
}
