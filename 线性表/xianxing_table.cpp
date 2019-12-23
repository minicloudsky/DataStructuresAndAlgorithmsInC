#include<stdlib.h>
#include<stdio.h>
#define MaxSize 50
typedef struct
{
    int data[MaxSize];
    int length;
}SqlList;
bool Insert(SqlList &L,int i,int e)
{
    if(i<1||i>L.length)
        return false;
    if(L.length>=MaxSize)
        return false;
    for(int j=L.length;j>=i;j--)
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.length++;
    return true;
}
bool Delete(SqlList &L, int i,int &e)
{
    if(i<1 || i>L.length)
        return false;
    e = L.data[i-1];
    for(int j=i;j<L.length;j++)
        L.data[j-1] = L.data[j];
    L.length--;
    return true;
}
int Find(SqlList L,int e)
{
    int i;
    for(i=0;i<L.length;i++)
        if(L.data[i]==e)
            return i+1;
    return 0;
}
int main()
{
    SqlList L ;
    L = (int*) malloc(sizeof(SqlList));
    return 0;
}
