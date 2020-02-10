#include<stdio.h>
#include<unistd.h>
#include<cstdlib>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
int main()
{
    pid_t pid = fork();
    if(pid==0)
        fputs("Hi i am child proc...",stdout);
    else{
        fputs("Child proc id is: %d\n",stdout);
        sleep(30);
    }
    if(pid==0)
        puts("End child process.");
    else
        puts("End parent process.");
    return 0;
}
