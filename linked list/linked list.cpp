#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
// creation of node
struct node
{
    int info;
    struct node *link;
};
struct node *start = NULL;// initially not pointing to anyone
struct node* create() // creating node
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node)); // creating dynamic memory
    return n; // return & of new node
};
void insertnode(int info)
{
    struct node * temp, *t;
    temp = create();
    temp->info = info;
    temp->link = NULL;
    if (start == NULL)
            start = temp;
    else
    {
        t = start;
        while(t->link!=NULL)
            t = t->link;
        t->link = temp;
    }

}
void deletefirst()
{
    struct node *r;
    if(start == NULL)
        printf("list is empty\n");
    else
    {
        r = start;
        start = start->link;
        free(r);
    }
}
void traverse()
{
    struct node *t;
    t = start;
    if(start == NULL)
        printf("list is empty\n");
    else
    {
            while(t!=NULL)
            {
                printf("%d ",t->info);
                t = t->link;
            }
    }
}
main()
{
int ch;
while(1){
    printf("1:enter a value in list\n2:delete a value\n3:traverse");
    cin>>ch;
    switch(ch)
    {case 1:
        int n;
        cin>>n;
        insertnode(n);
        break;
    case 2:
        deletefirst();
        break;
    case 3:
        traverse();
        break;
    default :
        exit(0);
    }

}
}










