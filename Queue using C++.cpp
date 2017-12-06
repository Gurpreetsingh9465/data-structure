#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class Queue
{
private:

    struct node
    {
        int info;
        node *link;
    };
        node *rear, *front;
public:
    Queue()
    {
        rear = NULL;
        front = NULL;
    }
    int isEmpty()
    {
        if(rear==NULL&&front==NULL)
            return 1;
        else
            return 0;
    }
    void insertQueue(int info)
    {
        node *p = new node;
        p->info = info;
        p->link = NULL;
        if(rear == NULL)
        {
            rear = p;
            front = p;
        }
        else
        {
            rear->link = p;
            rear++;
        }
    }
    int removeQueue()
    {
        if(front ==NULL)
            return -1;
        else if(front == rear)
        {
            int x = front->info;
            delete []front;
            front = rear = NULL;
            return x;
        }
        else
        {
            node *temp;
            temp = front;
            int x = front->info;
            front = front->link;
            delete []temp;
            return x;
        }
    }
    int getFirst()
    {
        if(front == NULL)
            return -1;
        else
            return front->info;
    }
    int count()
    {
        int c = 0;
        if(front == NULL)
            return c;
        node *t;
        t = front;
        while(t!=rear)
        {

            t=t->link;
            c++;
        }
        c++;
        return c;
    }
    void traverse()
    {
        node *t;
        t = front;
        while(t!=NULL)
        {
            cout<<t->info<<" ";
            t = t->link;
        }
    }
    ~Queue()
    {
        while(!isEmpty())
        {
            removeQueue();
        }
    }
};
main()
{
    Queue q;
    q.insertQueue(90);
    q.insertQueue(94);
    q.insertQueue(97);
    q.insertQueue(98);
    q.insertQueue(78);
    q.insertQueue(100);
    cout<<q.count();
    cout<<q.getFirst()<<endl;
    cout<<q.removeQueue()<<endl;
    cout<<q.getFirst()<<endl;

}
