#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};
struct Stack* createstack(int n)
{
    struct Stack *p;
    p = (struct Stack*)malloc(sizeof(struct Stack)); // dynamic creation
    p->capacity = n;
    p->array = (int *)malloc(sizeof(int)*n);
    p->top = -1;
    return p;
}
int isfull(struct Stack *p)
{
    if(p->top == p->capacity-1)
        return 1;
    else
        return 0;
}
int isempty(struct Stack *p)
{
    if(p->top == -1)
        return 1;
    else
        return 0;
}
void push(struct Stack *p,int x)
{

    if(!isfull(p))
    {
        p->top++;
        p->array[p->top] = x; // p->array[top] = x;
    }
    else
        printf("overloading");

}
int pop(struct Stack *p)
{
    int item;

    if(!isempty(p))
    {
        item = p->array[p->top];
        p->top--;
        return item;
    }
    else
        printf("underload\n");

}
main()
{
    struct Stack *p;
    p = createstack(5);
    while(1)
    {
        printf("1: push \n2:pop\n");
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            int n;
            cout<<"enter value"<<endl;
            cin>>n;
            push(p,n);
            break;
        case 2:
            int value;
            value = pop(p);
            cout<<value<<endl;
            break;
        default:
            exit(1);
        }

    }
}






