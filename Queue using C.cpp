#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Queue
{
    int front,rear,capacity;
    int *arr;
};
struct Queue * createQueue(int capacity)
{
    Queue *p ;
    p = (struct Queue *)malloc(sizeof(struct Queue));
    p->front = -1;
    p->rear = -1;
    p->capacity =capacity;
    p->arr = (int *)malloc(sizeof(int)*capacity);
    return p;
}
int isEmpty(struct Queue *p)
{
    if(p->rear == -1 && p->front == -1)
        return 1;
    else
        return 0;
}
int isFull(struct Queue *p)
{
    if((p->capacity-p->rear+p->front)%p->capacity)
        return 1;
    else
        return 0;
}
void doubleQueue(struct Queue *p)
{
    p->capacity = p->capacity*2;
    p->arr = (int *)realloc(p->arr, sizeof(int )*p->capacity);
}
void halfQueue(struct Queue *p)
{
    p->capacity = p->capacity/2;
    p->arr = (int *)realloc(p->arr, sizeof(int )*p->capacity);
}
int QueueCapacity(struct Queue *p)
{
    return p->capacity;
}
void enQueue(struct Queue *p,int info)
{
    if(p->rear == p->capacity-1 && p->front == 0)
        doubleQueue(p);
    if(isEmpty(p))
    {
        p->arr[0]=info;
        p->front = 0;
        p->rear = 0;
    }
    else
    {
        if(p->front!=0)
            p->rear = ((p->capacity - p->rear+p->front-2)%p->capacity);
        else{
            p->rear++;
        }
        p->arr[p->rear] = info;
    }
}
void DelQueue(struct Queue *p)
{
    if(p->front ==-1 && p->rear == -1)
        printf("not posibble");
    else{
            if(p->front == 0&&p->rear == 0)
            {
                p->front--;
                p->rear--;
            }
            else if(p->front == 0)
            {
                p->front++;
            }
            else if(p->front == p->capacity-1)
            {
                p->front == 0;
            }
            else
            {
                p->front++;
            }

    }
}
void display(struct Queue *p)
{
    int i = p->rear>p->front?p->rear:p->front;
    int j = p->rear<p->front?p->rear:p->front;
    for(int s = j;s<=i;s++)
        printf("%d ",p->arr[s]);
}
main()
{
    Queue *q;
    q = createQueue(4);
    printf("capacity is %d\n",QueueCapacity(q));
    enQueue(q,47);
    enQueue(q,45);
    enQueue(q,5);
    enQueue(q,98);
    printf("capacity is %d\n",QueueCapacity(q));
    enQueue(q,92);
    DelQueue(q);
    display(q);
    printf("capacity is %d\n",QueueCapacity(q));


}






