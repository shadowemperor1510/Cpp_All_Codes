#include<iostream>
using namespace std;
 class base1
 {
    public:
    int a;
    void display()
    {
        cout<<"Base1 class: a= "<<a<<endl;
    }
 };

class base2
 {
    public:
    int d;
    virtual void display()
    {
        cout<<"Base2 class: d= "<<d<<endl;
    }
 };

class base3
 {
    public:
    int e=0;
    virtual void display()=0;
 };

 class derived: public base1, public base2, public base3
 {
    public:
    int b=0;
    void display()
    {
        cout<<"Base class a= "<<a<<endl;
        cout<<"BAse class d= "<<d<<endl;
        cout<<"Derived class: b= "<<b<<endl;
        cout<<"Base 3 class e= "<<e<<endl;
    }
 };

int main()
{
    base1 *bcp;
    base2 *bcp2;
    base1 o1;
    derived o2;
    bcp=&o2;
    bcp2=&o2;
    bcp->a=48;
    bcp->display();
    bcp->a=98;
    bcp->display();
    bcp2->d=50;
    bcp2->display();
    bcp2->d=99;
    bcp2->display();
    derived *dcp;
    dcp=&o2;
    o2.a=100;
    o2.b=5;
    o2.display();
    dcp->a=10;
    dcp->b=20;
    dcp->display();
    base3 *bcp3;
    bcp3=&o2;
    bcp3->e=11;
    bcp3->display();
    return 0;
}