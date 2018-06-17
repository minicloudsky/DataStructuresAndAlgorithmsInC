#include<stdio.h>
#include<cstring>
int main()
{
	char exp[100] = "";
	printf("Polish Notation(PN):\n");
	toPolishNotation(exp);
	printf("Reverse Polish Notation(RPN):");
	toReversePolishNotation(exp);
	return 0;
}
void toPolishNotation(char exp[])
{
	int len = strlen(exp);
	char c,tempChar;
	Stack s1;
	Stack s2;
	Stack expression ;
	double number;
	int lastIndex = -1;
	for(int i = len-1;i>=0;--i)
	{
		c = exp[i];
		if(c>='0'&&c<='9')
		{
			lastIndex = readDoubleReverse(exp,i);
			number = 
		}
	}
}