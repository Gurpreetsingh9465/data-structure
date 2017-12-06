#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
    int info;
    struct node *link;
};
void push(struct node **s,int info)
{
    struct node *p,*t;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = info;
    p->link = NULL;
    if(*s == NULL)
    {
        *s = p;
    }
    else
    {
        t = *s;
        while(t->link!=NULL)
            t = t->link;
        t->link = p;
    }
}
int pop(struct node **s)
{
    if(*s == NULL)
    {
        printf("underflow\n");
        return -1;
    }
    struct node *t,*del;
    t = *s;
    while(t->link->link!=NULL)
    {
        t=t->link;
    }
    del = t->link;
    t->link = NULL;
    int x = del->info;
    free(del);
    return x;
}
void viewList(struct node **s)
{
    if(*s==NULL)
        printf("\n impossible\n");
    struct node *t;
    t = *s;
    while(t!=NULL)
    {
        printf("%d ",t->info);
        t=t->link;
    }
}
main()
{
    struct node *start = NULL;
    push(&start,45);
    push(&start,98);
    push(&start,47);
    push(&start,35);
    push(&start,39);
    push(&start,30);
    push(&start,45);
    viewList(&start);
    int x = pop(&start);
    int y = pop(&start);
    cout<<"\nlast two value are "<<x<<"and "<<y<<endl;
    viewList(&start);

}

