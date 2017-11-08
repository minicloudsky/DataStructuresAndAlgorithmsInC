#include<stdio.h>

void f(int (**p)[10])
{

}

int main()
{
    int a[12][12][10];
	f(a);
	return 0;
}
