#include<iostream>
using namespace std;

class copy
{
    int a;
    public:
    copy()
    {
        a=0;
    }
    copy(copy &o)
    {
        cout<<" Copy constructor invoked!"<<endl;
        a=o.a;
    }
    void display()
    {
        cout<<a<<endl;
    }
};

int main()
{
    copy c1,c2,c3,c4;
    //copy c5(c1);
    c4=c2;
    //copy c6= c3;

    c1.display();
    c2.display();
    c3.display();
    c4.display();
    //c5.display();
    //c6.display();

    return 0;
}