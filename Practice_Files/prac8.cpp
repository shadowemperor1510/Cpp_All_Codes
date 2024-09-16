#include<iostream>
using namespace std;

int factorial(int n);
int fib(int);

int main()
{
    int a;
    cout<<"Enter a no. \n";
    cin>>a;
    cout<<" Factorial= "<<factorial(a)<<endl;
    cout<<"Fib. term at pos. "<<a<<" is = "<<fib(a)<<endl;
    return 0;
}

int factorial(int n)
{
    if(n<2)
    return 1;
    return(n*factorial(n-1));
}

int fib(int n)
{
    if(n<2)
    return 1;
    return (fib(n-1) + fib(n-2));
}