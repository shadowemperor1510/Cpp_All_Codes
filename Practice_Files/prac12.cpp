#include<iostream>
using namespace std;

class cmplx
{
    int a,b;
    public:
    void set(int v1, int v2)
    {
        a=v1;
        b=v2;
    }
    void add(cmplx v1, cmplx v2)
    {
        a= v1.a + v2.a;
        b= v1.b + v2.b;
    }
    void print()
    {
        cout<<"complex no.= "<<a<<" + i"<<b<<endl;
    }
};

int main()
{
    cmplx o1,o2,o3;
    o1.set(1,2);
    o1.print();

    o2.set(3,4);
    o2.print();

    o3.add(o1,o2);
    o3.print();
    
    return 0;
}