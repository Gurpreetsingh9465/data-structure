#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
void TOH(int, char, char, char);
main()
{
    int n;
    char A = 'A', B = 'B', C = 'C';
    printf("no. of pegs\n");
    cin>>n;
    TOH(n, A, B, C);
    getch();
}
// point to remenber
// 1 interchange AUX and END
// 2 interchange BEG and AUX
void TOH(int n,char BEG, char AUX, char END) // beg starts aux mediator and ends
{
    static int x = 1;
    if(n>=1)
    {
        TOH(n-1, BEG, END, AUX); // transfering n-1 pegs from BRG to auxilary
        printf("%d %c to %c \n",x++ , BEG, END);
        TOH(n-1, AUX, BEG, END); // transfering AUX to END
    }
}
