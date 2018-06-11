#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double func(double x)
{
    return pow((1.0-1.0/x),-x);
}
int main()
{
    for(double i = 1.0;i<10000000.0;i++){
        printf("%lf  %lf\n",i,func(i));
    }

    return 0;
}
