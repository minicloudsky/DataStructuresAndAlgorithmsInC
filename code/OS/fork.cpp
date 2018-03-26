#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
    pid_t pid;
    pid = fork(); //创建一个进程
    if(pid < 0) //出错
    {
        fprintf(stdrr,"fork failed");
        exit(-1);
    }
    else if(pid==0) //子进程
    {
        execlp("bin/ls","ls",NULL);
    }
    else //父进程
    {
        wait(NULL); //父进程等待子进程结束
        printf("child complete");
    }
    return 0;
}
