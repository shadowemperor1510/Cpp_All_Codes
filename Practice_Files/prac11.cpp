#include<iostream>
using namespace std;

class bridge
{
    public:
    int a,b;
    void set();
    void display();
};

void bridge :: set()
{
    cout<<"Enter 2 values."<<endl;
    cin>>a>>b;
}

void bridge :: display()
{
    cout<<a<<"\t"<<b<<endl;
}

int main()
{
    bridge br;
    br.set();
    br.display();
    return 0;
}