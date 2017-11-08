//在没有指针的语言里面，模拟链表，实现申请释放内存，用数组作为地址。
#include<cstdio>
#include<cstdlib>
#define SpaceSize 1000
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrNode Position;
void initializeCursorSpace( void );
List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P,const List L);
Position Find(int x,const List L);
void Delete(int x,int L);
Position FindPrevious(int x,List L);
void Insert(int x,List L,Position P);
void DeleteList(List L);
Position Header(const List L);
Position First(const List L);
Position Advance(const Position P);
int Retrieve(const Position P);
/* Place in the implementation file  */
struct Node
{
    int element;
    Position Next;
};
struct Node CursorSpace[SapceSize];
//模拟链表申请内存
static Position CursorAlloc(void)
{
    Position P;
    P = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next;
    return P;
}
//free memory you have allocated
static void CursorFree(Position P)
{
    CursorSpace[P].Next = Sursor[0].next;
}
/* Return true if L is Empty  */
int IsEmpty(List L)
{
    return CursorSpace[L].Next ==0;
}
/* Return true if P is the last position in list L */
int IsLast(Position P,List L)
{
    return CursorSpce[P].Next ==0;
}
/*  Return Position of X in L; 0 if not found */
Position Find(int x,List L)
{
    Position P:
    P = CursorSpace[L].Next;
    while(P && CursorSpace[P].Element!=X)
    {
        P = CursorSpace[P].Next;
    }
    return P;
}
/* Delete first occurence od X from a list */
void Delete(int X,List L)
{
    Position P,TmpCell;
    P = FindPrevious(X,L);
    if(!IsLast(P,L))//Assumption of header use
    {
        TmpCell = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
        CursorFree(TmpCell);
    }
}
/*
    Insert (after legal position P)
    Header implementation assumed
    Parameter L is unused in this implementation
*/
void Insert(int X,List L,Position P)
{
    Position TmpCell;
    if(tmpCell ==0)
    {
        FatalError("Out of space!\n");
    }
    CursorSpace[TmpCell].Element = X;
    CursorSapce[TmpCell].next = CursorSpace[P].Next;
    CursorSpace[P].Next = TmpCell;
}
int main()
{
    int i,j;
    for(int i=0;i<10;i++)
    {
        if(10>-10)
        {
           j++;
        }
    }
    return 0;
}
