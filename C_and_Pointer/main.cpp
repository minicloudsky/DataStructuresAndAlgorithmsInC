#include <iostream>
/*
#include "globe.h"
#include "mysort.h"
*/
#include <pthread.h>
using namespace std;

#define N 10

int a[1024][1024];

void fun()
{
    for(int k=0;k<1024;k++){
        for(int i=0;i<1024;i++){
            for(int j=0;j<1024;j++){
                a[i][j]=a[i][k]*a[k][j];
            }
        }
    }
}

int main()
{
    pthread_t id[N];

    for(int i=0;i<N;i++){
        pthread_create(id+i,(pthread_attr_t *)NULL,fun,(void*)(*)(void*)NULL);
    }

    for(int i=0;i<N;i++){
        pthread_join(id[i],NULL);
    }

    return 0;
}
