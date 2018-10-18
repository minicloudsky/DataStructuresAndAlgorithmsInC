#ifndef MUL_H_INCLUDED
#define MUL_H_INCLUDED

#include"Cons_t.h"

void mull ( double M[V][V], double N[V][V],int A,int B,int W,int p,int q)
{
    double S1[1024],S2[1024];
    memset(S1,0,sizeof(S1));
    memset(S2,0,sizeof(S2));
    for(int i=0; i<A; i++)
    {
        S1[i]+= M[i][p]*N[p][p];
        S1[i]+=M[i][q]*N[q][p];

        S2[i]+=M[i][p]*N[p][q];
        S2[i]+=M[i][q]*N[q][q];

    }
    for(int i=0; i<T; i++)
    {
        M[i][p]=S1[i];
        M[i][q]=S2[i];
        if(i!=p&&i!=q)
            M[i][i]=M[i][i]*N[i][i];
    }
}

void mul ( double M[V][V], double N[V][V], double Z[V][V],int A,int B,int W)
{
    for(int i=0; i<A; i++)
    {
        for(int j=0; j<B; j++)
        {
            for(int k=0; k<W; k++)
            {
                Z[i][j] += M[i][k]*N[k][j];
            }
        }
    }
}

#endif // MUL_H_INCLUDED
