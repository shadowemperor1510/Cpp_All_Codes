#include<iostream>
using namespace std;

class cmplx
{
    int a,b;
    public:
    cmplx();
    cmplx(int, int);
    void print()
    {
        cout<<"Complex= "<<a<<" + "<<b<<"i"<<endl;
    }
};

cmplx :: cmplx()
{
    a=10;
    b=5;
}

cmplx :: cmplx(int c, int d)
{
    a=c;
    b=d;
}

int main()
{
    cmplx c1;
    int e,f;
    cout<<"Enter 2 nos."<<endl;
    cin>>e>>f;
    c1.print();

    cmplx c2(e,f);  //  implicit call 
    // or cmplx c2=cmplx(e,f);      explicit call 
    c2.print();
    return 0;
}