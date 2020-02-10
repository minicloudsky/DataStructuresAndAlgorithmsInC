#ifndef MATTRAN_H_INCLUDED
#define MATTRAN_H_INCLUDED

#include"Cons_t.h"

void MatTran( double M[V][V], double N[V][V],int A,int B)
{
    int i,j;
    for( i=0; i<A; i++)
    {
        for(j=0; j<B; j++)
        {
            N[j][i]=M[i][j];
        }
    }
}

#endif // MATTRAN_H_INCLUDED
