#include<cstdlib>
#include<cstdio>
#define element int
typedef struct Node
{
    element data;
    Node *next;
};
typedef struct
{
    LinkQueueNode *front;
    LinkQueueNode *rear;

}LinkQueue,LinkQueueNode;
int InitQueue(LinkQueue *Q)
{
    Q->front = (LinkQueueNode *) malloc(sizeof(LinkQueueNode));
    if(Q->front !=NULL)
    {
        Q->rear = Q->front;
        Q->front->next = NULL;
        return 1;
    }
}
int EnterQueue(LinkQueue *Q,element)
{
    LinkQueueNode *NewNode;
    NewNode = (LinkQueueNode*) malloc(sizeof(LinkQueueNode));
    if(NewNode!=NULL)
    {
        NewNode->data = x;
        NewNode->next = NULL;
        Q->rear->next = NewNode;
        Q->rear = NewNode;
        return 1;
    }
}
int DeleteQueue(LinkQueue *Q,element *x)
{
    LinkQueueNode *p;
    if(Q->front == Q->rear)
    {
        return 1;
    }
    p = Q->front->next;
    Q->front->next = p->next;
    if(Q->rear == p)
        Q->rear = Q->front;
    *x = p->data;
    free(p);
    return 1;
}
int main()
{
    return 0;
}
