
/*
#include "globe.h"
#include "mysort.h"
*/
#include <pthread.h>


#define N 10

int a[1024][1024];

void fun()
{
    int k,i,j;
    for(k=0;k<1024;k++){
        for(i=0;i<1024;i++){
            for(j=0;j<1024;j++){
                a[i][j]=a[i][k]*a[k][j];
            }
        }
    }
}

int main()
{
    pthread_t id[N];
    int i;


    for(i=0;i<N;i++){
        pthread_create(id+i,NULL,fun,NULL);
    }

    for(i=0;i<N;i++){
        pthread_join(id[i],NULL);
    }
    /*
    for(i=0;i<10;i++){
        fun();
    }*/

    return 0;
}
