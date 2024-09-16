#include<iostream>
using namespace std;

void g();
int factorial(int);

int main()
{
    int n;
    cout<<"Enter a no."<<endl;
    cin>>n;
    int f=factorial(n);
    cout<<"Factorial="<<f<<endl;
    g();
    return 0;
}

int factorial(int c)
{
    int i,f=1;
    for(i=1; i<=c;i++)
    {
        f=f*i;
    }
    return f;
}

void g()
{
    cout<<"Goodbye!!"<<endl;
}