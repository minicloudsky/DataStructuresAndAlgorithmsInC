#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
    char name[100];
    char id[100];
    char banji[100];
    char answer[1000];
    while(1)
    {
        printf("请输入姓名，学号，班级，设计模式作业输出结果,如需换行请输入'@':\n");
        scanf("%s",name);
        scanf("%s",id);
        scanf("%s",banji);
        scanf("%s",answer);

        printf("\n姓名: %s 学号: %s 班级: %s\n",name,id,banji);
        for(int i=0;i<strlen(answer);i++){
            if(answer[i]=='@')
                printf("\n");
            else
                printf("%c",answer[i]);
        }
        printf("\n");
    }
    return 0;
}
