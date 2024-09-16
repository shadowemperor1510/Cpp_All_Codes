#include<iostream>
using namespace std;

int main()
{
    int a =97;
    int* c= &a;
    cout<<c<<endl;
    cout<<c<<endl;
    cout<<*c<<endl;
    int** b= &c;
    cout<<b<<endl;
    cout<<&c<<endl;
    cout<<*b<<endl;
    cout<<**b<<endl;
    return 0;
}