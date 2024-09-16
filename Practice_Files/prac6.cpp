#include<iostream>
using namespace std;

void swappointer(int* a, int* b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void swapreference(int &a, int &b)
{
    int t;
    t=a;
    a=b;
    b=t;
}

int main()
{
    int a,b;
    cout<<"Enter 2 nos. \n";
    cin>>a>>b;
    cout<<"Before swap, a="<<a<<" b="<<b<<endl;
    swappointer(&a,&b);
    cout<<"After swap, a="<<a<<" b="<<b<<endl;
    cout<<" Swap rfeerence"<<endl;
    swapreference(a,b);
    cout<<a<<"   "<<b<<endl;
    return 0;
}

