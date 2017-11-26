#include<stdio.h>
#include<conio.h>
unsigned long factorial(int n);
main()
{
    int n;
    unsigned long fac;

    printf("enter a number\n");
    scanf("%d",&n);
    fac = factorial(n);
    printf("%ld",fac);
    getch();
}
unsigned long factorial(int n)
{
    if (n>0)
        return n*factorial(n-1);
    else
        return 1;
}
