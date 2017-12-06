#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class Stack
{
private:
    int *p,capacity,left,right;
public:
      Stack(int capacity)
      {
          this->capacity = capacity;
          left = -1;
          right = capacity;
          p= new int[capacity];
      }
      void push_right(int info)
      {
          if(isFull())
            cout<<"overflow"<<endl;
        else
        {
            right--;
            p[right] = info;
        }
      }
    void push_left(int info)
      {
          if(isFull())
            cout<<"overflow"<<endl;
        else
        {
            left++;
            p[left] = info;
        }
      }
      int isEmptyleft()
      {
          if(left == -1)
            return 1;
          else
            return 0;
      }
      int isEmptyright()
      {
          if(right == capacity)
            return 1;
          else
            return 0;
      }
      int isFull()
      {
          if(left+1 == right)
            return 1;
          else
            return 0;
      }
      int peekRight()
      {
          if(!isEmptyright())
            return p[right];

          else
            return -1;
      }
      int peekLeft()
      {
          if(!isEmptyleft())
            return p[left];
          else
            return -1;
      }
      int popRight()
      {
         if(!isEmptyright())
         {
            int temp = p[right];
            right++;
         }
          else
            return -1;
      }
      int popLeft()
      {
          if(!isEmptyleft())
          {
              int temp = p[left];
              left--;
              return temp;
          }
        else
            return -1;
      }
      ~Stack()
      {
          delete []p;
      }


};
main()
{
    Stack o(10);
    o.push_right(45);
    o.push_left(20);
    o.push_left(209);
    o.push_right(90);
    cout<<o.peekRight()<<endl;
    cout<<o.peekLeft();
}















