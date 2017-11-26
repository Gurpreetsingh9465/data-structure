#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
    int info;
    node *pre, *next;
};
struct node *start = NULL;
void insertfirstnode(int info)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = info;
    p->next = NULL;
    p->pre = NULL;
    if(start == NULL)
    {
        start = p;
    }
    else
    {
       p->next = start;
       start = p;
    }
}
void deletefirstnode()
{
    struct node *t;
    if (start ==NULL)
        printf("list is empty");
    else
    {
        t = start;
        start = start->next;
        start->pre = NULL;
        free(t);

    }
}
void viewlist()
{
    struct node *t;
    if (start == NULL)
        printf("list is empty");
    else
    {
        t = start;
        while(t->next!=NULL)
        {
            printf("%d ",t->info);
            t = t->next;
        }
    }
}
void  menu()
{
    int x;
    printf("\n1: insert first node\n2: delete first node\n3: view list\n4: exit\n");
    cin>>x;
    switch(x)
    {
    case 1:
        printf("enter the value you want to insert = ");
        int n;
        cin>>n;
        insertfirstnode(n);
        break;
    case 2:
        deletefirstnode();
        break;
    case 3:
        viewlist();
        break;
    case 4:
        exit(1);
    default :
        printf("invalid input");
    }
}
main()
{
    while(1)
    {
        menu();
    }
}





