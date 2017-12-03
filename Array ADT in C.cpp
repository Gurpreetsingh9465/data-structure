#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct ArrayADT
{
    int index;
    int capacity;
    int *ptr;
};
int getitem(struct ArrayADT *p,int index)
{
    int val;
    if(p->index<index||index<0)
        {
            printf("not possible\n");
            return -1;
        }
    else
    {
        val = *(p->ptr+index);
    }
    return val;
}
struct ArrayADT* create(int capacity)
{
    struct ArrayADT *p;
    p = (struct ArrayADT *)malloc(sizeof(struct ArrayADT));
    p->index = -1;
    p->ptr = (int *)malloc(sizeof(int)*capacity);
    p->capacity=capacity;
    return p;
}
void insertArray(struct ArrayADT *p,int index,int value)
{
    if(p->index == p->capacity-1)
    {
        printf("overflow\n");
    }
    else if(index>p->index+1||index<0)
    {
        printf("insertion not possible\n");
    }
    else if(index == p->index+1)
    {
        *(p->ptr +index) = value;
        p->index++;
    }
    else
    {
        int i=p->index;
        while(i<index)
        {
            p->ptr[i+1] = p->ptr[i];
            i--;
        }
        p->index++;
        p->ptr[index]=value;
    }
}
void editArray(struct ArrayADT *p,int index,int value)
{
    if(index<0||index>=p->index)
        printf("invalid index");
    else
    {
        p->ptr[index] = value;
    }
}
int removeArray(struct ArrayADT *p, int index)
{
    int val;
    if(p->index == -1)
        printf("deletion is not possible\n");
    else if(index == p->index)
        p->index--;
    else
    {
        val = *(p->ptr+index);
        int i = index;
        while(i<p->index)
        {
            *(p->ptr+i) = *(p->ptr+i+1);
            i++;
        }
        p->index--;

    }
    return val;
}
int sizeArray(struct ArrayADT *p)
{
    return p->index+1;
}
int searchArray(struct ArrayADT *p,int value)
{
    for(int i=0;i<p->index+1;i++)
    {
        if(p->ptr[i]==value)
            return 1;
    }
    return 0;
}
int sortArray(struct ArrayADT *p)
{
    for(int i=0;i<p->index;i++)
    {
        for(int j=0;j<p->index+1;j++)
        {
            if(p->ptr[i]>p->ptr[j])
            {
                int c;
                c=p->ptr[i];
                p->ptr[i] = p->ptr[j];
                p->ptr[j] = c;
            }
        }
    }
    return 1;
}
main()
{
    struct ArrayADT *p;
    p = create (10);
    while(1)
    {
        int x;
        printf("1: insert  \n2: remove \n3: get item\n4: edit\n5: size ");
        cin>>x;
        switch(x)
        {
        case 1:
            int index, value;
            printf("enter index and value\n");
            cin>>index>>value;
            insertArray(p,index,value);
            break;
        case 2:
            printf("enter index");
            cin>>index;
            printf("%D removed\n",removeArray(p,index));
            break;
        case 3:
            printf("enter index");
            cin>>index;
            printf("% is the value\n",getitem(p,index));
            break;
        case 4:
            printf("enter index and value\n");
            cin>>index>>value;
            editArray(p,index,value);
            break;
        case 5:
            printf("size is %d\n",sizeArray(p));
            break;
        default:
            exit(1);
        }
    }
}











