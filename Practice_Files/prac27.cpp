#include<iostream>
using namespace std;

template <class u= int, class v= double, class w=char>
class name
{
    u a;
    v b;
    w c;
    public:
    name(u x, v y, w z)
    {
        a=x;
        b=y;
        c=z;
    }
    void display()
    {
        cout<<"a= "<<a<<endl;
        cout<<"b= "<<b<<endl;
        cout<<"c= "<<c<<endl;
    }
};

int main()
{
    name <> h(10, 15.7, 'd');
    name<float, string, double> g(7.8, "BAzinga", 5);
    h.display();
    g.display();
    
    return 0;
}