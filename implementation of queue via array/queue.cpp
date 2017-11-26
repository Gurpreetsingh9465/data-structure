#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Queue
{
    int front,rear;
    int capacity;
    int *array;
};
struct Queue * createqueue(int capacity)
{
    struct Queue *p;
    p = (struct Queue *)malloc(sizeof(struct Queue));
    p->capacity = capacity;
    p->array = (int *)malloc(sizeof(int)*capacity);
    p->front = -1;
    p->rear = -1;
};
int isempty(struct Queue *p)
{
    if(p->front == -1)
        return 1;
    else
        return 0;
}
int isfull(struct Queue *p)
{
    return (p->rear+1)%p->capacity == p->front;
}
int queuesize(struct Queue *p)
{
    return (p->capacity-p->front+p->rear+1)%p->capacity;
}
void insert(struct Queue *p, int data)
{
    if(isfull(p))
        printf("overflow");
    else
    {
        p->rear = (p->rear+1)%p->capacity;
        p->array[p->rear] = data;
        if(p->front == -1)
            p->front = p->rear;
    }
}
int deletefront(struct Queue *p)
{
    int data;
    if(isempty(p))
    {printf("empty queue"); return -1;}
    else
    {
        data = p->array[p->front];
        if(p->front == p->rear)
            p->front = p->rear = -1;
        else
            p->front = (p->front+1)%p->capacity;

    }
    return data;
}
void deleteQueue(struct Queue *p)
{
    if(p)
    {
        if(p->array)
        {
            free(p->array);
        }
        free(p);
    }

}















