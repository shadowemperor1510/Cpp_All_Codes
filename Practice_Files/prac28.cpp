#include<iostream>
using namespace std;

template<class t>
class op
{
    public:
    t a;
    t b;
    void swapp(t* x, t* y)
{
    t temp= *x;
    *x = *y;
    *y = temp;
}
};

int main()
{
    op <int> o;
    int c=3, d=9;
    cout<<c<<endl<<d<<endl;
    o.swapp(&c, &d);
    cout<<c<<endl<<d<<endl;
    return 0;
}