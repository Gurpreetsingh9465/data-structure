#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
int GCD (int , int);
main()
{
    int a,b,gcd;
    cout<<"enter two numbers"<<endl;
    cin>>a>>b;
    gcd = GCD(a,b);
    printf("GCD is = %d",gcd);

}
// calculation of GCD by euclid theorem and recurssion
int GCD(int a, int b)
{
    if( a == b )
        return a; // we can return any one a or b
    else if (a%b == 0)
        return b;  // returning the smaller one
    else if(b%a == 0)
        return a;  // returning smaller one
    else if (a > b)
        return GCD(a%b,b); // euclid theorem
    else if ( b > a)
        return GCD(a, b%a); // euclid theorem
}

/* eg
GCD(105 , 91)
GCD(105%91, 91)
GCD(14, 91)
GCD(14, 91%14)
GCD(14 , 7)
GCD(14%7 , 7)   in this case a%b == 0 so return 7 which will be the GCD
*/

