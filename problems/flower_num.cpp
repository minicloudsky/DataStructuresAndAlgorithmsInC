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
        printf("������������ѧ�ţ��༶�����ģʽ��ҵ������,���軻��������'@':\n");
        scanf("%s",name);
        scanf("%s",id);
        scanf("%s",banji);
        scanf("%s",answer);

        printf("\n����: %s ѧ��: %s �༶: %s\n",name,id,banji);
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
