#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//insertion  delete viewlist getfirst getlast search
struct node
{
    int info;
    struct node *pre, *next;
};
void insertStart(struct node **s,int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->pre = NULL;
    p->info = data;
    p->next = *s;
    *s = p;

}
void insertLast(struct node **s,int data)
{
    struct node *p,*t;
    p =(struct node *)malloc(sizeof(struct node));
    if(*s == NULL)
    {
        p->pre = NULL;
        p->info = data;
        p->next = NULL;
        *s = p;
    }
    else
    {
        p->info = data;
        p->next = NULL;
        t = *s;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        p->pre = t;
        t->next = p;
    }
}
void insertAfter(struct node **s,struct node *ptr,int data)
{
    if(ptr == NULL)
        printf("not possible");
    else
    {
            struct node *p;
            p = (struct node *)malloc(sizeof(struct node));
            p->info = data;
            p->pre = ptr;
            p->next = ptr->next;
            if(ptr->next!=NULL)
                ptr->next->pre = p;
            ptr->next = p;
    }
}
struct node *Find(struct node **s, int value)
{
    struct node *t;
    if(*s == NULL)
    {  return NULL; }
    else
    {

        t = *s;
        while(t!=NULL)
            {
                if(t->info == value)
                    return t;
                t = t->next;
            }
        return NULL;
    }

}
int deleteFirst(struct node **s)
{
    if(*s == NULL)
        return 0;
    struct node *t;
    t = *s;
    *s = (*s)->next;
    (*s)->pre = NULL;
    free(t);
    return 1;

}
int deleteLast(struct node **s)
{
    if(*s == NULL)
        return 0;
    struct node *t;
    t = *s;
    while(t->next!=NULL)
        t=t->next;
    if((*s)->next == NULL)
         *s = NULL;
    else
    t->pre->next = NULL;
    free(t);
    return 1;
}
void deleteIntermediate(struct node **s,struct node *ptr)
{
    if(ptr == NULL||*s == NULL)
        printf("not possible");
    struct node *t;

    if (ptr == *s)
        {
            t = *s;
            *s = NULL;
            free(t);
        }
    else
    {
            if(ptr->next == NULL)
            {
                ptr->pre->next = NULL;
                free(ptr);
            }
            else
            {
                ptr->pre->next = ptr->next;
                ptr->next->pre = ptr->pre;
                free(ptr);
            }
    }
}
void viewList(struct node **s)
{
    struct node *t;
    t = *s;
    if(t == NULL)
        printf("list is empty");
    else{
    while(t=NULL)
    {
        printf("%d ",t->info);
        t = t->next;
    }
    }
}
int getFirst(struct node **s)
{
    if(*s == NULL)
        return -1;
    else
        return (*s)->info;
}
int getLast(struct node **s)
{
    struct node *t;
    t = *s;
    if(t == NULL)
        return -1;
    else
    {
        while(t->next!=NULL)
            t = t->next;
        return t->info;
    }
}




