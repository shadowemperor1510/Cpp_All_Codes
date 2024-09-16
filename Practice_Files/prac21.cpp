#include<iostream>
using namespace std;

class base1
{
    int a;
    public:
    base1(int i)
    {
        a=i;
        cout<<"Base1 constructor invoked \n";
    }
    void print1()
    {
        cout<<"a1= "<<a<<endl;
    }
};

class base2
{
    int a;
    public:
    base2(int i): a(i)
    {
        cout<<"BAse2 constructor invoked \n";
    }
    void print2()
    {
        cout<<"a2= "<<a<<endl;
    }
};

class derived: public base1, virtual public base2{
    int a3,a4;
    public:
    derived(int x, int y, int z, int w): base1(x), base2(y)
    {
        a3=z;
        a4=w;
        cout<<"Derived class constructor invoked \n";
    }
    void printd()
    {
        cout<<"a3= "<<a3<<endl;
        cout<<"a4= "<<a4<<endl;
    }
};

int main()
{
    int a,b,c,d;
    cout<<"Enter 4 values \n";
    cin>>a>>b>>c>>d;

    derived ob(a,b,c,d);
    ob.print1();
    ob.print2();
    ob.printd();

    return 0;
}