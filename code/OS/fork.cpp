#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
    pid_t pid;
    pid = fork(); //����һ������
    if(pid < 0) //����
    {
        fprintf(stdrr,"fork failed");
        exit(-1);
    }
    else if(pid==0) //�ӽ���
    {
        execlp("bin/ls","ls",NULL);
    }
    else //������
    {
        wait(NULL); //�����̵ȴ��ӽ��̽���
        printf("child complete");
    }
    return 0;
}
