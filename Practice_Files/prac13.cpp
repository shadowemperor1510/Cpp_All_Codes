#include<iostream>
using namespace std;

class cmplx
{
    int a,b;
    public:

    friend cmplx add(cmplx v1, cmplx v2);
    void set(int v1, int v2)
    {
        a=v1;
        b=v2;
    }
    void print()
    {
        cout<<"Complex = "<<a<<" + i"<<b<<endl;
    }
};

cmplx add(cmplx v1, cmplx v2)
{
    cmplx o3;
    o3.set((v1.a + v2.a), (v1.b + v2.b));
    return o3;
}

int main()
{
    cmplx o1,o2,sum;
    o1.set(1,2);
    o1.print();

    o2.set(3,4);
    o2.print();

    sum= add(o1,o2);
    sum.print();
    
    return 0;
}