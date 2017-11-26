#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
int fibonacci(int);
main()
{
    int n;
    int fib;
    cout<<"enter a no."<<endl;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        fib = fibonacci(i);
        printf("%d\t",fib);
    }

}
int fibonacci(int n)
{
    if (n>2)
        return(fibonacci(n-1)+fibonacci(n-2));
    else if (n==1||n==2)
        return 1;
}
