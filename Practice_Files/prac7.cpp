#include<iostream>
using namespace std;

inline int division(int, int);

int main()
{
    int a,b;
    cout<<"Enter 2 nos."<<endl;
    cin>>a>>b;
    cout<<"Quotient= "<<division(a,b)<<endl;
}

inline int division(int a, int b)
{
    return (a/b);
}