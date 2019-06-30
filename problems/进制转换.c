/*Description
输入一个十进制数N，将它转换成R进制数输出。

Input
输入数据包含多个测试实例，每个测试实例包含两个整数N(32位整数)和R（2<=R<=16, R<>10）。

Output
为每个测试实例输出转换后的数，每个输出占一行。如果R大于10，则对应的数字规则参考16进制（比如，10用A表示，等等）。

Sample Input
7 2
23 12
-4 3

Sample Output
111
1B
-11 */
#include<stdio.h>
int main()
{
	char s[18]="0123456789ABCDEF";
	char a[200];
	int i,count,n,r;
	while(~scanf("%d%d",&n,&r))
	{
		if(n<0)
		{
			n=-n;
			printf("-");
		}
		i=0;
		count=0;
		while(n!=0)
		{
			a[i]=s[n%r];
			n=n/r;
			i++;
			count++;
		}
		for(i=count-1;i>=0;i--)
		{
			printf("%c",a[i]);
		}
		printf("\n");
	}
	return 0;
}
