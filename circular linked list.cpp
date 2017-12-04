#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int info;
    struct node *link;
} ;
void display(struct node *last)
{
    if(last == NULL)
        printf("list is empty");
    else
    {
        struct node *t;
        t = last->link;
        do
        {
            printf("%d ",t->info);
            t=t->link;
        }while(t!=last->link);
    }
}
struct node * AddAtBeg(struct node *last,int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node ));
    p->info = data;
    p->link = last->link;
    last->link = p;
    return last;
}
struct node * addtoempty(struct node *last, int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node ));
    p->info = data;
    last = p;
    last->link = last;
    return last;


}
struct node * addatend(struct node *last, int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node ));
    p->info = data;
    p->link = last->link;
    last->link = p;
    last = p;
    return last;
}
struct node * addafter(struct node *last,int data, int value)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node ));
    p->info = value;
    struct node *t;
        t = last->link;
        do{
            if(t->info == data)
            {
                p->link = t->link;
                t->link = p;
                if(t==last)
                    last=p;
                return last;
            }
        }while(t!=last->link);
}
struct node * del(struct node *last,int value)
{
    struct node *t,*p;
    if(last == NULL)
        printf("not possible");
    else if(last == last->link)
        if(last->info == value)
        {
            t = last;
            free(t);
            last = NULL;
        }
    else if(last->link->info == value)
    {
        t = last->link;
        last->link = t->link;
        free(t);
    }
    p=last->link;
    while(p->link != last)
    {
        if(p->link->info == value)
        {
            t = p->link;
            p->link = t->link;

            free(t);
            return last;
        }
        p=p->link;
    }
    if(last->info == value)
    {
        t = last;
        p->link = last->link;
        last = p;
        free(t);
        return(last);
    }
}
